all: tree.o
	g++ main.cpp tree.o -o lab2
	make clean

tree.o: tree.h
	g++ -c tree.cpp

test:
	make all
	./lab2

clean:
	rm -f Lindsey_Lab02.tar.gz
	rm -f -r ./Lindsey_Lab02
	rm -f tree.o

clean-all:
	make clean
	rm -f ./lab2

tar:
	make all
	make clean
	mkdir ./Lindsey_Lab02
	cp main.cpp tree.cpp tree.h Makefile data.txt lab2 ./Lindsey_Lab02
	tar -cvzf Lindsey_Lab02.tar.gz Lindsey_Lab02
	rm -r ./Lindsey_Lab02
