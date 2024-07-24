/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.tpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/23 19:34:17 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/24 15:32:56 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Array.hpp"

template<typename T>
Array<T>::Array() : _array(nullptr), _size(0) {}

template<typename T>
Array<T>::Array(const unsigned int n) : _size(n) {
	_array = new T[n]();
}

template<typename T>
Array<T>::Array(const Array &origin) : _size(origin._size) {
	_array = new T[_size];
	for (int i = 0; i < _size; i++)
		_array[i] = origin._array[i];
}

template<typename T>
Array<T>& Array<T>::operator=(const Array &origin) {
	if (this != &origin) {
		delete[] _array; //delete old data
		_size = origin._size;
		_array = new T[_size];
		for (int i = 0; i < _size; i++)
			_array[i] = origin._array[i];	
	}
	return *this;
}

template<typename T>
Array<T>::~Array() {
	delete[] _array;
}

template<typename T>
T& Array<T>::operator[](int index) {
	if (index >= _size)
		throw std::out_of_range("index out of bounds");
	else
		return _array[index];
}

template<typename T>
int Array<T>::size() {
	return _size;
}

// Template implementation of the << operator overload
template<typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& array) {
    os << "Array( ";
    for (int i = 0; i < array._size; ++i) {
        os << array._array[i];
        if (i < array._size - 1) {
            os << ", ";
        }
    }
    os << " )";
    return os;
}
