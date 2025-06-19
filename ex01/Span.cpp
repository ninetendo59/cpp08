#include "Span.hpp"

Span::Span(unsigned int num) : N(num)
{
	if (Span::N > __INT_MAX__)
		throwSpanSizeMaxLimit();
}

Span &Span::operator=(const Span &source)
{
	(void)source;
	return (*this);
}

Span::~Span()
{

}

inline void Span::throwSpanIsFull()
{
	throw std::out_of_range("The Span is full!");
}

inline void Span::throwInsufficientSpan()
{
	throw std::out_of_range("You can't get Span less than 2!");
}

inline void Span::throwSpanSizeMaxLimit()
{
	throw std::out_of_range("Overflowed! Maximum allowed size: INT_MAX.");
}

inline void Span::throwSpanSizeInvalid()
{
	throw std::out_of_range("You can't really have less than 0 size bro.");
}

inline void Span::throwFailAssSpanZero()
{
	throw std::out_of_range("You can't really assign if the size is ZERO!!");
}

void Span::addNumber(int number)
{
	if (_span.size() < N)
		_span.push_back(number);
	else
		throwSpanIsFull();
}

unsigned int Span::shortestSpan()
{
	if (_span.size() < 2)
		throwInsufficientSpan();

	std::vector<int> sortedSpan = _span;
	std::sort(sortedSpan.begin(), sortedSpan.end());

	unsigned int SpanLength = __INT_MAX__;
	for (unsigned int n = 0; n < N - 1; n++)
	{
		if (SpanLength > static_cast<unsigned int>(sortedSpan[n + 1] - sortedSpan[n]))
			SpanLength = sortedSpan[n + 1] - sortedSpan[n];
	}
	return (SpanLength);
}

unsigned int Span::longestSpan()
{
	if (_span.empty() || _span.size() == 1)
		throwInsufficientSpan();
	unsigned int SpanLength = 
		std::max_element(_span.begin(), _span.end()) -
		std::min_element(_span.begin(), _span.end());
	return (SpanLength);
}

int Span::generateRandomFormula()
{
	int high = rand();
	int low = rand();

	int value = (high << 15) | (low & 0x7FFF);

	if (rand() % 2)
		value = -value;

	return (value);
}

void Span::fillSpan()
{
	if (Span::N == 0)
		throwFailAssSpanZero();

	std::vector<int> v;
	srand(time(NULL));

	for (unsigned int i = 0; i < N; i++)
	{
		const int value = generateRandomFormula();
		std::cout << "Value of Push #" << i
			<< ": " << value << std::endl;
		this->_span.push_back(value);
	}
}