all: list.o
	g++ main.cpp list.o -o lab2
	make clean

list.o: list.h
	g++ -c list.cpp

test: 
	make all
	./lab1

clean:
	rm -f Lindsey_Lab02.tar.gz
	rm -f -r ./Lindsey_Lab02
	rm -f list.o
    
clean-all:
	make clean
	rm -f ./lab2

tar:
	make all
	make clean
	mkdir ./Lindsey_Lab02
	cp main.cpp list.cpp list.h Makefile data.txt lab2 ./Lindsey_Lab02
	tar -cvzf Lindsey_Lab02.tar.gz Lindsey_Lab02
	rm -r ./Lindsey_Lab02
