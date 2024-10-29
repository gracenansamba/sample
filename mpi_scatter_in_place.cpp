#include <mpi.h>
#include <stdio.h>
#include <cstdlib>

int main(int argc, char **argv) {
    int rank, size;
    
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int recv_data;

    int *sendbuf = NULL;
    if (rank == 0) {
        sendbuf = (int *)malloc(size * sizeof(int));
        for (int i = 0; i < size; i++) {
            sendbuf[i] = i + 1; 
        }
    }

    if (rank == 0) {
        recv_data = sendbuf[0];
        MPI_Scatter(sendbuf, 1, MPI_INT, MPI_IN_PLACE, 1, MPI_INT, 0, MPI_COMM_WORLD);
    } else {
        MPI_Scatter(sendbuf, 1, MPI_INT, &recv_data, 1, MPI_INT, 0, MPI_COMM_WORLD);
    }

    printf("Process %d received data: %d\n", rank, recv_data);

    if (rank == 0) {
        free(sendbuf);
    }

    MPI_Finalize();
    return 0;
}

