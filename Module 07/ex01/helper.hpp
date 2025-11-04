#pragma once

#include <iostream>

template <typename T> void increment_generic(T& x) { ++x; }
template <typename T> void display_generic(const T& x) {std::cout << x << " ";}