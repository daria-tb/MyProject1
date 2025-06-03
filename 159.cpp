#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <array>
#include <stack>
#include <queue>

int main() 
{
	std::priority_queue<int> queue;
	queue.push(100);
	queue.push(20);
	queue.push(80);
	queue.push(50);

	while (!queue.empty()) 
	{
		std::cout << queue.top() << "  ";
		queue.pop();
	}
	std::cout << std::endl;
	std::priority_queue<int, std::vector<int>, std::greater<int>> queue2;
	queue2.push(100);
	queue2.push(20);
	queue2.push(80);
	queue2.push(50);
	while (!queue2.empty())
	{
		std::cout << queue2.top() << "  ";
		queue2.pop();
	}
	std::cout << std::endl;


	return 0;
}