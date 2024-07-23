/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/23 19:32:18 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/23 22:02:22 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>

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
		

		// Friend declaration for the << operator overload
    	// template<typename U>
    	// friend std::ostream& operator<<(std::ostream& os, const Array<U>& array);
    	// std::ostream& operator<<(std::ostream& os, const Array& array);
};

#include "Array.tpp"