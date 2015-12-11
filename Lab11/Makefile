CC = g++
CFLAGS = -Wall -c -g
LDFLAGS =

LAB = graph
OBJ = $(LAB).o main.o


all: $(OBJ)
	$(CC) $(LDFLAGS)  main.o $(LAB).o -o lab11
	make clean

main.o: main.cpp $(LAB).h
	$(CC) $(CFLAGS) $(LDFLAGS) main.cpp

$(LAB).o: $(LAB).cpp $(LAB).h
	$(CC) $(CFLAGS) $(LDFLAGS) $(LAB).cpp


test:
	make all
	./lab11

clean:
	rm -f Lindsey_Lab11.tar.gz
	rm -f -r ./Lindsey_Lab11
	rm -f $(OBJ)

clean-all:
	make clean
	rm -f ./lab11

tar:
	make all
	make clean
	mkdir ./Lindsey_Lab11
	cp main.cpp $(LAB).cpp $(LAB).h Makefile data1.txt data2.txt lab11 Report_Lindsey_Lab11.pdf Report_Lindsey_Lab11.tex ./Lindsey_Lab11
	tar -cvzf Lindsey_Lab11.tar.gz Lindsey_Lab11
	rm -r ./Lindsey_Lab11
