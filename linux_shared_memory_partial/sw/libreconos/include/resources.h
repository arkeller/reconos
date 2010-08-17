/// 
/// \file resources.h
/// Defines data types, constants and functions for ReconOS resources,
/// also calles OS objects, e.g. semaphores, mutexes etc.
/// 
/// \author     Enno Luebbers <enno.luebbers@upb.de>
/// \created    2007
// -------------------------------------------------------------------------
// Major Changes:
// 
// 22.06.2007   Enno Luebbers   File created
// 20.12.2007   Enno Luebbers   Modified to distinguish eCos/POSIX
//                              resources
//
#ifndef __RESOURCES_H__
#define __RESOURCES_H__

#ifdef __cplusplus
extern "C" {
#endif

// TYPE DEFINITIONS ========================================================

/// stores pointers to ReconOS resources
///
/// For semaphores, mutexes and condition variables, store a pointer
/// to the corresponding object. For mailboxes, store a pointer to
/// the mailbox handle.
typedef struct {
        void * ptr;                     ///< pointer to resource (can be an object or a handle)
        unsigned int type;        ///< integer identifying the resource type
} reconos_res_t;

// CONSTANTS ===============================================================

// Resource Identifiers ----------------------------------------------------
// Can (later) also be used as bit masks (e.g. for capabilities)

// eCos resource identifiers
#define CYG_SEM_T              0x00000001
#define CYG_MUTEX_T            0x00000002
#define CYG_COND_T             0x00000004
#define CYG_MBOX_HANDLE_T      0x00000008

// POSIX resource identifiers
#define PTHREAD_SEM_T             0x00001000
#define PTHREAD_MUTEX_T           0x00002000
#define PTHREAD_COND_T            0x00004000
#define PTHREAD_MQD_T              0x00008000

// ReconOS-only resource identifiers
// used for hardware-handled resources (e.g. hw mailboxes)
#define RECONOS_HWMBOX_READ_T   0x01000000
#define RECONOS_HWMBOX_WRITE_T  0x02000000
#define RECONOS_DUMMY_T         0xFF000000



#ifdef __cplusplus
} // extern "C"
#endif

#endif //__RESOURCES_H__
