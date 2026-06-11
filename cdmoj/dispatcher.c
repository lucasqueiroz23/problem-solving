#include <stdlib.h>
#include <stdio.h>
#include "mpi.h"

int main(int argc, char** argv) {
    const int root = 0;
    int ret = MPI_Init(&argc, &argv);
    MPI_Status status;
    if(ret != MPI_SUCCESS) {
        MPI_Abort(MPI_COMM_WORLD, ret);
    }

    int rank = 0; 
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int num_procs = 0;
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

    int n = 0;

    if(rank == root) {
        scanf("%d", &n);
        MPI_Bcast(&n, 1, MPI_INT, root, MPI_COMM_WORLD);
        int seeds[n];

        for(int i = 0; i < 3; i++){
            int x = 0;
            scanf("%d", &x);
            seeds[i] = x;
        }

        for(int i = 1; i < num_procs; i++) {
            MPI_Send(&seeds[i-1], 1, MPI_INT, i, 0, MPI_COMM_WORLD);
        }
    } else {
        int arr_size = 0;
        int seed = 0;

        MPI_Bcast(&arr_size, 1, MPI_INT, root, MPI_COMM_WORLD);
        int arr[arr_size]; 

        MPI_Recv(&seed, 1, MPI_INT, root, 0, MPI_COMM_WORLD, &status);
        srand(seed);
        int sum = 0;
        for(int i = 0; i < arr_size; i++) {
            arr[i] = rand() % 100;
            sum += arr[i];
        }

        printf("%d\n", sum);
    }
    exit(0);
}
