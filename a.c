#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <mpi.h>

const int SORT_ORDER_ASC = 1;
const int SORT_ORDER_DESC = 0;

void rng(int* arr, int n);

void bitonic_sort(int* array, int n, int order);

void bitonic_sort_rec(int* arr, int n, int proc_start, int proc_n, int order);
void merge_bitonic_seq_rec(int* arr, int n, int proc_start, int proc_n, int order);

int world_rank, world_size;

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    int n = 262144;
    int* array = (int*) malloc(n * sizeof(array));
    rng(array, n);

    struct timeval start_time, end_time, result_time;
    
    gettimeofday(&start_time, NULL);
    bitonic_sort(array, n, SORT_ORDER_ASC);
    gettimeofday(&end_time, NULL);

    timersub(&end_time, &start_time, &result_time);
    long long result_ms = result_time.tv_sec * 1000000LL + result_time.tv_usec;

    if (world_rank == 0) {
        char success = 1;
        int i;
        for (i = 1; i < n && success; i++)
            if (array[i] < array[i-1])
                success = 0;
        if (success)
            printf("sorting done successfully in %lld ms\n", result_ms);
        else {
            printf("error: array[%d] < array[%d]\n", i, i-1);
            printf("your array: [%d", array[0]);
            for (int i = 1; i < n; i++)
                printf(", %d", array[i]);
            printf("]\n");
        }
    }

    MPI_Finalize();
    return 0;
}

void bitonic_sort(int* array, int n, int order) {
    bitonic_sort_rec(array, n, 0, world_size, order);
}

void bitonic_sort_rec(int* arr, int n, int proc_start, int proc_n, int order) {
    if (n > 1) {
        if (proc_n > 1) {
            if (world_rank < proc_start + proc_n/2) {
                bitonic_sort_rec(arr, n/2, proc_start, proc_n / 2, SORT_ORDER_ASC);
                MPI_Recv(arr + n/2, n/2, MPI_INT, world_rank + proc_n / 2, 2, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                MPI_Send(arr, n/2, MPI_INT, world_rank + proc_n / 2, 2, MPI_COMM_WORLD);
            } else {
                bitonic_sort_rec(arr + n/2, n/2, proc_start + proc_n/2, proc_n / 2, SORT_ORDER_DESC);
                MPI_Send(arr + n/2, n/2, MPI_INT, world_rank - proc_n / 2, 2, MPI_COMM_WORLD);
                MPI_Recv(arr, n/2, MPI_INT, world_rank - proc_n / 2, 2, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            }
        } else {
            bitonic_sort_rec(arr, n/2, proc_start, 0, SORT_ORDER_ASC);
            bitonic_sort_rec(arr + n/2, n/2, proc_start, 0, SORT_ORDER_DESC);
        }
        merge_bitonic_seq_rec(arr, n, proc_start, proc_n, order);
    }
}

void merge_bitonic_seq_rec(int* arr, int n, int proc_start, int proc_n, int order) {
    if (n > 1) {
        for (int i = 0; i < n/2; i++)
            if ((arr[i] > arr[i + n/2] ? 1 : 0) == order) {
                int tmp = arr[i];
                arr[i] = arr[i + n/2];
                arr[i + n/2] = tmp;
            }

        if (proc_n > 1) {
            if (world_rank < proc_start + proc_n/2) {
                merge_bitonic_seq_rec(arr, n/2, proc_start, proc_n / 2, order);
                MPI_Recv(arr + n/2, n/2, MPI_INT, world_rank + proc_n / 2, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                MPI_Send(arr, n/2, MPI_INT, world_rank + proc_n / 2, 1, MPI_COMM_WORLD);
            } else {
                merge_bitonic_seq_rec(arr + n/2, n/2, proc_start + proc_n / 2, proc_n / 2, order);
                MPI_Send(arr + n/2, n/2, MPI_INT, world_rank - proc_n / 2, 1, MPI_COMM_WORLD);
                MPI_Recv(arr, n/2, MPI_INT, world_rank - proc_n / 2, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            }
        } else {
            merge_bitonic_seq_rec(arr, n/2, proc_start, 0, order);
            merge_bitonic_seq_rec(arr + n/2, n/2, proc_start, 0, order);
        }
    }
}

void rng(int* arr, int n) {
    srand(13515049);
    for (int i = 0; i < n; i++)
        arr[i] = rand();
}
