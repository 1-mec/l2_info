#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <signal.h>

const char srv_filename[] = "/tmp/sock_srv";
const int maxlength = 256;

void err(char s[]) {
  perror(s);
  exit(-1);
}

void traiter_signal(int signo) {
  unlink(srv_filename);
  exit(0);
}

void main() {

  int sd;  // n° fd de la socket
  int ret;

  struct sockaddr_un addrsrv;

  char msg[maxlength];

  struct sigaction act;

  sigemptyset(&(act.sa_mask));
  act.sa_flags = 0;
  act.sa_handler = traiter_signal;

  sigaction(SIGINT, &act, NULL);

  if ( (sd = socket(AF_UNIX, SOCK_DGRAM, 0)) == -1) err("création socket");
  printf("n° fd de la socket = %d\n", sd);

  addrsrv.sun_family = AF_UNIX;
  strcpy(addrsrv.sun_path, srv_filename);

  if (bind(sd, (const struct sockaddr *)&addrsrv, sizeof(addrsrv)) != 0) err("bind");

  while (1) {
    // attend un message
    ret = recvfrom(sd, msg, maxlength, 0, NULL, NULL);
    if (ret == -1) err("recvfrom");
    msg[ret] = '\0';
    printf("recvfrom = %d\nmessage du client = %s\n", ret, msg);
  }
}
