#variables
FLAGS=-std=c++11 -c

all: main

main: huffman.o frequencies.o
	g++ -o frequencies frequencies.o 
	g++ -o huffman huffman.o

huffman.o: huffman.cpp
	g++ $(FLAGS) huffman.cpp

frequencies.o: frequencies.cpp
	g++ $(FLAGS) frequencies.cpp

clean:
	rm -rf *o main *~ output.txt
	
catfile:
	cat sample.txt | ./frequencies | ./huffman
