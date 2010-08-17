///
/// \file osif.h
/// OSIF device driver for supporting ReconOS on Linux 2.6.
/// 
/// This driver provides character devices (e.g. /dev/osifnnn) for
/// accessing ReconOS OSIF registers from user space, in particular
/// from a delegate thread.
/// 
/// \author     Enno Luebbers <enno.luebbers@upb.de>
/// \date       15.01.2008
//
// This file is part of the ReconOS project <http://www.reconos.de>.
// University of Paderborn, Computer Engineering Group 
//
// (C) Copyright University of Paderborn 2007. Permission to copy,
// use, modify, sell and distribute this software is granted provided
// this copyright notice appears in all copies. This software is
// provided "as is" without express or implied warranty, and with no
// claim as to its suitability for any purpose.
//
// -------------------------------------------------------------------------
// Major Changes:
// 
// 15.01.2008   Enno Luebbers   File created
// 
#ifndef __OSIF_MODULE_H__
#define __OSIF_MODULE_H__

//#define OSIF_DEBUG 1


// CONSTANTS ==============================================

#define OSIF_NUMSLOTS 8    // maximum number of slots
                            // corresponds to the number of minors requested

#define OSIF_MAJOR  0       // dynamic major by default
// we start at minor 0 

#define OSIF_DCR_WRITESIZE 3     // number of OSIF DCR registers (writable)
#define OSIF_DCR_READSIZE  3     // numberof OSIF DCR registers (readable)

#define OSIF_CMD_MMU_SETPGD    0x0A000000


// MACROS =================================================

#undef PDEBUG             /* undef it, just in case */
#ifdef OSIF_DEBUG
#  ifdef __KERNEL__
     // This one if debugging is on, and kernel space
#    define PDEBUG(fmt, args...) printk( KERN_WARNING "osif: " fmt, ## args)
#  else
     // This one for user space 
#    define PDEBUG(fmt, args...) fprintf(stderr, fmt, ## args)
#  endif
#else
#  define PDEBUG(fmt, args...) 0      // not debugging: nothing
#endif

#endif  // __OSIF_MODULE_H__

