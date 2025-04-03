all: clean tads exec run

tads:
	g++ -Wall -c ./src/BinaryTree.cpp -I ./include/ -o ./obj/BinaryTree.o

exec:
	g++ -Wall ./apps/main.cpp ./obj/BinaryTree.o -I ./include/ -o ./bin/main

run: 
	./bin/main

clean:
	rm -rf ./bin/main
	rm -rf ./obj/BinaryTree.o
