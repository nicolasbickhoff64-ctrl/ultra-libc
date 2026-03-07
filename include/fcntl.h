#ifndef FCNTL_H
#define FCNTL_H

#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

#define O_RDONLY 0
#define O_WRONLY 1
#define O_RDWR 2
#define O_CREAT 64
#define O_NOCTTY 256
#define O_TRUNC 512
#define O_APPEND 1024
#define O_NONBLOCK 2048
#define O_NDELEY 2048
#define O_DSYNC 4096
#define O_SYNC 1052672
#define O_DIRECT 16384
#define O_DIRECTORY 65536
#define O_CLOEXEC 524288
#define O_EXCL 128

#define AT_FDCWD -100
#define AT_SYMLINK_NOFOLLOW 256

#define F_DUPFD  0
#define F_GETFD  1
#define F_SETFD  2
#define F_GETFL  3
#define F_SETFL  4
#define F_GETLK  5
#define F_SETLK  6
#define F_SETLKW 7

int open(const char *path, int flags, ...);
int creat(const char *path, mode_t mode);
int openat(int dirfd, const char *path, int flags, mode_t mode);
int openat2(int dirfd, const char *path, void *how, size_t size);

#endif
