all: hash.o
	g++ main.cpp hash.o -o lab3
	make clean

hash.o: hash.h
	g++ -c hash.cpp

test:
	make all
	./lab3

clean:
	rm -f Lindsey_Lab03.tar.gz
	rm -f -r ./Lindsey_Lab03
	rm -f hash.o

clean-all:
	make clean
	rm -f ./lab3

tar:
	make all
	make clean
	mkdir ./Lindsey_Lab03
	cp main.cpp hash.cpp hash.h Makefile data.txt lab3 ./Lindsey_Lab03
	tar -cvzf Lindsey_Lab03.tar.gz Lindsey_Lab03
	rm -r ./Lindsey_Lab03
