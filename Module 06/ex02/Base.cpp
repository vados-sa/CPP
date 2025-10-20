#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base::~Base() {}

 // It randomly instantiates A, B, or C and returns the instance as a Base pointer.
Base* generate(void) {
    switch (std::rand() % 3) {
        case 0: return new A();
        case 1: return new B();
        default: return new C();
    }
}

// It prints the actual type of the object pointed to by p: "A", "B", or "C".
void identify(Base* p) {
    if (!p) { std::cout << "Null" << std::endl; return; }
    if (dynamic_cast<A*>(p)) std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p)) std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p)) std::cout << "C" << std::endl;
    else std::cout << "Unknown" << std::endl;
}

// It prints the actual type of the object referenced by p: "A", "B", or "C".
// Using a pointer inside this function is forbidden.
void identify(Base& p) {
    try { (void)dynamic_cast<A&>(p); std::cout << "A" << std::endl; return; } catch (...) {}
    try { (void)dynamic_cast<B&>(p); std::cout << "B" << std::endl; return; } catch (...) {}
    try { (void)dynamic_cast<C&>(p); std::cout << "C" << std::endl; return; } catch (...) {}
    std::cout << "Unknown" << std::endl;
}