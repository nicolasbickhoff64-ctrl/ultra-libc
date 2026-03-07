#ifndef SIGNAL_H
#define SIGNAL_H

#define SIGSEGV 11
#define SIGHUP 1
#define SIGINT 2
#define SIGTRAP 5
#define SIGUSR1 10
#define SIGUSR2 12

#include <sys/types.h>

typedef struct {
    unsigned long sig[64 / 8];
} sigset_t;

union sigval {
    int   sival_int;    /* Valor inteiro */
    void *sival_ptr;    /* Valor do ponteiro */
};

typedef struct {
    int      si_signo;  /* Signal number */
    int      si_code;   /* Signal code */
    pid_t    si_pid;    /* Sending process ID */
    uid_t    si_uid;    /* Real user ID of sending process */
    void    *si_addr;   /* Memory location which caused fault */
    int      si_status; /* Exit value or signal */
    union sigval si_value;  /* Signal value */
} siginfo_t;

struct sigaction {
    void (*sa_handler)(int);                // Signal handler function
    void (*sa_sigaction)(int, siginfo_t *, void *); // Advanced handler
    sigset_t sa_mask;                       // Signals to block during execution
    int sa_flags;                           // Flags (e.g., SA_SIGINFO, SA_RESTART)
    void (*sa_restorer)(void);              // Not used by userspace
};

int kill(pid_t pid, int sig);

#endif
