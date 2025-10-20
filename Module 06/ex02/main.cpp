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

    // Null pointer test
    Base* nullp = NULL;
    std::cout << "identify(null Base*): ";
    identify(nullp);

    return 0;
}