#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void main(int argc, char** argv) {

	for(int i = 1; i < argc - 1; i++) {

		FILE* f1 = fopen(argv[i], "r");
		fseek(f1, 0, SEEK_END);
		long long unsigned size1 = ftell(f1);
		rewind(f1);

		char* str1 = malloc(size1);
		fread(str1, sizeof(char), size1, f1);

		for(int j = i + 1; j < argc; j++) {

			bool diferentes = false;

			printf("%s %s ", argv[i], argv[j]);

			FILE* f2 = fopen(argv[j], "r");
			fseek(f2, 0, SEEK_END);
			long long unsigned size2 = ftell(f2);

			rewind(f2);

			if(size1 != size2) {
				fclose(f2);
				printf("diferentes\n");
				continue;
			}
			char* str2 = malloc(size2);
			fread(str2, sizeof(char), size2, f2);

			int k = 0;
			while(k < size1) {
				if(str1[k] != str2[k]) {
					diferentes = true;
					break;
				}
				k++;
			}
			free(str2);	
			fclose(f2);
			diferentes ? printf("diferentes\n") : printf("iguais\n");
		}
		fclose(f1);
		free(str1);	
	}
	exit(0);
}
