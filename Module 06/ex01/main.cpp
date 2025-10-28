#include "Serializer.hpp"
#include <iostream>

int main() {

	//Serializer obj;

    Data obj = {42, "42school"};

    std::cout << "Original object:\n"
              << "  address: " << &obj << "\n"
              << "  id: " << obj.id << "\n"
              << "  name: " << obj.name << std::endl;

    uintptr_t raw = Serializer::serialize(&obj);
    Data* new_obj = Serializer::deserialize(raw);

    std::cout << "\nNew Object:\n"
              << "  address: " << new_obj << "\n"
              << "  id: " << new_obj->id << "\n"
              << "  name: " << new_obj->name << std::endl;

    std::cout << std::boolalpha
              << "\nAre they the same pointer pointer: " << (new_obj == &obj) << std::endl << std::endl;

    // alias test
    obj.id = 99;
    std::cout << "Alias check: " << new_obj->id << std::endl;

    // heap test
    Data* heap = new Data;
    heap->id = 7;
    heap->name = "heap";
    uintptr_t raw2 = Serializer::serialize(heap);
    Data* back2 = Serializer::deserialize(raw2);
    std::cout << "\nHeap round-trip same pointer: " << (back2 == heap) << std::endl << std::endl;
    delete heap;

    // NULL test
    uintptr_t zero = Serializer::serialize(NULL);
    Data* nullp = Serializer::deserialize(zero);
    std::cout << "NULL round-trip: " << (nullp == NULL) << std::endl;

    return 0;
}