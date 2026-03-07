#ifndef STDLIB_H
#define STDLIB_H

#include <stddef.h>
#include <stdint.h>

void exit(int code);
void *malloc(size_t size);
void free(void *p);
void _exit(int code);

#endif
