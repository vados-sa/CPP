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

    std::cout << "\nDeserialized pointer:\n"
              << "  address: " << new_obj << "\n"
              << "  id: " << new_obj->id << "\n"
              << "  name: " << new_obj->name << std::endl;

    std::cout << std::boolalpha
              << "\nSame pointer: " << (new_obj == &obj) << std::endl;

    // Alias test
    obj.id = 99;
    std::cout << "Alias check - should be 99: " << new_obj->id << std::endl;

    // Heap test
    Data* heap = new Data;
    heap->id = 7;
    heap->name = "heap";
    uintptr_t raw2 = Serializer::serialize(heap);
    Data* back2 = Serializer::deserialize(raw2);
    std::cout << "\nHeap round-trip same pointer: " << (back2 == heap) << std::endl;
    delete heap;

    // NULL test
    uintptr_t zero = Serializer::serialize(NULL);
    Data* nullp = Serializer::deserialize(zero);
    std::cout << "NULL round-trip: " << (nullp == NULL) << std::endl;

    return 0;
}