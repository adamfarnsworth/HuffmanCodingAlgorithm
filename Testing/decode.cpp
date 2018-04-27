#include <iostream>			// std::cout
#include <bitset>			// std::bitset
#include <unordered_map>	// std::unordered_map
#include <fstream>			// std::ifstream

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
	char a = ' ';
	std::bitset<8> bits8;
	// huffT format: {huffmanCode, character @ encoding}
	// ex) {11001, 97} represents 11001 gives the char 'a'
	std::unordered_map<std::string, int> huffT;

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
		huffT[hCode] = value;
	}
	huffmanTable.close();
	int byteCount = 7;
	std::string bitString = "";
	//reading input character by character
	while (std::cin.get(a) && a != EOF) {
		// making char readable as binary
		bits8 = a;

		// itterating though current byte
		for (int i = 7; i >= 0; i--) {
			bitString.append(std::to_string(bits8[i]));

			// checks if bitString exists in Huffman Table
			if (huffT.find(bitString) != huffT.end()) {
				// checking for EOF
				if (huffT.at(bitString) == 32000)
					break;
				std::cout << (char) huffT.at(bitString);
				bitString = "";
			}
		}
	}



	//system("pause");
}