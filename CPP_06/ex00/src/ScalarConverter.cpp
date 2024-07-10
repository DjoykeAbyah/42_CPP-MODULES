/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/10 19:39:35 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/10 21:00:30 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string &literal){
	//check if char + convert to char
	//check if int + convert to int
	//check if float + convert to float
	//check if double + convert to double
}

char convertToChar(std::string &literal){
	if (literal.empty())
		std::cout << "input is empty" << std::endl;
	if (literal.size() != 1)
		std::cout << "to big for a char" << std::endl;
	if (isprint(static_cast<char>(literal[0])) == false)
		std::cout << "not printable" << std::endl;
}