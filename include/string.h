#ifndef STRING_H
#define STRING_H

size_t strlen(const char *t);
char *strcpy(char *dst, char *src);
char *strcat(char *dst, char *src);
int strcmp(char *t1, char *t2);
void *memcpy(void *dest, const void *src, size_t n);

#endif
