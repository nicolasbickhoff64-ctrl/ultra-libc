#include <sys/resource.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <sys/types.h>

extern long wrap(long ret);

int setpriority(int which, id_t who, int value) {
    return wrap(syscall(SYS_setpriority, which, who, value));
}
