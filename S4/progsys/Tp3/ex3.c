#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char * argv[]){
    if (argc != 3){
        printf("manque d'arguments");
        return 1;
    }

    int fd = open(argv[1], O_WRONLY | O_APPEND , S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    if (fd == -1){
        perror("");
    }

    int c = write(fd,argv[2], strlen(argv[2]));
    
    close(fd);
    return 0;
}