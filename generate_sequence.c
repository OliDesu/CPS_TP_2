#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>

int main() {
    int length;
    struct timeval tm;

    gettimeofday(&tm, NULL);
    srand(tm.tv_usec);
    length = rand()%100+10;
    while (length--)
        printf("%d", rand()%2);
    printf("\n");
    return 0;
}
