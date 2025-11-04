**Templates**

## [Function Templates](https://en.cppreference.com/w/cpp/language/templates.html)
 Special functions that can operate with generic types. This allows us to create a function template whose functionality can be adapted to more than one type or class without repeating the entire code for each type.

The format for declaring function templates with type parameters is:

`template <class identifier> function_declaration;`

`template <typename identifier> function_declaration;`

### Template Overloading
Writing multiple versions of the same template that differ by const qualifiers or references.

**[const correctness](https://isocpp.org/wiki/faq/const-correctness)**

## [Class Template](https://en.cppreference.com/w/cpp/language/class_template.html)

**value initialization vs default initialization**

`new int;`: default initialization. Value of *a is indeterminate (garbage).
`new int();`: value initialization, triggered by `()`, which zero-initialized the `int`.
That`s why
`int* a = new int();`
`std::cout << *a;`
prints `0`.


### Notes for evaluation:
**ex00:** 
- introduction to Function Template. 
- the goal is to write 3 function templates, swap, min and max. 
- Subject provides a main for testing
- I added a test case where the types are the same

**ex01:**
- it's about providing two overloads for `iter()` so constness is also respected.
- const array can only be displayed, but not incremented.

**ex02**
- introduction to Class Template.
