# ultra-libc
ultra-libc is a minimal C standard library for x86_64, even smaller than musl, designed for ultra-tiny, standalone binaries.

Static libc size: ~37 KB

Dynamic libc size: ~21 KB (loader not yet implemented)

In the future, a functional loader may be added to support dynamic linking.

# Implemented functions

ultra-libc currently implements 67 core functions, including:

# File operations:
open, creat, openat, openat2, fcntl, ioctl, stat, fstat, lstat, mkdir, chmod, utimensat, rename, unlink, rmdir, truncate, ftruncate, fsync, chown, dup, dup2, pipe

# Memory management:
mmap, munmap, mprotect, brk, sbrk, malloc, free, memcpy

# Process & signals:
fork, vfork, execve, getpid, getppid, getuid, geteuid, getgid, getegid, kill, rt_sigaction, setpriority

# I/O & strings:
write, read, printf (supports %s and %c), puts, strlen, strcpy, strcat, strcmp

# Networking:
socket, connect, bind, listen, accept

# Time & system info:
time, gettimeofday, clock_gettime, uname, gethostname, sethostname

# Syscall wrapper:
syscall

# Process control:
exit, _exit, waitpid

Future prospects

This libc is designed for extremely small binaries, and it may become famous for the tiny size of executables it produces, making it ideal for embedded systems, minimal Linux environments, or experiments with ultra-tiny OS development.
