#ifndef UN_H
#define UN_H

struct sockaddr_un {
    sa_family_t     sun_family;     /* Address family */
    char            sun_path[];     /* Socket pathname */
};

#endif
