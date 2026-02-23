#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char * argv[]){

    int fd = open("fic2" , O_WRONLY | O_CREAT | O_EXCL | O_APPEND );

    if (fd == -1){
        perror("nop mdrr");
    }

    lseek(fd,768,SEEK_CUR);

    for (int i = 0; i < 256 ; i++){
        unsigned char x = i;
        int c = write(fd,&x, strlen(&x));
    }
    
    close(fd);
    return 0;
}