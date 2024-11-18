// fifotest_p: parent
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int n = 10;

int main() {
    int p2c = open("p2c", O_WRONLY);
    int c2p = open("c2p", O_RDONLY);
    unsigned char k = 0;
    write(p2c, &k, 1);
    for (int i = 0; i < n; i++) {
        read(c2p, &k, 1);
        printf("parent: %d\n", k);
        k = k + 1;
        write(p2c, &k, 1);
        sleep(1);
    }
    close(p2c);
    close(c2p);
    return 0;
}
