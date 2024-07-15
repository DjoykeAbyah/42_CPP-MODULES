/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/10 19:39:35 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/15 16:26:15 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iomanip>

//cast to all other types beside the type thats input

void ScalarConverter::convert(std::string &literal){
	
	if (checkChar(literal) == true){
		convertChar(literal);
	}
	if (checkInt(literal) == true){
		convertInt(literal);
	}
	//check if float + convert to float
	//check if double + convert to double
	else
		std::cout << "Invalid input" << std::endl;
}

bool checkChar(std::string &literal){
	if (literal.empty()){
		std::cout << "input is empty" << std::endl;
		return false;
	}
	if (literal.size() == 3 && literal[0] == '\'' && literal[2] == '\''){
		return true;
	}
	return false;
}

void convertChar(std::string &literal){
	char c = literal[1];
	
	if (!isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

bool checkInt(std::string &literal){
	if (literal.empty()){
		std::cout << "input is empty" << std::endl;
		return false;
	}
	int size = literal.size();
	for (int i = 0; i < size; i++)
	{
		if (!isdigit(literal[i]))
			return false;
	}
	return true;
}

void convertInt(std::string &literal){
	int num = std::stoi(literal);
	
	std::cout << "char: ";
    if (num < 0 || num > 127 || !isprint(num)) {
        std::cout << "Non displayable" << std::endl;
    } else {
        std::cout << "'" << static_cast<char>(num) << "'" << std::endl;
    }
	std::cout << "int: " << num << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(num) << std::endl;
}