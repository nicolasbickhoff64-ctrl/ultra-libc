#include <stddef.h>
#include <string.h>
#include <errno.h>

size_t strlen(const char *t) {
    size_t s = 0;
    while (t[s] != '\0') { s++; }
    return s;
}

char *strcpy(char *dst, char *src) {
    int s = 0;
    int i = 0;
    while (src[i] != '\0') { dst[i++] = src[s++]; }
    dst[i++] = '\0';
    return dst;
}

char *strcat(char *dst, char *src) {
    dst += strlen(dst);
    return strcpy(dst, src);
}

int strcmp(char *t1, char *t2) {
    if (!t1) { errno = EFAULT; return -1; }
    if (!t2) { errno = EFAULT; return -1; }
    while (*t1 != '\0' && *t2 != '\0') {
        if (*t1 != *t2) {
            return (int)*t1 - *t2;
        }
        t1++;
        t2++;
    }

    return (int)*t1 - *t2;
}

void *memcpy(void *dest, const void *src, size_t n) {
    int s = 0;
    int i = 0;
    while (s != n) { *(char*)(dest + s++) = *(char*)(src + i++); }
    return dest;
}
