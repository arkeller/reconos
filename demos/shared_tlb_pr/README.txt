sort_demo: Demonstrator for ReconOS
===================================

Files and Directories
---------------------

    src/        all necessary source files (hw and sw)
    runme.sh    script to build project


To build hardware:

    ./runme.sh
    cd shared_tlb_pr_generated
    . settings.sh
    cd hw
    make bits all

Bitstream will be in
    shared_tlb_pr_generated/hw/merges/prm0_hwt/base_routed_full.bit
    shared_tlb_pr_generated/hw/merges/prm0_hwt/prm0_hwt_routed_partial.bit
    (or similar files in the other directories in the merges directory)    


To build software (after building hardware): 
    cd shared_tlb_pr_generated
    . settings.sh
    cd sw
    ./runme.sh

Executables will be in the same directory (*.elf).

    
