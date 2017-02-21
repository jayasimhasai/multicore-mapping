make omp

#echo "Utilizing 20 Threads"

ssh mic0 'export KMP_AFFINITY="scattered,granularity=fine"; \
	export KMP_PLACE_THREADS=20c,1t,0o; \
	export OMP_NUM_THREADS=20; \'
	#cd /gpfs/stfc/local/HCPhi005/ddr01/gxc30-ddr01/herc_demo; \
	#export LD_LIBRARY_PATH=/gpfs/stfc/local/systems/sja01/ljj24-sja01/testjob/intel/#clck/2.2.1.003/share/mic/:$LD_LIBRARY_PATH; \
#	./demo.x'
