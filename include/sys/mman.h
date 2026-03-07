#ifndef MMAN_H
#define MMAN_H

#define PROT_NONE 0
#define PROT_READ 1
#define PROT_WRITE 2
#define PROT_EXEC 4
#define MAP_SHARED 1
#define MAP_PRIVATE 2
#define MAP_FIXED 16
#define MAP_ANONYMOUS 32
#define MAP_ANON 32
#define MAP_FAILED (void*)-1

#include <sys/types.h>
#include <stddef.h>
#include <stdint.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);
int munmap(void *addr, size_t length);
int mprotect(void *addr, size_t len, int prot);

#endif
