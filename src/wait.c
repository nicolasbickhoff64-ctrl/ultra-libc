#include <sys/wait.h>
#include <sys/syscall.h>
#include <unistd.h>

extern long wrap(long ret);

pid_t waitpid(pid_t pid, int *status, int options) {
    return wrap(syscall(SYS_wait4, pid, status, options, 0));
}
