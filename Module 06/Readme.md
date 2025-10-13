ex00: static_cast;
ex 01: Why would you want a class to be not instantiable?
Provide only static utilities (no object needed) - one of.
Use Cases of Static Member Functions:
- They can access and modify static data members of the class.
- No object instantiation is required—call them directly using the class name (ClassName :: function name()).
- Perfect for utility functions or helper methods.
- Can be used to track common data across all objects (like a counter).

Goal: round-trip a raw pointer through an integer without changing bits.
reinterpret_cast: the only C++ cast that allows pointer ↔ integer conversions.