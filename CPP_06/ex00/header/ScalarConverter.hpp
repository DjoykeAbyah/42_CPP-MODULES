/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/10 19:39:49 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/16 21:38:39 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cctype>

/**
 * @note 	A static method is a class member function
 * 			belongs to the class not instance.
 * 			Called using the class name, don't create object of the class.
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

bool checkChar(std::string &literal);
bool checkInt(std::string &literal);
bool checkFloat(std::string &literal);
bool checkDouble(std::string &literal);
bool checkPseudo(std::string &literal);

void convertChar(std::string &literal);
void convertInt(std::string &literal);
void convertFloat(std::string &literal);
void convertDouble(std::string &literal);
void convertPseudo(std::string &literal);
