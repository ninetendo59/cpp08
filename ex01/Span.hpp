#ifndef SPAN_HPP
#define SPAN_HPP
#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>

class Span
{
	private:
		unsigned int N;
		std::vector<int> _span;

	public:
		Span();
		Span(const Span &source);
		Span(unsigned int N);
		Span &operator=(const Span &source);
		~Span();
		void addNumber(int number);
		unsigned int shortestSpan();
		unsigned int longestSpan();
		int generateRandomFormula();
		void fillSpan();

		inline void throwSpanIsFull();
		inline void throwInsufficientSpan();
		inline void throwSpanSizeMaxLimit();
		inline void throwSpanSizeInvalid();
		inline void throwFailAssSpanZero();
};

#endif
