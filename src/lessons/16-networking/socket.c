#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main() {
  // Create a UDP socket with a IPv4 address family
  int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }
  printf("Socket created with file descriptor: %d\n", sockfd);

  // Close the socket
  if (close(sockfd) == -1) {
    perror("close");
    exit(EXIT_FAILURE);
  }
  printf("Socket closed successfully.\n");
  return 0;
}