#include <iostream>
#include <string>
#include <functional>
#include <queue>

struct node {
	int freq;
	std::string value;

	node* left;
	node* right;

	bool operator<(const node& rhs) const
	{
		return freq < rhs.freq;
	}
};

/*
finds position of \t or ' '

input: string with form value_____freq
return: position of whitespace
*/
int tabOrSpace(std::string value) {
	return(value.find(' ') < value.find('\t')) ? value.find(' ') : value.find('\t');
}

void printValues(node* root, std::string bits) {
	if (root->value != "") {
		std::cout << root->value << "\t" << bits << std::endl;
		return;
	}
	printValues(root->left, bits + "0");
	printValues(root->right, bits + "1");
}

int main() {
	std::string freq;
	std::priority_queue<node*> pq;
	
	// loading input into min heap
	while (getline(std::cin, freq) && freq.size() > 0) {
		node* currentValue = new node();
		std::size_t pos = tabOrSpace(freq);
		currentValue->value = freq.substr(0,pos);
		currentValue->freq = std::stoi(freq.substr(pos + 1));
		pq.push(currentValue);
	}

	node* left;
	node* right;
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

	printValues(pq.top(), "");
	system("pause");
}