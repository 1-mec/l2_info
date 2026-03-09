#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>


int main(int argc, char * argv[]) {
    struct stat st;
    int tube[2];

    int fd = open(argv[1], O_RDWR , 644);
    int fdd = open(argv[0], O_RDWR , 644);

    pipe(tube);

    if (argc == 1){
        printf("")
    }

    int fs = fstat(tube[0],&st );

    printf("tube n°%d ,fd = %d , size = %d , mode = %d, inode = %d\n",tube[0],fs, st.st_size, st.st_mode, st.st_ino);

}
