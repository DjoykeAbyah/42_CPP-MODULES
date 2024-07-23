/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/23 19:32:18 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/23 20:39:19 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Array.tpp"

/**
 * throw std::exception when element in [] operator is out of bounds
 * try to compile int * a = new int() then display *a
 * 
 */
template<typename T>
class Array {
	
	private:
		T* 				_data;

	public:
		
		Array();
		Array(const unsigned int n);
		Array(const Array &copy);
		Array& operator=(const Array &copy);
		~Array();

		int size();
		
};