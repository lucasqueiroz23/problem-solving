#include <stdio.h>
#include <stdlib.h>

#define NUM_SOCKETS 4

int main(void) {
    int* t = malloc(NUM_SOCKETS * sizeof(int));

    int ans = 0; 

    for(int i = 0; i < NUM_SOCKETS; i++) {
        scanf("%d", &t[i]);
        ans += t[i];
        ans--;
    }
    ans++;


    printf("%d\n", ans);

    free(t);
    exit(0);
}
