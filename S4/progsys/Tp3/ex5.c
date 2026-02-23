#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>


#define N 758

int main() {
  int fd = open("fichier.txt", O_RDONLY);
  if (fd == -1) {
    perror("Ouverture du fichier");
  } else {
    unsigned char msg[N+1];
    int c;
    int i = 0;
    printf("===============================================================================\n");
    for(int i = 0 ; i < 758; i++){
        c = read(fd, msg, N);
        if (c>0) {
            msg[c] = 0; 
        }
        char cc = (char)c;
        printf("0x%X\n",msg[i]);
    }
    close(fd);
  }
}