#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main()
{
    std::vector<int> v;
	srand(time(NULL));
	std::cout << std::endl << "Testing 1: Smaller number" << std::endl
		<< "-------------------------" << std::endl;
	for (int i = 0; i < 6; i++)
	{
		const int value = rand() % 10;
		std::cout << "Value of Push #" << i
			<< ": " << value << std::endl;
		v.push_back(value);
	}
    try
	{
		const int value = rand() % 10;
		std::cout << "Value random generated: " << value << std::endl;
        std::vector<int>::iterator it = easyfind(v, value);
        std::cout << "Found in vector: " << *it << std::endl;
    }
	catch (const std::exception& e) 
	{
        std::cout << "Vector: " << e.what() << std::endl;
    }

	std::cout << std::endl << "Testing 2: Bigger number"<< std::endl
		<< "------------------------" << std::endl;
    std::list<int> l;
    for (int i = 0; i < 6; i++)
	{
		const int value = rand() % 70;
		std::cout << "Value of Push #" << i
			<< ": " << value << std::endl;
		l.push_back(value);
	}
    try
	{
		const int value = rand() % 10;
		std::cout << "Value random generated: " << value << std::endl;
        std::list<int>::iterator it = easyfind(l, value);
        std::cout << "Found in list: " << *it << std::endl;
    }
	catch (const std::exception& e)
	{
        std::cout << "List: " << e.what() << std::endl;
    }

	std::cout << std::endl << "Testing 3: Empty container"<< std::endl
		<< "--------------------------" << std::endl;
    std::vector<int> empty;
    try
	{
        std::vector<int>::iterator it = easyfind(empty, 1);
        std::cout << "Found in empty vector: " << *it << std::endl;
    }
	catch (const std::exception& e)
	{
        std::cout << "Empty vector: " << e.what() << std::endl;
    }

    return 0;
}
