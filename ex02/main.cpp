#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	MutantStack<int> mstack;
	mstack.push(1);
	mstack.push(17);
	std::cout << "Test 1 (TOP):" << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Test 2(pop):" << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "Test 3 (iteration test):"<< std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "Test 4 other type container"<< std::endl;
	std::list<int> mlist;
	mlist.push_back(5);
	mlist.push_back(17);
	mlist.push_back(3);

	for (std::list<int>::iterator it = mlist.begin(); it != mlist.end(); ++it)
		std::cout << *it << std::endl;

	//add more test after here
	return 0;
}