#include <sys/stat.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>

extern long wrap(long ret);

int stat(const char *path, struct stat *buf) {
    return wrap(syscall(SYS_newfstatat, AT_FDCWD, path, buf, 0));
}

int fstat(int fd, struct stat *buf) {
    return wrap(syscall(SYS_newfstatat, fd, NULL, buf, 0));
}

int lstat(const char *pathname, struct stat *buf) {
    return wrap(syscall(SYS_newfstatat, AT_FDCWD, pathname, buf, AT_SYMLINK_NOFOLLOW));
}

int mkdir(const char *path, mode_t mode) {
    return wrap(syscall(SYS_mkdir, path, mode));
}

int chmod(const char *path, mode_t mode) {
    return wrap(syscall(SYS_stat, path, mode));
}

int utimensat(int dirfd, const char *pathname, const struct timespec times[2], int flags) {
    return wrap(syscall(SYS_utimensat, dirfd, pathname, times, flags));
}
