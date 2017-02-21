make mpi

echo "Utilizing $1 Ranks"
mpirun -np $1 -genvall -host mic0 /gpfs/stfc/local/HCPhi005/ddr01/gxc30-ddr01/herc_demo/demo.x
