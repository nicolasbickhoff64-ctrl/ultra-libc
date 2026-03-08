#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stddef.h>
#include <sys/syscall.h>
#include <unistd.h>

static void intToStr(int num, char *str) {
    int i = 0;
    int isNegative = 0;

    // Tratar 0 explicitamente
    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return;
    }

    // Tratar números negativos
    if (num < 0) {
        isNegative = 1;
        num = -num;
    }

    // Processar dígitos individuais
    while (num != 0) {
        int rem = num % 10;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / 10;
    }

    // Adicionar sinal negativo se necessário
    if (isNegative) {
        str[i++] = '-';
    }

    str[i] = '\0'; // Terminador nulo

    // Inverter a string
    int start = 0;
    int end = i - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

extern long wrap(long ret);

int printf(char *s, ...) {
    va_list args;
    va_start(args, s);

    int total = 0;

    for (char *p = s; *p; p++) {
        if (*p == '%') {
            p++;
            if (*p == 's') {
                char *str = va_arg(args, char*);
                int ret = write(1, str, strlen(str));
                if (ret < 0) {
                    va_end(args);
                    return -1;
                }
                total += ret;
            } else if (*p == 'c') {
                char c = (char)va_arg(args, int);
                int ret = write(1, &c, 1);
                if (ret < 0) {
                    va_end(args);
                    return -1;
                }
                total += ret;
            } else if (*p == 'd') {
                int n = (int)va_arg(args, int);
                char buffer[200];
                intToStr(n, buffer);
                int ret = write(1, buffer, strlen(buffer));
                if (ret < 0) {
                    va_end(args);
                    return -1;
                }
                total += ret;
            }
        } else {
            int ret = write(1, p, 1);
            if (ret < 0) {
                va_end(args);
                return -1;
            }
            total += ret;
        }
    }

    va_end(args);
    return total;
}

int puts(char *s) {
    size_t len = strlen(s);
    if (write(1, s, len) == -1) { return -1; } else { write(1, "\n", 1); return len+1; }
}

int rename(const char *oldname, const char *newname) {
    return wrap(syscall(SYS_rename, oldname, newname));
}

char *fdgets(int fd, char *buf, int n) {
    if (n <= 0) return 0;
    int i = 0;
    char c;

    while (i < n - 1) {
        ssize_t r = read(fd, &c, 1);
        if (r <= 0) break; // EOF ou erro
        buf[i++] = c;
        if (c == '\n') break;
    }

    if (i == 0) return 0; // nada lido
    buf[i] = 0;
    return buf;
}

char *fgets(char *str, int n, FILE *stream) {
    return fdgets((int)stream, str, n);
}
