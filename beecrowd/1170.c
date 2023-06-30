#include <stdio.h>
#include <stdlib.h>

int main() {
	int n = 0;
	scanf("%d", &n);
	while(n--) {
		double food = 0;
		scanf("%lf", &food);

		int count = 0;
		while( food > 1) {
			count++;
			food /= 2;
		}
		printf("%d dias\n", count);
	}
	exit(0);
}
