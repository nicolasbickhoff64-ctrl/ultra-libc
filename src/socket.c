#include <sys/socket.h>
#include <sys/syscall.h>
#include <unistd.h>

extern long wrap(long ret);

int socket(int domain, int type, int protocol) {
    return wrap(syscall(SYS_socket, type, protocol));
}

int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen) {
    return wrap(syscall(SYS_connect, sockfd, addr, addrlen));
}

int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen) {
    return wrap(syscall(SYS_bind, sockfd, addr, addrlen));
}

int listen(int sockfd, int backlog) {
    return wrap(syscall(SYS_bind, sockfd, backlog));
}

int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen) {
    return wrap(syscall(SYS_accept, addr, addrlen));
}
