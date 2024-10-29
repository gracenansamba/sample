#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int rank, size;
    const int root = 0;
    int sendbuf;         
    int *recvbuf = NULL; 

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    sendbuf = rank;

    if (rank == root) {
        recvbuf = (int *)malloc(size * sizeof(int));
        recvbuf[rank] = rank; 
    }

    if (rank == root) {
        MPI_Gather(MPI_IN_PLACE, 1, MPI_INT, recvbuf, 1, MPI_INT, root, MPI_COMM_WORLD);
    } else {
        MPI_Gather(&sendbuf, 1, MPI_INT, recvbuf, 1, MPI_INT, root, MPI_COMM_WORLD);
    }

    if (rank == root) {
        printf("Root process gathered data:\n");
        for (int i = 0; i < size; i++) {
            printf("%d ", recvbuf[i]);
        }
        printf("\n");
        free(recvbuf); 
    }

    MPI_Finalize();

    return 0;
}

