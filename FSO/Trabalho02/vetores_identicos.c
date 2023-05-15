#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

int n;

void read_array(int *arr){
	int num = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &num);
		arr[i] = num;
	}
}

int compare_int(const void *a, const void *b){
	if(*(int *)a == *(int *)b) return 0;
	return *(int*)a < *(int*)b ? -1 : 1;
}

bool arrays_are_equal(int *arr1, int *arr2) {
	for(int i = 0; i < n; i++)
		if(arr1[i] != arr2[i]) return false;
	return true;
}

void *sort(void *arg){
	int *arr = (int *)arg;
	qsort(arr, n, sizeof(int), compare_int);
}

int main(){
	scanf("%d", &n);

	int *arr1 = malloc(n * sizeof(int));
	int *arr2 = malloc(n * sizeof(int));

	read_array(arr1);
	read_array(arr2);

	pthread_t tid;
	pthread_create(&tid, NULL, sort, arr1);
	sort(arr2);		
	pthread_join(tid, NULL);
	
	if (arrays_are_equal(arr1, arr2))
		printf("Mesmos elementos\n");
	else printf("Diferentes\n");

	free(arr1);
	free(arr2);

	exit(0);
}
