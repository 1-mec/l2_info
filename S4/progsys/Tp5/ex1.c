#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

const int port_num = 2000;
const int maxlength = 256;

void err(char s[]) {
  perror(s);
  exit(-1);
}

void main() {

  int sd;         // n° fd de la socket en attente des connexions
  int accept_sd;  // n° fd de la socket d'une connexion
  int ret;
  int ret1;
 
  struct sockaddr_in addrsrv;
  struct sockaddr_in addrcli;
  int len_addrcli;

  char msg[maxlength];
  char replymsg[maxlength];
  char bienvenue[] = "bienvenue";

  if ( (sd = socket(AF_INET, SOCK_STREAM, 0)) == -1) err("création socket");
  printf("Ce serveur attend les connexions sur le port %d\n", port_num);
  printf("n° fd de la socket = %d\n", sd);

  addrsrv.sin_family = AF_INET;
  addrsrv.sin_port = htons(port_num);
  addrsrv.sin_addr.s_addr = htonl(INADDR_ANY);

// associe la socket à l'adresse IP locale et au port 2000
  if (bind(sd, (const struct sockaddr *)&addrsrv, sizeof(addrsrv)) != 0) err("bind");

  listen(sd, 1); //la socket écoute, 1 seule connexion possible

  while (1) {
    // attend une connexion
	len_addrcli = sizeof(addrcli);
	accept_sd = accept(sd, (struct sockaddr *)&addrcli, &len_addrcli); //attend(ne pas oublier sur le cc2) et accepte une connexion (bloquant)
	int pid = fork(); // car var serv sont les mêmes pour les 2 enfants
	if (pid == 0){
		//debut processus fils
		//1)Le serveur transmet au client un message de bienvenue
		ret1 = sendto(accept_sd,bienvenue, strlen(bienvenue), 0, (const struct sockaddr*)&addrcli, len_addrcli);
		if (ret1 == -1){
			err("sendto");
			exit(-1);
		}
		//printf("n° fd de la connexion = %d, port = %d\n", accept_sd, ntohs(addrcli.sin_port));
		// 2) boucle attente de message/réponse
		int actif = 1;
		while (actif) {
		  // attend l'arrivée d'un message sur une connexion (bloquant)
			  ret = recvfrom(accept_sd, msg, maxlength, 0, NULL, NULL);
			  if (ret == -1) {
				err("recvfrom");
				actif = 0;
			  } else if (ret == 0) {
				printf("fin de la connexion\n");
				close(accept_sd);
				actif = 0;
			  } else {
				msg[ret] = '\0';
				printf("recvfrom = %d\nmessage du client = %s\n", ret, msg);
				// prépare et envoi une réponse
				snprintf(replymsg, maxlength, "j'ai bien recu '%s'", msg);
				ret = sendto(accept_sd, replymsg, strlen(replymsg), 0, (const struct sockaddr*)&addrcli, len_addrcli);
				printf("sendto = %d\n", ret);
				if (ret == -1) {
				  err("sendto");
				  actif = 0;
				}
			  }
			}
		}
	}
}
