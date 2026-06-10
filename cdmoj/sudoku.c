#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <math.h>

typedef struct indexes {
    int row_start;
    int row_end;
    int col_start;
    int col_end;
} indexes;

void calculate_indexes(indexes* arr, int n) {
    int step = (int) sqrt(n);
    int count = -1;
    for(int i = 0; i < n; i++) {
        int x = i % step;

        if(x == 0) {
            count++;
        }

        int row_start = count * step;
        int row_end = count * step + step;

        int col_start = x * step;
        int col_end = x * step + step;


        arr[i].row_start = row_start;
        arr[i].row_end = row_end;
        arr[i].col_start = col_start;
        arr[i].col_end = col_end;
    }
}

int check_row(int** sudoku, int n, int row_index) {
    int check[n];
    for(int i = 0; i < n; i++) check[i] = 0;

    for(int i = 0; i < n; i++) {
        int pos = sudoku[row_index][i];
        check[pos]++;
        if(check[pos] > 1) return 0;
    }

    return 1;

}

int check_col(int** sudoku, int n, int col_index) {
    int check[n];
    for(int i = 0; i < n; i++) check[i] = 0;

    for(int i = 0; i < n; i++) {
        int pos = sudoku[i][col_index];
        check[pos]++;
        if(check[pos] > 1) return 0;
    }

    return 1;
}

int check_block(int** sudoku, int n, indexes* indexes) {
    int local_sum = 0;
    
    int check[n];
    for(int i = 0; i < n; i++) check[i] = 0;

    int row_start = indexes->row_start;
    int row_end = indexes->row_end;
    int col_start = indexes->col_start;
    int col_end = indexes->col_end;


    for(int i = row_start; i < row_end; i++) {
        for(int j = col_start; j < col_end; j++) {
            int pos = sudoku[i][j];
            check[pos]++;
            if(check[pos] > 1) {
                return 0;
            }
        }
    }

    return 1;

}


void shutdown(int ok) {
    if(ok == 0) {
        printf("Invalido\n");
    }

    if(ok == 1) {
        printf("Valido\n");
    }

    exit(0);
}

int main() {
    int n = 0;
    scanf("%d", &n);

    indexes arr[n];
    calculate_indexes(arr, n);
    int** sudoku = malloc(sizeof(int) * n);

    int target_sum = 0; 
    int block_size = (int) sqrt(n);

    for(int i = 1; i <= n; i++) {
        target_sum += i;
    }

    sudoku[0] = malloc(sizeof(int) * n);

    for(int i = 0 ; i < n; i++) {
        sudoku[i] = malloc(sizeof(int) * n);
        for(int j = 0; j < n; j++) {
            int x = 0;
            scanf("%d", &x);
            x--;
            sudoku[i][j] = x;
        }
    }

    int ok = 1;

    #pragma omp parallel for
    for(int i = 0; i < n; i++) {
        if(check_row(sudoku, n, i) == 0) {
            ok = 0;
        }
    }

    if(ok == 0) 
        shutdown(ok);

    #pragma omp parallel for
    for(int i = 0; i < n; i++) {
        if(check_col(sudoku, n, i) == 0) {
            ok = 0;
        }
    }

    if(ok == 0) 
        shutdown(ok);

    #pragma omp parallel for
    for(int i = 0; i < n; i++) {
        if(check_block(sudoku, n, &arr[i]) == 0) {
            ok = 0;
        }
    }


    shutdown(ok);
    return 0;
}
