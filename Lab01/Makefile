all: list.o
	g++ main.cpp list.o -o lab1
	make clean

list.o: list.h
	g++ -c list.cpp

test: 
	make all
	./lab1

clean:
	rm -f Lindsey_Lab01.tar.gz
	rm -f -r ./Lindsey_Lab01
	rm -f list.o
    
clean-all:
	make clean
	rm -f ./lab1

tar:
	make all
	make clean
	mkdir ./Lindsey_Lab01
	cp main.cpp list.cpp list.h Makefile data.txt lab1 ./Lindsey_Lab01
	tar -cvzf Lindsey_Lab01.tar.gz Lindsey_Lab01
	rm -r ./Lindsey_Lab01