mkdir -p ./outmain
gcc ./main.c -o ./main.exe -lm

for i in ./input/*; do 
    ./main.exe < $i > ./outmain/$(basename $i);
done

diff -w ./output ./outmain