#include <mpi.h>
#include <stdio.h>
#include <cstdlib>

int main(int argc, char **argv) {
    int rank, size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int send_count = rank + 1;
    int *sendbuf = (int *)malloc(send_count * sizeof(int));
    for (int i = 0; i < send_count; i++) {
        sendbuf[i] = rank + 1;  
    }

    int *recv_counts = NULL;
    int *displs = NULL;
    int total_recv_count = (size * (size + 1)) / 2;  
    int *recvbuf = NULL;
    if (rank == 0) {
        recv_counts = (int *)malloc(size * sizeof(int));
        displs = (int *)malloc(size * sizeof(int));
        recvbuf = (int *)calloc(total_recv_count, sizeof(int)); 

        int displacement = 0;
        for (int i = 0; i < size; i++) {
            recv_counts[i] = i + 1;
            displs[i] = displacement;
            displacement += recv_counts[i];
        }
        
        for (int i = 0; i < recv_counts[0]; i++) {
            recvbuf[displs[0] + i] = rank + 1;  
        }
    }

    if (rank == 0) {
        MPI_Gatherv(MPI_IN_PLACE, 0, MPI_DATATYPE_NULL, recvbuf, recv_counts, displs, MPI_INT, 0, MPI_COMM_WORLD);
    } else {
        MPI_Gatherv(sendbuf, send_count, MPI_INT, NULL, NULL, NULL, MPI_INT, 0, MPI_COMM_WORLD);
    }

    if (rank == 0) {
        printf("Root process gathered data:\n");
        for (int i = 0; i < total_recv_count; i++) {
            printf("%d ", recvbuf[i]);
        }
        printf("\n");
    }

    free(sendbuf);
    if (rank == 0) {
        free(recv_counts);
        free(displs);
        free(recvbuf);
    }

    MPI_Finalize();
    return 0;
}

