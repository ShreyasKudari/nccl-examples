#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>
int main(int argc, char **argv){
    MPI_Init(&argc, &argv);
    int my_rank, total_ranks;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &total_ranks);
    printf("Process %i out of %i \n",my_rank,total_ranks);
    int *buffer = (int *)malloc(sizeof(int)*32*1024*1024);
    int count = 32*1024*1024;
    //memset(buffer, 1, count);
    int *reduced_buffer =(int *)malloc(sizeof(int)*32*1024*1024);//32MB
	for(int i=0;i<500;i++){
    int ierr = MPI_Allreduce(buffer, reduced_buffer, count, MPI_INT, MPI_SUM,
              MPI_COMM_WORLD);
	}
    // printf("%i",ierr); 
    //printf("%i \n",reduced_buffer[0]);
    
    free(buffer);
    free(reduced_buffer);

    MPI_Finalize();

    
    return 0;
}
