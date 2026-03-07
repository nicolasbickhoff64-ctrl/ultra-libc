#include <unistd.h>
#include <sys/syscall.h>
#include <signal.h>
#include <sys/types.h>
#include <stddef.h>

extern long wrap(long ret);

int kill(pid_t pid, int sig) {
    return wrap(syscall(SYS_kill, pid, sig));
}

int rt_sigaction(int signum, const struct sigaction *act, struct sigaction *oldact, size_t sigsetsize) {
    return wrap(syscall(SYS_rt_sigaction, signum, act, oldact, sigsetsize));
}
