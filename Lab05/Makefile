all: bst.o
	g++ main.cpp bst.o -o lab5
	make clean

bst.o: bst.h
	g++ -c bst.cpp

test:
	make all
	./lab5

clean:
	rm -f Lindsey_Lab05.tar.gz
	rm -f -r ./Lindsey_Lab05
	rm -f bst.o

clean-all:
	make clean
	rm -f ./lab5

tar:
	make all
	make clean
	mkdir ./Lindsey_Lab05
	cp main.cpp bst.cpp bst.h Makefile data.txt lab5 ./Lindsey_Lab05
	tar -cvzf Lindsey_Lab05.tar.gz Lindsey_Lab05
	rm -r ./Lindsey_Lab05
