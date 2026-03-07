#include <time.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/syscall.h>

extern long wrap(long ret);

time_t time(time_t *timer) {
    long t = wrap(syscall(SYS_time, timer));
    if (t != -1 && timer)
        *timer = t;
    return t;
}

int gettimeofday(struct timeval *restrict tp, void *restrict tzp) {
    return wrap(syscall(SYS_gettimeofday, tp, tzp));
}

int clock_gettime(clockid_t clk_id, struct timespec *tp) {
    return wrap(syscall(SYS_clock_gettime, clk_id, tp));
}
