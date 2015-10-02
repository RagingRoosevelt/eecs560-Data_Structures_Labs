all: bst.o
	g++ main.cpp bst.o -o lab3
	make clean

bst.o: bst.h
	g++ -c bst.cpp

test:
	make all
	./lab3

clean:
	rm -f Lindsey_Lab03.tar.gz
	rm -f -r ./Lindsey_Lab03
	rm -f bst.o

clean-all:
	make clean
	rm -f ./lab3

tar:
	make all
	make clean
	mkdir ./Lindsey_Lab03
	cp main.cpp bst.cpp bst.h Makefile data.txt lab3 ./Lindsey_Lab03
	tar -cvzf Lindsey_Lab03.tar.gz Lindsey_Lab03
	rm -r ./Lindsey_Lab03
