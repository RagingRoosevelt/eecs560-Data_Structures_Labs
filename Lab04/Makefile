all: hash.o
	g++ main.cpp hash.o -o lab4
	make clean

hash.o: hash.h
	g++ -c hash.cpp

test:
	make all
	./lab4

clean:
	rm -f Lindsey_Lab04.tar.gz
	rm -f -r ./Lindsey_Lab04
	rm -f hash.o

clean-all:
	make clean
	rm -f ./lab4

tar:
	make all
	make clean
	mkdir ./Lindsey_Lab04
	cp main.cpp hash.cpp hash.h Makefile data.txt lab4 ./Lindsey_Lab04
	tar -cvzf Lindsey_Lab04.tar.gz Lindsey_Lab04
	rm -r ./Lindsey_Lab04
