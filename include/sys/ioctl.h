#ifndef IOCTL_H
#define IOCTL_H

#define FIONREAD 21531
#define FIONBIO 21537
#define FIOCLEX 21585
#define TIOCOUTQ 21521
#define TIOCGWINSZ 21523
#define SIOCGIFADDR 35093
#define SIOCSIFADDR 35094
#define SIOCGIFFLAGS 35091

int ioctl(int fd, unsigned long request, ...);

#endif
