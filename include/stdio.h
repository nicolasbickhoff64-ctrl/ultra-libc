#ifndef STDIO_H
#define STDIO_H

typedef struct {
    int fd;
} FILE;

int printf(char *s, ...);
int puts(char *s);
char *fgets(char *str, int n, FILE *stream);

#endif
