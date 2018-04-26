#include <functional>
#include <queue>
#include <iostream>


int main() {

	// Creates a max heap
	std::priority_queue <int, std::vector<int>, std::greater<int> > pq;


	// 1 byte input
	char a = ' ';
	unsigned int count = 0;


	//reading input character by character
	while (std::cin.get(a)) {
		pq.push(a);
	}

	int current = 0;
	int previous = 0;
	// if statement protects against nothing being entered
	if (!pq.empty())
		previous = pq.top();

	// One by one extract items from max heap
	while (pq.empty() == false)
	{
		current = pq.top();

		if (current == previous)
			count++;

		if (current != previous) {
			std::cout << previous << "\t" << count << std::endl;
			count = 1;
		}

		previous = current;
		pq.pop();
	}
	std::cout << previous << "\t" << count << std::endl;

	system("pause");
}