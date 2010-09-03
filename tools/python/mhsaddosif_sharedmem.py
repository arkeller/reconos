#!/usr/bin/python
#
# mhsaddosif.py: add reconos osifs to a mhs file
#

import sys
import reconos.mhs_sharedmem

# support designs with PLB46 or PLB34/OPB
supported_plb_versions = ('46', '34')
osif_pcore_names = {'46' : 'xps_osif', '34' : 'plb_osif_mmu'}
intc_pcore_names = {'46' : 'xps_intc', '34' : 'opb_intc'}

def exitUsage():
    sys.stderr.write("Usage: %s <mhs_file> num_slots [ -f ]\n" % sys.argv[0])
    sys.exit(1)
    
    
if __name__ == "__main__":
    
    if len(sys.argv) < 3: exitUsage()
        
    mhs_orig = sys.argv[1]
    num_slots = int(sys.argv[2])
    
    # parse mhs file
    a = reconos.mhs_sharedmem.MHS(mhs_orig)
    
    # get PLB bus name and derive clock and reset names
    # try all supported versions
    # if more than one bus found, use the one named 'plb' FIXME: good idea?
    plb = None
    for plb_ver in supported_plb_versions:
        plb_buses = a.getPcores("plb_v" + plb_ver)
        if len(plb_buses) == 0:
            sys.stderr.write("NOTE: no PLB (v" + plb_ver + ") buses present in design.\n")
        elif len(plb_buses) > 1:
            # use the PLB named 'plb'
            sys.stderr.write("NOTE: more than one PLB (v" + plb_ver + ") bus present in design.\n")
            for b in plb_buses:
                sys.stderr.write("   " + b.instance_name + "\n")
                if b.instance_name == "plb":
                    plb = b
        else:    # exactly 1 plb
            # use the first PLB that's found.
            plb = plb_buses[0]
        if plb:         # found a suitable plb!
            osif_pcore_name = osif_pcore_names[plb_ver]
            intc_pcore_name = intc_pcore_names[plb_ver]
            break

    if not plb:         # no PLBs found of either variant
        sys.stderr.write("ERROR: no suitable PLB buses present in design.\n")
        sys.exit(1)

    # get interrupts
    # TODO: this should look for the interrupt controller connected to the
    # first PPC, instead of a hardcoded instance name!
    intc = a.getPcore( intc_pcore_name + "_0")
    interrupts = intc.getValue("Intr")

    # get the number of reconos slots already present in the design
    current_slots = len(a.getPcores(osif_pcore_name))
    
    # output a warning in case we found reconos slots
    if current_slots > 0:
        sys.stderr.write("Warning: file '%s' already contains %i OSIF(s):\n" % (mhs_orig, current_slots))
        for pcore in a.getPcores("osif_pcore_name"):
            sys.stderr.write(pcore.instance_name + " (version %s)" % pcore.getValue("HW_VER") + "\n")
        if not "-f" in sys.argv[2:]:
            sys.stderr.write("\nuse option -f to ignore\n")
            sys.exit(1)

    # get instance name as well as clock and reset names
    plb_name = plb.instance_name
    sys.stderr.write("using " + plb_name + "\n")
    clock = plb.getValue("PLB_Clk")
    reset = plb.getValue("SYS_Rst")
    
    # get DCR bus name
    dcr_buses = a.getPcores("dcr_v29")
    if len(dcr_buses) == 0:
        sys.stderr.write("ERROR: no DCR (v29) buses present in design.\n")
        sys.exit(1)
    if len(dcr_buses) > 1:
        sys.stderr.write("ERROR: more than one DCR bus present in design.\n")
        sys.stderr.write("       I'm too dumb to handle that.\n")
        sys.exit(1)
    # use the first DCR that's found.
    dcr_name = dcr_buses[0].instance_name

    # add slots one by one
    for s in range(current_slots, current_slots + num_slots):
        pcore = reconos.mhs_sharedmem.createReconosSlot(s, plb_name, dcr_name, clock, reset, osif_pcore_name, plb_ver = plb_ver)
        interrupts += " & " + pcore.getValue("interrupt")
        a.pcores.append(pcore)
    
    # connect interrupts
    intc.setValue("Intr",interrupts)
    intc.setValue("C_NUM_INTR_INPUTS",len(interrupts.split("&")))
    
    # output resulting mhs file to stdout
    print a



