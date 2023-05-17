#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void check_if_can_pass(bool *arr){
		int x;
		scanf("%d", &x);
		x--;
		arr[x] = true;
}

int main(){
	int n = 0, p = 0, q = 0;
	scanf("%d", &n);
	bool *arr = malloc(n * sizeof(bool));
	for(int i = 0; i < n ; i++)
		arr[i] = false;
	scanf("%d", &p); 
	while(p--){
		check_if_can_pass(arr);
	}
	scanf("%d", &q);
	while(q--){
		check_if_can_pass(arr);
	}
	for(int i = 0; i < n; i++){
		if(!arr[i]){
			printf("Oh, my keyboard!\n");
			exit(0);
		}
	}
	printf("I become the guy.\n");
	exit(0);
}
