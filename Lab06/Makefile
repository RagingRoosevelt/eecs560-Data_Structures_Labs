all: hash_open.o hash_chain.o timer.h
	g++ main.cpp hash_chain.o hash_open.o -o lab6
	make clean

hash_open.o: hash_open.h
	g++ -c hash_open.cpp

hash_chain.o: hash_chain.h
	g++ -c hash_chain.cpp

test:
	make all
	./lab6

clean:
	rm -f Lindsey_Lab06.tar.gz
	rm -f -r ./Lindsey_Lab06
	rm -f hash_open.o
	rm -f hash_chain.o

clean-all:
	make clean
	rm -f ./lab6

tar:
	make all
	make clean
	mkdir ./Lindsey_Lab06
	cp main.cpp hash_open.cpp hash_open.h hash_chain.cpp hash_chain.h timer.h Makefile lab6 ./Lindsey_Lab06
	tar -cvzf Lindsey_Lab06.tar.gz Lindsey_Lab06
	rm -r ./Lindsey_Lab06
