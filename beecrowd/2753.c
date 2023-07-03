#include <stdio.h>
#include <stdlib.h>

int main() {
	int var = 97;
	while(var <= 122) {
		printf("%d e %c\n", var, (char) var);
		var++;
	}

	exit(0);
}
