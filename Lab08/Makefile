all: heap.o
	g++ main.cpp heap.o -o lab8
	make clean

heap.o: heap.h
	g++ -c heap.cpp

test:
	make all
	./lab8

clean:
	rm -f Lindsey_Lab08.tar.gz
	rm -f -r ./Lindsey_Lab08
	rm -f heap.o

clean-all:
	make clean
	rm -f ./lab8

tar:
	make all
	make clean
	mkdir ./Lindsey_Lab08
	cp main.cpp heap.cpp heap.h Makefile data.txt lab8 ./Lindsey_Lab08
	tar -cvzf Lindsey_Lab08.tar.gz Lindsey_Lab08
	rm -r ./Lindsey_Lab08
