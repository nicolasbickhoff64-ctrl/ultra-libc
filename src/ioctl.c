#include <sys/ioctl.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <stdarg.h>

extern long wrap(long ret);

int ioctl(int fd, unsigned long request, ...) {
    va_list ap;
    void *arg = 0;

    va_start(ap, request);

    arg = va_arg(ap, void *);
    va_end(ap);

    return wrap(syscall(SYS_ioctl, fd, request, arg));
}
