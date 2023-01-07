#include <stdio.h>
#include <stdlib.h>

int isPalindrome(char *string, int length){
	for(int i = 0, j = length - 1; i<=j ; i++,j--){
		if(string[i] != string[j])
			return 0;
	}

	return 1;
}

int main(){

	int n = 0;
	scanf("%d", &n);

	char *word = malloc(n*sizeof(char));
	scanf("%s",word);
	printf("%d\n",isPalindrome(word,n));

	free(word);
	return 0;
}
