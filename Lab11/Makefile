CC = g++
CFLAGS = -Wall -c -g
LDFLAGS =

LAB = graph
OBJ = $(LAB).o main.o


all: $(OBJ)
	$(CC) $(LDFLAGS)  main.o $(LAB).o -o lab10
	make clean

main.o: main.cpp $(LAB).h
	$(CC) $(CFLAGS) $(LDFLAGS) main.cpp

$(LAB).o: $(LAB).cpp $(LAB).h
	$(CC) $(CFLAGS) $(LDFLAGS) $(LAB).cpp


test:
	make all
	./lab10

clean:
	rm -f Lindsey_Lab10.tar.gz
	rm -f -r ./Lindsey_Lab10
	rm -f $(OBJ)

clean-all:
	make clean
	rm -f ./lab10

tar:
	make all
	make clean
	mkdir ./Lindsey_Lab10
	cp main.cpp $(LAB).cpp $(LAB).h Makefile data.txt lab10 ./Lindsey_Lab10
	tar -cvzf Lindsey_Lab10.tar.gz Lindsey_Lab10
	rm -r ./Lindsey_Lab10
