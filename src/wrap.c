#include <errno.h>

long wrap(long ret) {
    if (ret < 0 && ret >= -4095) {
        errno = -ret;
        return -1;
    }
    return ret;
}
