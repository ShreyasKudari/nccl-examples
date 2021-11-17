#! /bin/sh
mpirun -N 4 -hostfile hostfilebkg ./mpi_allreduce &
sleep 1
mpirun -N 4 -hostfile hostfile /scratch/08105/shrey_k/nccl-tests/build/all_reduce_perf -b 8 -e 128M -f 2 -g 1

