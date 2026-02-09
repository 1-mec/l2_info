#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

void calc(int deb,int i){
}

int create_procs(){
    for (int i = 0; i < 10; i++){
        int p = fork();
        if(p ==0){
            
            int res = (i+1)*100;
            int res2 = 1*i*100; 
            int subTot = 0;
            for (int j = res2 ; j <= res; j++){
                subTot += j;
            }
            printf("pid & ppid => %d %d ========> subtot = %d\n",getpid(),getppid(),subTot);
            exit(0); 
        }
    }
}

int main(){

    create_procs();
    //calc(500);

}
