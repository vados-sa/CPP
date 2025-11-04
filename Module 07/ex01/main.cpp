#include "iter.hpp"
#include "helper.hpp"

void display_int(const int& x) {std::cout << x << " ";}
void increment_int(int& x) { ++x; }

int main() {
	int a[] = {1,2,3};
	std::cout << "a = {1,2,3}" << std::endl;
    
	iter(a, 3, increment_int);
    iter(a, 3, display_int); // should be 2, 3, 4
	std::cout << std::endl;
	
    iter(a, 3, increment_generic<int>);
	iter(a, 3, display_generic<int>); // should be 3, 4, 5
	std::cout << std::endl;
	
    const int ca[] = {7,8,9};
	std::cout << "ca = {7,8,9}" << std::endl;

    iter(ca, 3, display_int);  // should be 7, 8, 9
	std::cout << std::endl;
    iter(ca, 3, display_generic<int>);  // should be 7, 8, 9
	std::cout << std::endl;
	// iter(ca, 3, increment_int);        // should not compile
	// iter(ca, 3, increment_generic<int>); // should not compile


    std::string s[] = {"x","y","z"};
	std::cout << "s[] = {\"x\",\"y\",\"z\"}" << std::endl;
    iter(s, 3, display_generic<std::string>);
	std::cout << std::endl;

    return 0;
}