#include <stdarg.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stddef.h>
#include <sys/syscall.h>
#include <unistd.h>

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
