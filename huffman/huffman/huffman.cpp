#include <iostream>		// std::cout
#include <string>		// getline()
#include <functional>	// std::priority_queue
#include <queue>		// std::priority_queue
#include <fstream>		// std::ofstream

int fileSize = 0;
std::ofstream myfile;

struct node {
	int freq;
	int value;

	node* left;
	node* right;
};

/*
finds position of \t or ' '

input: string with form value_____freq
return: position of whitespace
*/
int tabOrSpace(std::string value) {
	return(value.find(' ') < value.find('\t')) ? value.find(' ') : value.find('\t');
}

/*
traverse and prints out tree

input: root of tree, and bits for the character
return: Prints data recursivly
*/
void printValues(node* root, std::string bits) {
	if (root == NULL)
		return;
	printValues(root->left, bits + "0");
	if (root->value != 0) {
		myfile << root->value << "\t" << bits << std::endl;
		fileSize = bits.size()*root->freq;
	}
	printValues(root->right, bits + "1");
}

/*
overloading the compare for priority queue
*/
struct CompareNode : public std::binary_function<node*, node*, bool>
{

	bool operator()(const node* lhs, const node* rhs) const
	{

		return lhs->freq > rhs->freq;
	}
};

int main() {
	std::string freq;
	//std::priority_queue<node> pq;
	std::priority_queue<node*, std::vector<node*>, CompareNode> pq;

	node* nullChar = new node();
	nullChar->freq = 0;
	nullChar->value = EOF;
	pq.push(nullChar);

	// loading input into min heap
	while (getline(std::cin, freq) && freq.size() > 0) {
		node* currentValue = new node();
		std::size_t pos = tabOrSpace(freq);
		currentValue->value = stoi(freq.substr(0, pos));
		currentValue->freq = stoi(freq.substr(pos + 1));
		pq.push(currentValue);
	}

	// creating tree
	while (pq.size() > 1) {
		node* parent = new node();
		parent->right = pq.top();
		pq.pop();
		parent->left = pq.top();
		pq.pop();
		parent->freq = parent->left->freq + parent->right->freq;
		pq.push(parent);
	}

	// printing tree
	myfile.open("codewords.txt");
	printValues(pq.top(), "");
	myfile.close();
	std::cout << "file size = " << fileSize << " bits" << std::endl;
	system("pause");
}