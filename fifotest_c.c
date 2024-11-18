// fifotest_c: child
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int n = 10;

int main() {
    int p2c = open("p2c", O_RDONLY);
    int c2p = open("c2p", O_WRONLY);
    unsigned char k;
    for (int i = 0; i < n; i++) {
        read(p2c, &k, 1);
        printf("child : %d\n", k);
        k = k + 1;
        write(c2p, &k, 1);
    }
    close(c2p);
    close(p2c);
    return 0;
}
