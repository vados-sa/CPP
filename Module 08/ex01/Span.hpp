#pragma once

#include <vector>
#include <iterator>

class Span {
		std::vector<int> span;
		unsigned int N;

	public:
		explicit Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int n);

		template <typename It>
		void addRange(It first, It last);

		int shortestSpan() const;
		int longestSpan() const;
};