#include <sys/utsname.h>
#include <sys/syscall.h>
#include <unistd.h>

extern long wrap(long ret);

int uname(struct utsname *buf) {
    return (int)wrap(syscall(SYS_uname, buf));
}
