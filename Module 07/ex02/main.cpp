#include "Array.hpp"
#include <iostream>
#include <string>

template <typename T>
void printArray(const char* name, const Array<T>& arr) {
    std::cout << name << " (size=" << arr.size() << "): ";
    unsigned int n = arr.size();
    std::cout << "[";
    for (unsigned int i = 0; i < n; ++i) {
        if (i) std::cout << ", ";
        std::cout << arr[i];
    }
    std::cout << "]\n";
}

int main() {

    {
        std::cout << "### Empty Array:" << std::endl;
        Array<int> a;
        std::cout << "size=" << a.size() << "\n";
        try {
            std::cout << "Access a[0]: ";
            std::cout << a[0] << "\n";
        } catch (const std::exception& e) {
            std::cout << e.what() << "\n";
        }
        std::cout << std::endl;
    }

    {
        std::cout << "### Array<int> of a specific size:" << std::endl;
        Array<int> a(5);
        for (unsigned int i = 0; i < a.size(); ++i)
            a[i] = (int)(i + 1);
        printArray("a", a);
        try {
            std::cout << "Access a[4]: ";
            std::cout << a[4] << "\n";
        } catch (const std::exception& e) {
            std::cout << e.what() << "\n";
        }
        std::cout << std::endl;
    }

    {
        std::cout << "### Array<string> of a specific size:" << std::endl;
        Array<std::string> s(3);
        printArray("s", s);
        s[0] = "alpha"; s[1] = "beta"; s[2] = "gamma";
        printArray("s", s);
        std::cout << std::endl;
    }

    {
        std::cout << "### Const correctness:" << std::endl;
        Array<int> a(3);
        for (unsigned int i = 0; i < a.size(); ++i)
            a[i] = (int)(i * 2);
        const Array<int>& ca = a;
        std::cout << "ca[0]=" << ca[0] << ", ca[1]=" << ca[1] << ", ca[2]=" << ca[2] << "\n";
        // ca[0] = 7; // should NOT compile if uncommented (read-only)
        std::cout << std::endl;
    }

    {
        std::cout << "### Edge: zero-sized array via sized ctor with n=0\n";
        Array<int> z(0);
        std::cout << "z.size()=" << z.size() << "\n";
        try {
            std::cout << z[0] << "\n";
        } catch (const std::exception& e) {
            std::cout << e.what() << "\n";
        }
    }

    return 0;
}
