#ifndef SOCKET_H
#define SOCKET_H

#define AF_UNSPEC 0
#define AF_LOCAL 1
#define AF_UNIX 1
#define AF_INET 2
#define AF_INET6 10

#include <sys/types.h>

typedef unsigned short sa_family_t;

struct sockaddr {
    sa_family_t     sa_family;      /* Address family */
    char            sa_data[];      /* Socket address */
};

typedef unsigned int socklen_t;

int socket(int domain, int type, int protocol);
int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
int listen(int sockfd, int backlog);

#endif
