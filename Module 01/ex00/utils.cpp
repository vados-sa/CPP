#include "Zombie.hpp"

std::string trim(const std::string& str)
{
    size_t start = str.find_first_not_of(" \t\n\r");
    size_t end = str.find_last_not_of(" \t\n\r");

    if (start == std::string::npos) {
        return ""; // String is all whitespace
    }

    return str.substr(start, end - start + 1);
}