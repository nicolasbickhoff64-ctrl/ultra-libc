#ifndef UNISTD_H
#define UNISTD_H

#include <stdint.h>
#include <stddef.h>
#include <sys/types.h>

#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2
#define stdin 0
#define stdout 1
#define stderr 2

ssize_t write(int fd, const void *buf, ssize_t size);
ssize_t read(int fd, void *buf, ssize_t size);
long syscall(long num, ...);
pid_t getpid();
int brk(void *addr);
void *sbrk(intptr_t increment);
int close(int fd);
off_t lseek(int fd, off_t offset, int whence);
uid_t getuid();
uid_t geteuid();
gid_t getgid();
gid_t getegid();
pid_t fork();
pid_t vfork();
int gethostname(char *name, size_t len);
int sethostname(const char *name, size_t len);
int execve(const char *pathname, char *const argv[], char *const envp[]);
pid_t getppid();
int unlink(const char *pathname);
int rmdir(const char *path);
int chown(const char *path, uid_t owner, gid_t group);
int dup(int oldfd);
int dup2(int oldfd, int newfd);
int pipe(int fd[2]);
int truncate(const char *path, off_t length);
int ftruncate(int fd, off_t length);
int fsync(int fd);

#endif
