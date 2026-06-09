#include <math.h>
#include <omp.h>
// #include <stdio.h>

double fat[16];

void fill_fat() {
    fat[0] = 1.0;
    fat[1] = 1.0;

    for(int i = 2; i < 16; i++) {
        fat[i] = fat[i - 1] * (double) i;
    }
}

double exp_natural(int x, int n) {
    fill_fat();

    double sum = 0.0;

    #pragma omp parallel for
    for(int i = 0; i <= n; i++) {
        sum += pow(x, i)/(fat[i]);
        // printf("%lf\n", sum);
    }

    return sum;
}
//
//
// int main() {
//     printf("%lf\n", exp_natural(2, 7));
//     printf("%lf\n", exp_natural(3, 4));
//     return 0;
// }
