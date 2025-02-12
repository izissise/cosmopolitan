#ifndef COSMOPOLITAN_LIBC_SOCK_SOCK_H_
#define COSMOPOLITAN_LIBC_SOCK_SOCK_H_
#include "libc/sock/struct/sockaddr.h"
#if !(__ASSEMBLER__ + __LINKER__ + 0)
COSMOPOLITAN_C_START_
/*───────────────────────────────────────────────────────────────────────────│─╗
│ cosmopolitan § system api » berkeley sockets                             ─╬─│┼
╚────────────────────────────────────────────────────────────────────────────│*/

#define INET_ADDRSTRLEN 22
#define IFHWADDRLEN     6

uint16_t htons(uint16_t);
uint16_t ntohs(uint16_t);
uint32_t htonl(uint32_t);
uint32_t ntohl(uint32_t);

#if defined(__GNUC__) && !defined(__STRICT_ANSI__)
#define htons(x) __builtin_bswap16(x)
#define ntohs(x) __builtin_bswap16(x)
#define htonl(x) __builtin_bswap32(x)
#define ntohl(x) __builtin_bswap32(x)
#endif

const char *inet_ntop(int, const void *, char *, uint32_t);
int inet_pton(int, const char *, void *);
uint32_t inet_addr(const char *);
int parseport(const char *);
uint32_t *GetHostIps(void);

int nointernet(void);
int socket(int, int, int);
int accept(int, struct sockaddr *, uint32_t *);
int accept4(int, void *, uint32_t *, int);
int bind(int, const void *, uint32_t);
int connect(int, const void *, uint32_t);
int listen(int, int);
int shutdown(int, int);
int getsockname(int, void *, uint32_t *);
int getpeername(int, void *, uint32_t *);
ssize_t send(int, const void *, size_t, int);
ssize_t recv(int, void *, size_t, int);
ssize_t recvfrom(int, void *, size_t, uint32_t, void *, uint32_t *);
ssize_t sendfile(int, int, int64_t *, size_t);
int getsockopt(int, int, int, void *, uint32_t *);
int setsockopt(int, int, int, const void *, uint32_t);
int socketpair(int, int, int, int[2]);
ssize_t sendto(int, const void *, size_t, uint32_t, const void *, uint32_t);
int sockatmark(int);

COSMOPOLITAN_C_END_
#endif /* !(__ASSEMBLER__ + __LINKER__ + 0) */
#endif /* COSMOPOLITAN_LIBC_SOCK_SOCK_H_ */
