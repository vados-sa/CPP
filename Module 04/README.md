**Subtype Polymorphism, Abstract Classes, and Interfaces**

## Subtype Polymorphism (ex00)
It's also know as **runtime polymorphism**.
Allows for the program to use derived class methods through a base class pointer or reference.

`virtual` means the linkage will be dynamic and not static.

## Deep Copy x Shallow Copy (ex02)
**Deep Copy** makes sure that dynamically allocated objects are properly copied.

Meanwhile, **Shallow Copy** of dynamically allocated onjects only copies the pointers - the adress it points to.  

## Abstract Classes (ex03)
A class where not all of its functions implementations are known.
To make a class abstract, it needs to have at least one **pure virtual fucntion** by assigning it to 0 (zero): `virtual void function() = 0;`.
- Objects cannot be created from abstract classes.
- Every derived class must have an implementation of the function.