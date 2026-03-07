#include <stddef.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <errno.h>

extern long wrap(long ret);

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset) {
    return (void*)wrap(syscall(SYS_mmap, addr, length, prot, flags, fd, offset));
}

int munmap(void *addr, size_t length) {
    return (int)wrap(syscall(SYS_munmap, addr, length));
}

int mprotect(void *addr, size_t len, int prot) {
    return (int)wrap(syscall(SYS_mprotect, addr, len, prot));
}
