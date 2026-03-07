#ifndef STAT_H
#define STAT_H

#include <time.h>
#include <sys/types.h>

struct stat {
    dev_t      st_dev;
    ino_t      st_ino;
    mode_t     st_mode;
    nlink_t    st_nlink;
    uid_t      st_uid;
    gid_t      st_gid;
    dev_t      st_rdev;
    off_t      st_size;
    blksize_t  st_blksize;
    blkcnt_t   st_blocks;
    time_t     st_atime;
    time_t     st_mtime;
    time_t     st_ctime;
};

int stat(const char *path, struct stat *buf);
int fstat(int fd, struct stat *buf);
int lstat(const char *pathname, struct stat *buf);
int mkdir(const char *path, mode_t mode);
int chmod(const char *path, mode_t mode);
int utimensat(int dirfd, const char *pathname, const struct timespec times[2], int flags);

#endif
