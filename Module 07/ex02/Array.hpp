#pragma once

#include <cstddef>
#include <stdexcept>

template <typename T>
class Array {
		T* elements;
		unsigned int _size;
	public:
		Array() : _size(0) {
			elements = NULL;
		}

		Array(unsigned int n) : _size(n) {
			elements = new T[n];
		}

		Array(const Array& other) : elements(NULL), _size(other._size) {
			if (_size)
				elements = new T[_size];
			for (unsigned int i = 0; i < _size; ++i)
        		elements[i] = other.elements[i];
		}
		Array& operator=(const Array& other) {
			if (this == &other) return *this;
			else {
				delete[] elements;
				elements = NULL;
				_size = other._size;
				if (_size) {
					elements = new T[_size];
					for (unsigned int i = 0; i < _size; ++i)
        				elements[i] = other.elements[i];
				}
			}
			return *this;
		}

        ~Array(){delete[] elements;}

		T& operator[](unsigned int index) {
			if (index >= _size)
				throw std::out_of_range("Array index out of bounds");
			return elements[index];
		}
		const T& operator[](unsigned int index) const {
			if (index >= _size)
				throw std::out_of_range("Array index out of bounds");
			return elements[index];
		}

		unsigned int size() const { return _size; }
};