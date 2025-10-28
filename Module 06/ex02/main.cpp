#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
    std::srand(static_cast<unsigned int>(std::time(0)));

    for (int i = 0; i < 5; ++i) {
        Base* p = generate();

        std::cout << "identify(Base*): ";
        identify(p);

        std::cout << "identify(Base&): ";
        identify(*p);

        delete p;
        std::cout << "----" << std::endl;
    }

    return 0;
}