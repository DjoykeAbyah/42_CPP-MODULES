/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/10 19:39:49 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/15 14:30:20 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cctype>

/**
 * @note 	A static method is a class member function
 * 			belongs to the class not instance.
 * 			Called using the class name, don't create object of the class.
 * @todo	Do I need to use exceptions?
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

void convertChar(std::string &literal);
bool checkChar(std::string &literal);
void convertInt(std::string &literal);
bool checkInt(std::string &literal);
