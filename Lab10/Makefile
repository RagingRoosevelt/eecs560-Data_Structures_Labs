CC = g++
CFLAGS = -Wall -c -g
LDFLAGS = 

OBJ = binom_queue.o main.o


all: $(OBJ)
	$(CC) $(LDFLAGS)  main.o binom_queue.o -o lab10
	make clean
	
main.o: main.cpp binom_queue.h
	$(CC) $(CFLAGS) $(LDFLAGS) main.cpp
	
binom_queue.o: binom_queue.cpp binom_queue.h
	$(CC) $(CFLAGS) $(LDFLAGS) binom_queue.cpp


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
	cp main.cpp binom_queue.cpp binom_queue.h Makefile data.txt lab10 ./Lindsey_Lab10
	tar -cvzf Lindsey_Lab10.tar.gz Lindsey_Lab10
	rm -r ./Lindsey_Lab10
