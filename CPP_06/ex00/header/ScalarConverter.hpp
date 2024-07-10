/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/10 19:39:49 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/10 20:16:32 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

/**
 * @note 	A static method is a class member function that belongs to the class
 * 			not an instance of the class.
 * 			Called using the class name, without the need to create an object of the class.
 */ 
class ScalarConverter{
	
	private:
		ScalarConverter() = delete;
		ScalarConverter(const ScalarConverter &copy) = delete;
		ScalarConverter& operator=(const ScalarConverter &copy) = delete;
		~ScalarConverter() = delete;
		
	public:
	
		static void convert(std::string &literal); //static method to convert and display scalar types
};

char convertToChar(std::string &literal);