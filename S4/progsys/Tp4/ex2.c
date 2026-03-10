#include <stdio.h>
#include <unistd.h>

int main() {
    int tube[2];

    pipe(tube);
    printf("tube[0]=%d tube[1]=%d\n", tube[0], tube[1]);

    int pid=fork();

    if (pid == 0) {
        // processus fils
        close(tube[0]);
        dup2(tube[1], STDOUT_FILENO);
        execlp("du", "du", "-BK","--max-depth=1", NULL);
    } else {
        // processus père
        close(tube[1]);
        dup2(tube[0], STDIN_FILENO);
        execlp("sort","sort","-h",NULL);
    }
}
