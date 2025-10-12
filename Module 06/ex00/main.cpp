#include "ScalarConverter.hpp"

int main(int ac, char *av[])
{
    if (ac != 2) {
        std::cerr << "Usage: ./ScalarConverter <string representation of a C++ literal>" << std::endl;
        return 1;
    }

    std::string str = av[1];
    ScalarConverter::convert(str);

    return 0;
}