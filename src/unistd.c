#include <unistd.h>
#include <stdarg.h>
#include <sys/syscall.h>
#include <errno.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/utsname.h>
#include <string.h>

char **environ;

extern long wrap(long ret);

ssize_t write(int fd, const void *buf, size_t size) {
    return (ssize_t)wrap(syscall(SYS_write, fd, buf, size));
}

ssize_t read(int fd, void *buf, size_t size) {
    return (ssize_t)wrap(syscall(SYS_read, fd, buf, size));
}

long syscall(long num, ...) {
    va_list lista;
    long ret=0,a1=0,a2=0,a3=0,a4=0,a5=0,a6=0;

    va_start(lista, num);
    a1 = va_arg(lista, long);
    a2 = va_arg(lista, long);
    a3 = va_arg(lista, long);
    a4 = va_arg(lista, long);
    a5 = va_arg(lista, long);
    a6 = va_arg(lista, long);

    va_end(lista);

    register long r10 asm("r10") = a4;
    register long r8  asm("r8")  = a5;
    register long r9  asm("r9")  = a6;

    asm volatile (
        "syscall"
        : "=a" (ret)
        : "a"(num), "D"(a1), "S"(a2), "d"(a3), "r"(r10), "r"(r8), "r"(r9)
        : "rcx", "r11", "memory"
    );

    return ret;
}

pid_t getpid() {
    return (pid_t)wrap(syscall(SYS_getpid));
}

int brk(void *addr) {
    void *r = (void*)syscall(SYS_brk, addr);

    if (r < addr) { errno = ENOMEM; return -1; }
    return 0;
}

void *sbrk(intptr_t increment) {
    void *old = (void*)syscall(SYS_brk, 0);
    syscall(SYS_brk, old + increment);
    return old;
}

int close(int fd) {
    return (int)wrap(syscall(SYS_close, fd));
}

off_t lseek(int fd, off_t offset, int whence) {
    return (off_t)wrap(syscall(SYS_lseek, fd, offset, whence));
}

uid_t getuid() {
    return (uid_t)wrap(syscall(SYS_getuid));
}

uid_t geteuid() {
    return (uid_t)wrap(syscall(SYS_geteuid));
}

gid_t getgid() {
    return (gid_t)wrap(syscall(SYS_getgid));
}

gid_t getegid() {
    return (gid_t)wrap(syscall(SYS_getegid));
}

pid_t fork() {
    return (pid_t)wrap(syscall(SYS_fork));
}

pid_t vfork() {
    return (pid_t)wrap(syscall(SYS_vfork));
}

int gethostname(char *name, size_t len) {
    if (!name) { errno = EFAULT; return -1; }
    struct utsname uts;
    if (uname(&uts) == -1) { return -1; }
    ssize_t l = strlen(uts.nodename);
    if (l >= len)
        l = len - 1;
    memcpy(name, uts.nodename, l);
    return 0;
}

int sethostname(const char *name, size_t len) {
    return (int)wrap(syscall(SYS_sethostname, name, len));
}

int execve(const char *pathname, char *const argv[], char *const envp[]) {
    return (int)wrap(syscall(SYS_execve, pathname, argv, envp));
}

pid_t getppid() {
    return (pid_t)wrap(syscall(SYS_getppid));
}

int unlink(const char *pathname) {
    return wrap(syscall(SYS_unlink, pathname));
}

int rmdir(const char *path) {
    return wrap(syscall(SYS_rmdir, path));
}

int chown(const char *path, uid_t owner, gid_t group) {
    return wrap(syscall(SYS_chown, path, owner, group));
}

int dup(int oldfd) {
    return wrap(syscall(SYS_dup, oldfd));
}

int dup2(int oldfd, int newfd) {
    return wrap(syscall(SYS_dup2, oldfd, newfd));
}

int pipe(int fd[2]) {
    return wrap(syscall(SYS_pipe, fd));
}

int truncate(const char *path, off_t length) {
    return wrap(syscall(SYS_truncate, path, length));
}

int ftruncate(int fd, off_t length) {
    return wrap(syscall(SYS_ftruncate, fd, length));
}

int fsync(int fd) {
    return wrap(syscall(SYS_fsync, fd));
}

int chdir(const char *path) {
    return wrap(syscall(SYS_chdir, path));
}
