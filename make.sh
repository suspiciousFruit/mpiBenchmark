> results/res_8Mb.txt

for ((i=1; i < 10; i++))
do
    srun -N 2 ./a.out 8 >> ./results/res_8Mb.txt
done