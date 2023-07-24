#include <stdio.h>
#include <stdlib.h>

int main() {
    int ages = 0;
    int num_people = 0;
    int age = 0;

    scanf("%d", &age);
    while(age >= 0) {
        ages += age;
        num_people++;
        scanf("%d", &age);
    }

    printf("%.2lf\n", (double)ages/num_people);
    exit(0);
}
