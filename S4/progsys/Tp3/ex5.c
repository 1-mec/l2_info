#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char * argv[]){
    if (argc != 2){
        printf("nb arguments pas bon");
        return 1;
    }

    int fd = open("fic1" , O_RDWR | O_CREAT | O_APPEND , S_IRUSR | S_IROTH | S_IRGRP );

    if (fd == -1){
        perror("nop mdrr");
    }

    int buf = strlen(argv[1]);

    for (int i = 0; i < 256 ; i++){
        unsigned char x = i;
        int c = write(fd,buf, strlen(&x));
    }
    
    close(fd);
    return 0;
}