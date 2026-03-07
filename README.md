# ultra-libc
A minimal libc that is even smaller than musl itself, with a static libc size of ~37 KB, and a dynamic one weighing ~21 KB, and the loader for the dynamic libc is not yet implemented, but in the future we can create a functional loader for the ultra-libc, the implemented functions are:
open, creat, openat, openat2, fcntl, ioctl, mmap, munmap, mprotect, setpriority, kill, rt_sigaction, socket, connect, bind, listen, accept, stat, fstat, lstat, mkdir, chmod, utimensat, printf (only %s and %c), puts, rename, exit, _exit, malloc, free, strlen, strcpy, strcat, strcmp, memcpy, time, gettimeofday, clock_gettime, write, read, syscall, getpid, brk, sbrk, close, lseek, getuid, geteuid, getgid, getegid, fork, vfork, gethostname, sethostname, execve, getppid, unlink, rmdir, chown, dup, dup2, pipe, truncate, ftruncate, fsync, uname, and waitpid.

Totaling 67 functions.

And in the future, this libc may become famous for the size of the binaries it generates.
