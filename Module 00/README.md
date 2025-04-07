**Namespaces, classes, member functions, stdio streams, initialization lists, static, const, and some other basic
stuff.**

# Megaphone (ex00)

## Overview
A simple program that takes command-line arguments and prints them in uppercase.

## Introduced C++ Concepts
- **`std::string`**: Unlike C-style strings (`char *`), `std::string` provides safer and more flexible string manipulation.
- **String Concatenation (`+=`)**: Appending strings directly without `strcat`.
- **String Methods (`length()`)**: Using member functions instead of `strlen()`.
- **Character Conversion (`std::toupper()`)**: Using `<cctype>` functions with `std::string`.
- **`std::cout`**: C++-style standard output stream (`printf` alternative).


# My Awesome Phonebook (ex01)

## Overview
"My Awesome PhoneBook" is a simple program that simulates a basic phonebook application. It allows users to add, search, and display contacts. The program can store up to 8 contacts, replacing the oldest one when a 9th contact is added. All data is lost when the program exits.

## Introduced C++ Concepts
- **Classes and Objects**.
- **Encapsulation**: Private members x Public Methods.
- **Input and Output**: `std::getline`, `std::cout`, `std::cin`.
- **Formatting Output**: `std::setw`.
- **Const Methods**: Methods that do not modify the object (e.g., `display_contact()`).