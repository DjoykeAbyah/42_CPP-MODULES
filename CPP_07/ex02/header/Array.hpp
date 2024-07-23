/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/23 19:32:18 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/23 21:43:29 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>

/**
 * throw std::exception when element in [] operator is out of bounds
 * try to compile int * a = new int() then display *a
 * 
 */
template<typename T>
class Array {
	
	private:
		T* 				_array;
		int				_size;

	public:
		
		Array();
		Array(const unsigned int n);
		Array(const Array &copy);
		Array& operator=(const Array &copy);
		~Array();

		int size();
		const T& operator[](unsigned int index);
		
};

#include "Array.tpp"