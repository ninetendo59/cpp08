#include "Span.hpp"

int main() {
    std::cout << std::endl << "Testing 1: sanity test" << std::endl
		<< "-------------------------" << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Test 1 Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << "Testing 2: Exceed limit" << std::endl
		<< "-------------------------" << std::endl;
    try
    {
        Span sp(2);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3); // Should throw
    }
    catch (const std::exception& e)
    {
        std::cout << "Test 2 Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << "Testing 3: N < 2" << std::endl
		<< "-------------------------" << std::endl;
    try {
        Span sp(3);
        sp.addNumber(42);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl; // Should throw
    }
    catch (const std::exception& e)
    {
        std::cout << "Test 3 Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << "Testing 4: Fill span" << std::endl
		<< "-------------------------" << std::endl;
    try
    {
        Span sp(10);
        sp.fillSpan();
        std::cout << "Shortest span (auto): " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span (auto): " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Test 4 Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << "Testing 5: Span zero" << std::endl
		<< "-------------------------" << std::endl;
    try
    {
        Span sp(0);
        sp.fillSpan(); // Should throw
    }
    catch (const std::exception& e)
    {
        std::cout << "Test 5 Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << "Testing 6: Span Big" << std::endl
		<< "-------------------------" << std::endl;
    try
    {
        Span big;
        big.fillSpan();
        std::cout << "Shortest span (auto): " << big.shortestSpan() << std::endl;
        std::cout << "Longest span (auto): " << big.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}