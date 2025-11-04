#pragma once

#include <iostream>
#include <cstddef>

template <typename T> void iter(T* array, const std::size_t length, void (*func)(T&)) {
	for (std::size_t i = 0; i < length; i++)
		func(array[i]);
}

template <typename T> void iter(const T* array, const std::size_t length, void (*func)(const T&)) {
	for (std::size_t i = 0; i < length; i++)
		func(array[i]);
}