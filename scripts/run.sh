gcc -c ./src/*.c
gcc -o ./bin/$1 ./*.o
./bin/$1
rm -rf ./*.o  