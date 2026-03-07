#ifndef TIME_H
#define TIME_H

#include <sys/types.h>

typedef signed long long time_t;

struct timespec {
    time_t tv_sec;
    long   tv_nsec;
};

time_t time(time_t *timer);
int clock_gettime(clockid_t clk_id, struct timespec *tp);

#endif
