#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    int total = 0;
    for (int i = 0; i < 10; i++){
        int tube[2];
        pipe(tube);
        int p = fork();
        if(p ==0){
            close(tube[0]);
            int res = (i+1)*100;
            int res2 = i*100+1; 
            int subTot = 0;
            for (int j = res2 ; j <= res; j++){
                subTot += j;
            }
            printf("pid & ppid => %d %d ========> subtot = %d\n",getpid(),getppid(),subTot);
            write(tube[1], &subTot,sizeof(subTot));
            close(tube[1]);
            exit(0); 
        } else {
            close(tube[1]);
            int temp;
            int n = read(tube[0],&temp,sizeof(temp));
            if (n == sizeof(temp)){
                total += temp;
            }
            close(tube[0]);
        }
        wait(NULL);
    }
    printf("en gros tube fait %d\n",total);
}