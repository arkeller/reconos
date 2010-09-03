#!/usr/bin/env bash

TDIR=shared_tlb_pr_generated

SW_FILES=src/sw/*
HW_FILES=src/hw/*
PRJ_FILE=src/*.rprj
LYT_FILE=src/*.lyt
MAKEFILE_FILES=src/Makefile*

reconos_mkprj.py $TDIR

cp $PRJ_FILE $TDIR
cp $LYT_FILE $TDIR/hw
cp $MAKEFILE_FILES $TDIR/hw
cp $SW_FILES $TDIR/sw
#cp $HW_FILES $TDIR/hw
cd $TDIR/hw/hwthreads
reconos_addhwthread.py hwt hwt ../../../src/hwt.vhd
reconos_addhwthread.py memcpy memcpy ../../../src/memcpy.vhd 

