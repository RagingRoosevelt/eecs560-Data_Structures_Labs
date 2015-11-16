all: heap_skew.o
	g++ main.cpp heap_skew.o -o lab9
	make clean

heap_skew.o: heap_skew.h
	g++ -c heap_skew.cpp

test:
	make all
	./lab9

clean:
	rm -f Lindsey_Lab09.tar.gz
	rm -f -r ./Lindsey_Lab09
	rm -f heap_skew.o

clean-all:
	make clean
	rm -f ./lab9

tar:
	make all
	make clean
	mkdir ./Lindsey_Lab09
	cp main.cpp heap_skew.cpp heap_skew.h Makefile data.txt lab9 ./Lindsey_Lab09
	tar -cvzf Lindsey_Lab09.tar.gz Lindsey_Lab09
	rm -r ./Lindsey_Lab09
