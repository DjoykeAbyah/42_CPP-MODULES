/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.tpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/23 19:34:17 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/23 21:18:43 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Array.hpp"

template<typename T>
Array<T>::Array() : _data(nullptr), _size(0) {}

template<typename T>
Array<T>::Array(const unsigned int n) {
	_data = new T[n]();
	_size = this._size;
}

template<typename T>
Array<T>::Array(const Array &copy) {
	int n = this->size();
	copy._data = new T[n];
	for (int i = 0; i < n; i++)
		copy._data[i] = this->_data[i];
}



template<typename T>
int Array<T>::size() {
	return this.size();
}

