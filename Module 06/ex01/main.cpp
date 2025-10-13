#include "Serializer.hpp"
#include <iostream>

int main() {

	//Serializer obj;

	Data obj = {42, "42school"};
	std::cout << "Original pointer:\n" << "Original address: " << &obj << "\nId: " << obj.id << "\nName: " << obj.name << std::endl;
	uintptr_t raw = Serializer::serialize(&obj);
	
	Data* new_obj = Serializer::deserialize(raw);
	std::cout << "New pointer: \n" << "Original address: " << &obj << "\nId: " << new_obj->id << "\nName: " << new_obj->name << std::endl;

	std::cout << std::boolalpha << "Same pointer: " << (new_obj == &obj) << std::endl;

	return 0;
}