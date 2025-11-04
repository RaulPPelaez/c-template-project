#include <errno.h>
#include <ifaddrs.h> // for getifaddrs and freeifaddrs
#include <netdb.h>   // for getnameinfo
#include <stdio.h>
#include <string.h>
int main() {
  struct ifaddrs *addresses;
  if (getifaddrs(&addresses) == -1) {
    printf("getifaddrs call failed with error: %s\n", strerror(errno));
    return -1;
  }
  struct ifaddrs *addr = addresses;
  while (addr) {
    if (addr->ifa_addr == NULL) {
      addr = addr->ifa_next;
      continue;
    }
    const int family = addr->ifa_addr->sa_family;
    const bool isIPv4 = family == AF_INET;
    // int isIPv6 = family == AF_INET6;

    const int family_size =
        isIPv4 ? sizeof(struct sockaddr_in) : sizeof(struct sockaddr_in6);
    if (isIPv4) {
      char ap[100];
      getnameinfo(addr->ifa_addr, family_size, ap, sizeof(ap), 0, 0,
                  NI_NUMERICHOST);
      printf("%s\t%s\n", addr->ifa_name, ap);
    }
    addr = addr->ifa_next;
  }
  freeifaddrs(addresses);
  return 0;
}