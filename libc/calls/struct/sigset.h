#ifndef COSMOPOLITAN_LIBC_CALLS_STRUCT_SIGSET_H_
#define COSMOPOLITAN_LIBC_CALLS_STRUCT_SIGSET_H_
#if !(__ASSEMBLER__ + __LINKER__ + 0)
COSMOPOLITAN_C_START_

typedef struct sigset {
  uint64_t __bits[2];
} sigset_t;

int sigaddset(sigset_t *, int) paramsnonnull();
int sigdelset(sigset_t *, int) paramsnonnull();
int sigemptyset(sigset_t *) paramsnonnull();
int sigfillset(sigset_t *) paramsnonnull();
int sigismember(const sigset_t *, int) paramsnonnull() nosideeffect;
int sigprocmask(int, const sigset_t *, sigset_t *);
int sigsuspend(const sigset_t *);
int sigpending(sigset_t *) paramsnonnull() nosideeffect;
int pthread_sigmask(int, const sigset_t *, sigset_t *);

COSMOPOLITAN_C_END_
#endif /* !(__ASSEMBLER__ + __LINKER__ + 0) */
#endif /* COSMOPOLITAN_LIBC_CALLS_STRUCT_SIGSET_H_ */
