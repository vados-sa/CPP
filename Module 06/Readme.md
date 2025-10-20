**Type Cast**

Convert an expression of a given type into another type.

# Implicit Conversion:
Implicit conversions do not require any operator. They are automatically performed when a value is copied to a compatible type. It affects fundamental data types, and allow conversions such as the conversions between numerical types (short to int, int to float, double to int...), to or from bool, and some pointer conversions. Some of these conversions may imply a loss of precision, which the compiler can signal with a warning. This warning can be avoided with an explicit conversion.

# Explicit Conversion:
Many conversions, specially those that imply a different interpretation of the value, require an explicit conversion.

## dynamic_cast:
Can be used only with pointers and references to objects, and it's mainly used to perform downcasting (converting a pointer/reference of a base class to a derived class) in polymorphisms and inheritance. Its purpose is to ensure that the result of the type conversion is a valid complete object of the requested class.
Therefore, dynamic_cast is always successful when we cast a class to one of its base classes.
If the conversion is not possible, dynamic_cast returns a null pointer (for pointer conversions) or throws a bad_cast exception (for reference conversions).

## reinterpret_cast:
reinterpret_cast converts any pointer type to any other pointer type, even of unrelated classes. The operation result is a simple binary copy of the value from one pointer to the other. All pointer conversions are allowed: neither the content pointed nor the pointer type itself is checked.

## static_cast: 
Can perform conversions between pointers to related classes, not only from the derived class to its base, but also from a base class to its derived. This ensures that at least the classes are compatible if the proper object is converted, but no safety check is performed during runtime to check if the object being converted is in fact a full object of the destination type. Therefore, it is up to the programmer to ensure that the conversion is safe. Can also be used to perform any other non-pointer conversion that could also be performed implicitly, like for example standard conversion between fundamental types.

## const_cast:
This type of casting manipulates the constness of an object, either to be set or to be removed.

**obs: `typeid`** (not allowed in ex02): allows to check the type of an expression 'typeid (expression)'. This operator returns a reference to a constant object of type type_info that is defined in the standard header file <typeinfo>.

# ex00
`static_cast` chosen here because it performs standard numeric conversions and keeps intent explicit.
Implicit conversion could also be used here, but it hides intent and makes narrowing conversions easy to miss. Explicit `static_cast` makes the potentially lossy step deliberate.  

# ex01:
The exercise asks to round-trip a pointer through an integer type. `reinterpret_cast` is used here because the the conversion is being made between unrelated pointer types (uintptr_t and Data structure).

### Why would you want a class to be not instantiable?
Provide only static utilities (no object needed) - one of.
Use Cases of Static Member Functions:
- They can access and modify static data members of the class.
- No object instantiation is required—call them directly using the class name (ClassName :: function name()).
- Perfect for utility functions or helper methods.
- Can be used to track common data across all objects (like a counter).
Goal: round-trip a raw pointer through an integer without changing bits.
reinterpret_cast: the only C++ cast that allows pointer ↔ integer conversions.

# ex02:
`dynamic_cast` used here because it performs a safe downcast from Base to one of A, B, or C using RTTI (Run-Time Type Information). It checks the object’s dynamic type at runtime - Base must be polymorphic - and only succeeds if the object really is that derived type.

For pointers: if the object isn’t of the requested derived type, dynamic_cast returns NULL. That’s why identify(Base*) checks each cast and prints the match.

For references: if the cast fails, dynamic_cast throws std::bad_cast. That’s why identify(Base&) uses try/catch.
