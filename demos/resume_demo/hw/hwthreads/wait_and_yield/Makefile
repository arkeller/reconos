# Set the following values as appropriate for your hardware thread

# VHDL source files ( in the correct evaluation order! )
VHDL_FILES=wait_and_yield.vhd
# Name of the thread's top entity
USER_LOGIC_ENTITY=wait_and_yield
# Target architecture
ARCHITECTURE=virtex2p


######### NO CHANGES NECESSARY BEYOND THIS LINE ###########

MKHWTHREAD=$(RECONOS)/tools/python/mkhwthread.py
MKPRMHS=$(RECONOS)/tools/python/mkprmhs.py
PLATGEN=platgen
THREAD_PCORE_PREFIX=hw_task_v1_0
THREAD_PCORE_SUFFIX=_b
THREAD_PCORE=$(THREAD_PCORE_PREFIX)1$(THREAD_PCORE_SUFFIX)
SUPPORT_PCORES=reconos_$(RECONOS_VER) burst_ram_$(RECONOS_VER)

QUIET_MKHWTHREAD=  echo "    MKHWTHREAD  $@"; $(MKHWTHREAD)
QUIET_MKPRMHS=     echo "    MKPRMHS     $@"; $(MKPRMHS)
QUIET_PLATGEN=     echo "    PLATGEN     $@"; $(PLATGEN)

ifeq ($(NUM_OSIFS),)
    $(error Number of OSIFs unknown. Specify NUM_OSIFS)
endif

all: hwthread

clean:
	$(Q)rm -f platgen.log platgen.opt system.mhs
	$(Q)rm -rf hdl implementation synthesis pcores
	$(Q)rm -rf hw_task_v1_*_b
	$(Q)rm -f hw_task_*.ngc

$(THREAD_PCORE_PREFIX)%$(THREAD_PCORE_SUFFIX): 
	$(Q)$($(QQ)MKHWTHREAD) $(USER_LOGIC_ENTITY) $(subst $(THREAD_PCORE_SUFFIX),,$(subst $(THREAD_PCORE_PREFIX),,$@)) $(VHDL_FILES) >> make.log

hwthread: clean $(THREAD_PCORE)
	$(Q)mkdir pcores
	$(Q)cd pcores && ln -s ../$(THREAD_PCORE) .
	$(Q)cd pcores && for z in $(SUPPORT_PCORES); do \
	    ln -s $(RECONOS)/core/pcores/$$z . ;\
	done
	$(Q)$($(QQ)MKPRMHS) 1 $(NUM_OSIFS) > system.mhs
	$(Q)$($(QQ)PLATGEN) -lp $$(pwd) -p $(ARCHITECTURE) system.mhs >> make.log
	
