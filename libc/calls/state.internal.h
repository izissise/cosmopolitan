#ifndef COSMOPOLITAN_LIBC_CALLS_STATE_INTERNAL_H_
#define COSMOPOLITAN_LIBC_CALLS_STATE_INTERNAL_H_
#include "libc/intrin/nopl.internal.h"
#include "libc/thread/thread.h"
#include "libc/thread/tls.h"
#if !(__ASSEMBLER__ + __LINKER__ + 0)
COSMOPOLITAN_C_START_

hidden extern int __vforked;
hidden extern bool __time_critical;
hidden extern unsigned __sighandrvas[NSIG];
hidden extern unsigned __sighandflags[NSIG];
hidden extern pthread_mutex_t __fds_lock_obj;
hidden extern const struct NtSecurityAttributes kNtIsInheritable;

void __fds_lock(void);
void __fds_unlock(void);
void __sig_lock(void);
void __sig_unlock(void);

#ifdef _NOPL0
#define __fds_lock()   _NOPL0("__threadcalls", __fds_lock)
#define __fds_unlock() _NOPL0("__threadcalls", __fds_unlock)
#else
#define __fds_lock()   (__threaded ? __fds_lock() : 0)
#define __fds_unlock() (__threaded ? __fds_unlock() : 0)
#endif

#ifdef _NOPL0
#define __sig_lock()   _NOPL0("__threadcalls", __sig_lock)
#define __sig_unlock() _NOPL0("__threadcalls", __sig_unlock)
#else
#define __sig_lock()   (__threaded ? __sig_lock() : 0)
#define __sig_unlock() (__threaded ? __sig_unlock() : 0)
#endif

COSMOPOLITAN_C_END_
#endif /* !(__ASSEMBLER__ + __LINKER__ + 0) */
#endif /* COSMOPOLITAN_LIBC_CALLS_STATE_INTERNAL_H_ */
