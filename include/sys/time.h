#ifndef SYS_TIME_H
#define SYS_TIME_H

#include <sys/types.h>

struct timeval {
    time_t tv_sec;    /* Segundos - time_t (geralmente long de 64-bit) */
    suseconds_t tv_usec; /* Microssegundos - suseconds_t (geralmente long) */
};

int gettimeofday(struct timeval *restrict tp, void *restrict tzp);

#endif
