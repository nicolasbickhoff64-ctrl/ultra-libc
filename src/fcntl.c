#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <stddef.h>
#include <stdarg.h>
#include <sys/types.h>

static int cmd_requires_arg(int cmd) {
    switch(cmd) {
        case F_SETFL:
        case F_SETFD:
        case F_SETLK:
        case F_SETLKW:
            return 1; // precisa de argumento extra
        default:
            return 0; // não precisa
    }
}

extern long wrap(long ret);

int open(const char *path, int flags, ...) {
    return (int)wrap(syscall(SYS_openat, AT_FDCWD, flags, 0));
}

int creat(const char *path, mode_t mode) {
    return (int)wrap(syscall(SYS_creat, path, mode));
}

int openat(int dirfd, const char *path, int flags, mode_t mode) {
    return (int)wrap(syscall(SYS_openat, dirfd, path, flags, mode));
}

int openat2(int dirfd, const char *path, void *how, size_t size) {
    return (int)wrap(syscall(SYS_openat2, path, how, size));
}

int fcntl(int fd, int cmd, ...) {
    va_list ap;
    int arg = 0;

    va_start(ap, cmd);
    if (cmd_requires_arg(cmd))
        arg = va_arg(ap, int);
    va_end(ap);

    return wrap(syscall(SYS_fcntl, fd, cmd, arg));
}
