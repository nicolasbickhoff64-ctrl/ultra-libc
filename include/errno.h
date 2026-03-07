#ifndef ERRNO_H
#define ERRNO_H

#define EPERM 1
#define ENOENT 2
#define EINTR 4
#define EAGAIN 11
#define ENOMEM 12
#define EACCES 13
#define EFAULT 14
#define EINVAL 22
#define EMFILE 24

int *__errno_location(void);
#define errno (*__errno_location())

#endif
