#variables
FLAGS=-std=c++11 -c

all: main

main: huffman.o frequencies.o encode.o decode.o
	g++ -o frequencies frequencies.o 
	g++ -o huffman huffman.o
	g++ -o encode encode.o
	g++ -o decode decode.o

huffman.o: huffman.cpp
	g++ $(FLAGS) huffman.cpp

frequencies.o: frequencies.cpp
	g++ $(FLAGS) frequencies.cpp
	
encode.o: encode.cpp
	g++ $(FLAGS) encode.cpp
	
decode.o: decode.cpp
	g++ $(FLAGS) decode.cpp	

clean:
	rm -rf *.o main *~ output.txt codewords.txt encoded.txt decoded.txt frequencies huffman encode decode
	
runFrequencies:
	cat sample.txt | ./frequencies
	
runHuffman:
	cat sample.txt | ./frequencies | ./huffman
	
runEncode:
	cat sample.txt | ./encode codewords.txt >> encoded.txt
	
runDecode:
	cat encoded.txt | ./decode codewords.txt >> decoded.txt	
	
runAll:
	make runHuffman
	make runEncode
	make runDecode