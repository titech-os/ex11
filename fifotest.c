#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    char *av[] = { 0 };
    int c1, c2;
    if ((c1 = fork()) == 0) {
        execv("fifotest_p", av);
    }
    if ((c2 = fork()) == 0) {
        execv("fifotest_c", av);
    }
    if (c1 < 0 || c2 < 0) {
        fprintf(stderr, "fork failed\n");
        exit(EXIT_FAILURE);
    }
    wait(NULL);
    wait(NULL);
    return EXIT_SUCCESS;
}
