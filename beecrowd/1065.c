#include <stdio.h>
#include <stdlib.h>


int main() {
    int NUM_INTEGERS = 5;
    short count_even = 0;
    char* MSG = "valores pares\n";
    while(NUM_INTEGERS--){
        int val = 0; 
        scanf("%d", &val);
        count_even = val % 2 == 0 ? count_even + 1 : count_even;
    }

    printf("%d %s", count_even, MSG);
    exit(0);
}
