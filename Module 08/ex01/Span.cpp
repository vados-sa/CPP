#include "Span.hpp"
#include <iostream>
#include <algorithm>
#include <limits>
#include <iterator>

Span::Span() : N(0) {}

Span::Span(unsigned int N) : N(N) { span.reserve(N); }

Span::Span(const Span& other)
	: span(other.span), N(other.N) {}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		span = other.span;
		N = other.N;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int n) {
	if (span.size() >= static_cast<size_t>(N))
		throw std::length_error("Span capacity exceeded");
	else
		span.push_back(n);
}

template <typename It>
void Span::addRange(It first, It last) {
	int incoming = std::distance(first, last);
	if (span.size() + static_cast<size_t>(incoming) > static_cast<size_t>(N))
		throw std::length_error("Not enough space in Span");
	span.insert(span.end(), first, last);
}

int Span::shortestSpan() const {
	if (span.size() < 2)
		throw std::logic_error("Not enough elements to compute span");
	std::vector<int> copy = span;
	std::sort(copy.begin(), copy.end());
	int best = std::numeric_limits<int>::max();
	for (size_t i = 0; i < copy.size() - 1; i++)
		best = std::min(best, copy[i + 1] - copy[i]);
	return best;
}

int Span::longestSpan() const {
	if (span.size() < 2)
		throw std::logic_error("Not enough elements to compute span");
	int highest = *std::max_element(span.begin(), span.end());
	int lowest = *std::min_element(span.begin(), span.end());
	return highest - lowest;
}