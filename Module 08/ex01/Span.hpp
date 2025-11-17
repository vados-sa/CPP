#pragma once

#include <vector>
#include <iterator>

class Span {
		std::vector<int> span;
		unsigned int N;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int n);
		
		int shortestSpan() const;
		int longestSpan() const;
		
		template <typename It>
		void addRange(It first, It last) {
			int incoming = std::distance(first, last);
			if (span.size() + static_cast<size_t>(incoming) > static_cast<size_t>(N))
				throw std::length_error("Not enough space in Span");
			span.insert(span.end(), first, last);
		}

		int getN() const;
};