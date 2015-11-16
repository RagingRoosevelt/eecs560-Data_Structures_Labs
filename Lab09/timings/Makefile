all: heap_leftist.o heap_skew.o
	g++ main.cpp heap_leftist.o heap_skew.o -o lab9
	make clean

heap_leftist.o: heap_leftist.h
	g++ -c heap_leftist.cpp

heap_skew.o: heap_skew.h
	g++ -c heap_skew.cpp

test:
	make all
	./lab9

clean:
	rm -f Lindsey_Lab09.tar.gz
	rm -f -r ./Lindsey_Lab09
	rm -f heap_leftist.o
	rm -f heap_skew.o

clean-all:
	make clean
	rm -f ./lab9

tar:
	make all
	make clean
	mkdir ./Lindsey_Lab09
	cp main.cpp heap_leftist.cpp heap_leftist.h heap_skew.h heap_skew.cpp Makefile lab9 ./Lindsey_Lab09
	tar -cvzf Lindsey_Lab09.tar.gz Lindsey_Lab09
	rm -r ./Lindsey_Lab09
