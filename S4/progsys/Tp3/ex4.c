#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char * argv[]){
    if (argc != 2){
        printf("nb arguments pas bon");
        return 1;
    }

    int fd = open("fic1" , O_WRONLY | O_CREAT | O_APPEND , S_IRUSR | S_IWUSR | S_IRGRP );

    if (fd == -1){
        perror("nop mdrr");
    }

    for (int i = 0; i < 256 ; i++){
        unsigned char x = &i;
        int c = write(fd,x, strlen(&x));
    }
    
    close(fd);
    return 0;
}