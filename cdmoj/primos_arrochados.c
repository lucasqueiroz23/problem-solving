#include <math.h>
#include <stdio.h>
#include <omp.h>
#include <stdbool.h>

#define SIZE 100

int arr[SIZE];
int prime_arr[SIZE];

bool isPrime(int num) {
    if(num == 1) return false;

    int sqrt_num = (int) sqrt(num);
    for(int i = 2; i < sqrt_num; i++){
        if(num % i == 0) return false;
    }

    return true;
}

void update_prime_arr(int index) {
    prime_arr[index] = 1;
    int num = arr[index];

    while(num != 0) {
        if(!isPrime(num)) {
            prime_arr[index] = 0;
            break;
        }
        num /= 10;
    }
}

int main() {
    int t = 0;

    scanf("%d", &t);
    const int T = t;

    for(int i = 0; i < T; i++) {

        prime_arr[i] = 0;

        int n = 0;
        scanf("%d", &n);
        arr[i] = n;
    }

    #pragma omp parallel for
    for(int i = 0; i < T; i++) {
        update_prime_arr(i);
    }
    
    for(int i = 0; i < T; i++){
        if(prime_arr[i] == 0) {
            printf("N\n");
        } else {
            printf("S\n");
        }
    }

    return 0;
}
