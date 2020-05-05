gcc -c ./list.c ./test/*.c
gcc -o ./bin/$1 ./*.o
./bin/$1
rm -rf ./*.o  