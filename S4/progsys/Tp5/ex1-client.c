#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

const char server_addr[] = "127.0.0.1";
const int port_num = 2000;
const int maxlength = 256;

void err(char s[]) {
  perror(s);
  exit(-1);
}

void main() {

  int sd;  // n° fd de la socket
  int ret;

  struct sockaddr_in addrsrv;

  char msg[maxlength];

  if ( (sd = socket(AF_INET, SOCK_STREAM, 0)) == -1) err("création socket");
  printf("n° fd de la socket = %d\n", sd);

  addrsrv.sin_family = AF_INET;
  addrsrv.sin_port = htons(port_num);
  inet_aton(server_addr, &addrsrv.sin_addr);

  if (connect(sd, (const struct sockaddr*)&addrsrv, sizeof(addrsrv)) == -1) err("connect");

  while (1) {
    printf("Entrer un message :");
    fgets(msg, maxlength, stdin);
    if (strlen(msg)>1) {
      msg[strlen(msg)-1] = '\0';
      ret = sendto(sd, msg, strlen(msg), 0, (const struct sockaddr*)&addrsrv, sizeof(addrsrv));
      if (ret == -1) err("sendto");
      printf("sendto = %d\n", ret);
      ret = recvfrom(sd, msg, maxlength, 0, NULL, NULL);
      if (ret == -1) err("recvfrom");
      msg[ret] = '\0';
      printf("recvfrom = %d\nréponse du serveur = %s\n", ret, msg);
    }
  }
}
