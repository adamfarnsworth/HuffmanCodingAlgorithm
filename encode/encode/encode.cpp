#include <iostream>			// std::cout
#include <fstream>			// std::ifstream
#include <string>			// getine
#include <unordered_map>	// std::unordered_map
#include <bitset>			// std::bitset

std::ifstream huffmanTable;
/*
finds position of \t or ' '

input: string with form value_____freq
return: position of whitespace
*/
int tabOrSpace(std::string value) {
	return(value.find(' ') < value.find('\t')) ? value.find(' ') : value.find('\t');
}

int main(int argc, char *argv[]) {
	std::bitset<8> bits8;
	char a = ' ';
	int bitCount = 7;
	//bits8[1] = 1;    // 00000010
	
	// Declaring hashT to be of <char, int> type
	// key will be of char type and mapped value will
	// be of string type
	std::unordered_map<int, std::string> huffT;
	
	huffmanTable.open(argv[1]);

	
	int value;
	std::string hCode;
	std::string line;
	/* Reading line by line from Huffman table
	storing the values and encoding into a
	local hashtable*/
	while (getline(huffmanTable, line))
	{
		std::size_t pos = tabOrSpace(line);
		hCode = line.substr(pos + 1);
		value = stoi(line.substr(0, pos));
		huffT[value] = hCode;
	}
	huffmanTable.close();

	//reading input character by character
	while (std::cin.get(a) && a != EOF) {

		// loading char into byte(s)
		for (unsigned int i = 0; i < huffT.at(a).length(); i++) {
			if (bitCount == -1) {
				std::cout << bits8<< std::endl;
				bitCount = 7;
			}
			bits8[bitCount] = huffT.at(a).at(i) - 48;		// - 48 is to convert char to int
			bitCount--;
		}
	}

	// loading "EOF" into byte(s)
	for (unsigned int i = 0; i < huffT.at(0).length(); i++) {
		if (bitCount == -1) {
			std::cout << bits8 << std::endl;
			bitCount = 7;
			bits8.reset();
		}
		bits8[bitCount] = huffT.at(0).at(i) -48 ;		// - 48 is to convert char to int
		bitCount--;
	}
	// there will be trailing 0's after insertion of "EOF"
	if(bitCount != 7)
		std::cout << bits8 << std::endl;


	//system("pause");
}