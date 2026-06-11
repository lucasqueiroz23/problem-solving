#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

int prefix_scan(int* arr, int start, int end) {

    for(int i = start + 1; i < end; i++) {
        arr[i] += arr[i-1];
    }

    return arr[end - 1];
}

int main(int argc, char** argv) {
    int init_result = MPI_Init(&argc, &argv);
    MPI_Status status;
    if(init_result != MPI_SUCCESS) {
        MPI_Abort(MPI_COMM_WORLD, init_result);
    }

    int number_of_processes = 0;
    MPI_Comm_size(MPI_COMM_WORLD, &number_of_processes);

    int rank = 0;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);


    int s = 0;
    int n = 0;

    if(rank == 0) {
        scanf("%d", &s);
        scanf("%d", &n);
    }

    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&s, 1, MPI_INT, 0, MPI_COMM_WORLD);

    srand(s);
    int arr[n];
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    int sum = 0;
    int chunk_size = n / number_of_processes;

    int start = rank * chunk_size;
    int end = start + chunk_size;

    if(rank == number_of_processes - 1) {
        end = n;
    }

    int res = prefix_scan(arr, start, end);
    MPI_Reduce(&res, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if(rank == 0) {
        printf("%d\n", sum);
    }

    MPI_Finalize();
    exit(0);
}
