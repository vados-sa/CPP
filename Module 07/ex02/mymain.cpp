#include "Array.hpp"
#include <iostream>
#include <string>

template <typename T>
void printArray(const char* name, const Array<T>& arr, unsigned int maxShow = 8) {
    std::cout << name << " (size=" << arr.size() << "): ";
    unsigned int n = arr.size() < maxShow ? arr.size() : maxShow;
    std::cout << "[";
    for (unsigned int i = 0; i < n; ++i) {
        if (i) std::cout << ", ";
        std::cout << arr[i];
    }
    if (arr.size() > maxShow) std::cout << ", ...";
    std::cout << "]\n";
}

struct Widget {
    int id;
    Widget() : id(0) {}                 // default-constructed to 0
    Widget(int v) : id(v) {}
};

std::ostream& operator<<(std::ostream& os, const Widget& w) {
    os << "Widget(" << w.id << ")";
    return os;
}

int main() {
    std::cout << "=== ex02 :: Array<T> tests ===\n\n";

    // 1) Default constructor → empty array
    {
        Array<int> a;
        std::cout << "[1] default ctor -> empty\n";
        std::cout << "size=" << a.size() << "\n";
        // Bounds check (should throw)
        try {
            std::cout << "access a[0] (should throw): ";
            std::cout << a[0] << "\n"; // expect exception
        } catch (const std::exception& e) {
            std::cout << "caught: " << e.what() << "\n";
        }
        std::cout << "\n";
    }

    // 2) Sized constructor with built-in type (ints are uninitialized until we assign)
    {
        std::cout << "[2] sized ctor (int, n=5) + assignment\n";
        Array<int> a(5);
        for (unsigned int i = 0; i < a.size(); ++i) a[i] = (int)(i + 1);
        printArray("a", a);
        // OOB should throw
        try {
            std::cout << "access a[5] (should throw): ";
            std::cout << a[5] << "\n";
        } catch (const std::exception& e) {
            std::cout << "caught: " << e.what() << "\n";
        }
        std::cout << "\n";
    }

    // 3) Sized constructor with class type (strings default-construct to "")
    {
        std::cout << "[3] sized ctor (std::string, n=3) default-initialized to \"\"\n";
        Array<std::string> s(3);
        printArray("s", s);
        s[0] = "alpha"; s[1] = "beta"; s[2] = "gamma";
        printArray("s", s);
        std::cout << "\n";
    }

    // 4) Copy constructor → deep copy (modifying copy doesn’t affect original)
    {
        std::cout << "[4] copy ctor deep copy check\n";
        Array<int> a(3);
        for (unsigned int i = 0; i < a.size(); ++i) a[i] = (int)(10 + i); // 10,11,12
        Array<int> b(a); // copy
        printArray("a", a);
        printArray("b", b);
        b[0] = 999;
        std::cout << "after b[0]=999\n";
        printArray("a", a); // must remain 10,11,12
        printArray("b", b); // 999,11,12
        std::cout << "\n";
    }

    // 5) Assignment operator → deep copy + self-assignment safety
    {
        std::cout << "[5] operator= deep copy + self-assignment\n";
        Array<int> a(4);
        for (unsigned int i = 0; i < a.size(); ++i) a[i] = (int)(100 + i); // 100..103

        Array<int> c(2);
        c[0] = -1; c[1] = -2;
        std::cout << "before assign:\n";
        printArray("a", a);
        printArray("c", c);

        c = a; // deep copy
        std::cout << "after c=a:\n";
        printArray("a", a);
        printArray("c", c);

        c[1] = 4242;
        std::cout << "after c[1]=4242:\n";
        printArray("a", a); // must remain unchanged
        printArray("c", c);
    }

    // 6) Const correctness: const Array uses const operator[] (read-only)
    {
        std::cout << "[6] const correctness\n";
        Array<int> a(3);
        for (unsigned int i = 0; i < a.size(); ++i) a[i] = (int)(i * 2); // 0,2,4
        const Array<int>& ca = a;
        std::cout << "ca[0]=" << ca[0] << ", ca[1]=" << ca[1] << ", ca[2]=" << ca[2] << "\n";
        // The following should NOT compile if uncommented (read-only):
        // ca[0] = 7;
        std::cout << "\n";
    }

    // 7) Custom class type to verify default construction and deep copy
    {
        std::cout << "[7] custom type (Widget)\n";
        Array<Widget> w(3);            // default-constructed -> id=0
        for (unsigned int i = 0; i < w.size(); ++i) w[i].id = (int)(i + 42);
        printArray("w", w);

        Array<Widget> w2 = w;          // copy
        w2[1].id = 777;
        std::cout << "after w2[1].id=777\n";
        printArray("w", w);            // must remain unchanged
        printArray("w2", w2);
        std::cout << "\n";
    }

    // 8) Edge: zero-sized array via sized ctor
    {
        std::cout << "[8] sized ctor with n=0\n";
        Array<int> z(0);
        std::cout << "z.size()=" << z.size() << "\n";
        try {
            std::cout << z[0] << "\n"; // should throw
        } catch (const std::exception& e) {
            std::cout << "caught: " << e.what() << "\n";
        }
        std::cout << "\n";
    }

    std::cout << "=== done ===\n";
    return 0;
}
