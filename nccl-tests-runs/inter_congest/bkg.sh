#!/bin/sh
while $true
LD_LIBRARY_PATH=$SCRATCH/nccl/build/lib:$LD_LIBRARY_PATH
do
nohup mpirun -N 4 -hostfile hostfile /scratch/08105/shrey_k/nccl-tests/build/all_reduce_perf -b 8 -e 128M -f 2 -g 1
done

