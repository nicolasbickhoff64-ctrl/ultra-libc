#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/syscall.h>

extern long wrap(long ret);

struct alloc {
    size_t size;
    void *p;
};

static struct alloc maps[8192] = { 0 };
static int total_maps = 0;

__attribute__((noreturn))
void exit(int code) {
    syscall(SYS_exit, code);
    for (;;) { }
}

__attribute__((noreturn))
void _exit(int code) {
    exit(code);
    for (;;) { }
}

void *malloc(size_t size) {
    void *p = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    if (p == MAP_FAILED) { return NULL; }
    maps[total_maps].size = size;
    maps[total_maps].p = p;
    total_maps++;
    return p;
}

void free(void *p) {
    if (!p) return;
    int found = 0;
    int i = 0;
    for (i = 0; i < total_maps; i++) {
        if (maps[i].p == p) { found = 1; break; }
    }
    size_t size = maps[i].size;
    if (found == 1) {
        int r = munmap(p, size);
        if (r == -1) return;
        maps[i] = maps[total_maps - 1];
        total_maps--;
        return;
    } else {
        return;
    }
}
