micinfo

micsmc -a

#echo "All Relevant Information"
#ssh mic0 'cat /proc/cpuinfo'

echo "Clock"
ssh mic0 'cat /proc/cpuinfo | grep "cpu MHz" | uniq'

echo "Number of Processors in the System"
ssh mic0 'cat /proc/cpuinfo | grep "cpu cores" | uniq'

echo "Maximum Number of Threads in the System"
ssh mic0 'cat /proc/cpuinfo | grep "siblings" | uniq'
