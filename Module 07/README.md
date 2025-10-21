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