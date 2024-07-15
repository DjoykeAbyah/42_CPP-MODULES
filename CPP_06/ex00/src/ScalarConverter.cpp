/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/10 19:39:35 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/15 14:07:59 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

//cast to all other types beside the type thats input

void ScalarConverter::convert(std::string &literal){
	
	if (checkChar(literal) == true){
		convertChar(literal);
	}
	//check if int + convert to int
	//check if float + convert to float
	//check if double + convert to double
}

bool checkChar(std::string &literal){
	if (literal.empty()){
		std::cout << "input is empty" << std::endl;
		return false;
	}
	if (literal.size() != 1){
		std::cout << "to big for a char" << std::endl;
		return false;
	}
	if (isdigit(literal[0])){
		std::cout << "character is a digit" << std::endl;
		return false;
	}
	if (isprint(static_cast<char>(literal[0])) == false){
		std::cout << "Non displayable" << std::endl;
		return false;
	}
	return true;
}

void convertChar(std::string &literal){
	std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(literal[0]) << std::endl;
	std::cout << "double: " << static_cast<double>(literal[0]) << std::endl;
}