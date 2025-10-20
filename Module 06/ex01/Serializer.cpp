#include "Serializer.hpp"
#include <iostream>

Serializer::Serializer() {
    std::cout << "Serializer: default constructor" << std::endl;
}

Serializer::Serializer(const Serializer& other) {
    (void)other;
    std::cout << "Serializer: copy constructor" << std::endl;
}

Serializer& Serializer::operator=(const Serializer& other) {
    (void)other;
    std::cout << "Serializer: copy assignment operator" << std::endl;
    return *this;
}

Serializer::~Serializer() {
    std::cout << "Serializer: destructor" << std::endl;
}

// It takes a pointer and converts it to the unsigned integer type uintptr_t.
uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

// It takes an unsigned integer parameter and converts it to a pointer to Data.
Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}