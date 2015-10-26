all: heap.o
	g++ main.cpp heap.o -o lab7
	make clean

heap.o: heap.h
	g++ -c heap.cpp

test:
	make all
	./lab7

clean:
	rm -f Lindsey_Lab07.tar.gz
	rm -f -r ./Lindsey_Lab07
	rm -f heap.o

clean-all:
	make clean
	rm -f ./lab7

tar:
	make all
	make clean
	mkdir ./Lindsey_Lab07
	cp main.cpp heap.cpp heap.h Makefile data.txt lab7 ./Lindsey_Lab07
	tar -cvzf Lindsey_Lab07.tar.gz Lindsey_Lab07
	rm -r ./Lindsey_Lab07
