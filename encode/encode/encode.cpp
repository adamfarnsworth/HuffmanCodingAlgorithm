#include <iostream>	// std::cout
#include <fstream>	// std::ifstream
#include <string>	// getine
#include <unordered_map>
std::ifstream myfile;

/*
finds position of \t or ' '

input: string with form value_____freq
return: position of whitespace
*/
int tabOrSpace(std::string value) {
	return(value.find(' ') < value.find('\t')) ? value.find(' ') : value.find('\t');
}

int main(int argc, char *argv[]) {
	// Declaring hashT to be of <char, int> type
	// key will be of char type and mapped value will
	// be of string type
	std::unordered_map<int, std::string> hashT;
	
	myfile.open(argv[1]);
	
	int value;
	std::string hCode;
	std::string line;
	/* Reading line by line from Huffman table
	storing the values and encoding into a
	local hashtable*/
	while (getline(myfile, line))
	{
		std::size_t pos = tabOrSpace(line);
		hCode = line.substr(pos + 1);
		value = stoi(line.substr(0, pos));
		hashT[value] = hCode;
	}

	myfile.close();
	system("pause");
}