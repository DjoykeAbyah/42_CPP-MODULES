/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/23 19:32:18 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/24 15:45:24 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# define BOLD_TEXT "\033[1m"
# define RESET "\033[0m"
# define BLUE "\033[34m"
# define CYAN "\033[36m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define MAGENTA "\033[35m"
# define ORANGE "\033[38;2;255;165;0m"

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
		T& operator[](int index);
		
	// Friend declaration for the << operator overload
    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const Array<U>& array);
	
};

#include "Array.tpp"