/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.tpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/23 19:34:17 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/23 21:47:02 by dreijans      ########   odam.nl         */
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
		_array[i] = origin_array[i];
}

template<typename T>
Array<T>& Array<T>::operator=(const Array &origin) {
	if (this != &origin) {
		_size = origin._size;
		_array = new T[_size];
		for (int i = 0; i < _size; i++)
			_array[i] = origin_array[i];	
	}
	return *this;
}

template<typename T>
Array<T>::~Array() {
	delete[] _array;
}

template<typename T>
const T& Array<T>::operator[](unsigned int index) {
	if (index >= _size)
		throw std::__throw_out_of_range("index out of bounds");
	else
		return _data[index];
}

template<typename T>
int Array<T>::size() {
	return _size;
}