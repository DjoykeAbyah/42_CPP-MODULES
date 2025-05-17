/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/27 16:18:53 by dreijans      #+#    #+#                 */
/*   Updated: 2025/05/17 21:19:24 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& copy) : _stack(copy._stack) {}

RPN& RPN::operator=(const RPN& copy) {
	if (this != &copy) {
		_stack = copy._stack;
	}
	return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(std::string &character) {
	return (character == "+" || character == "-" || character == "/" || character == "*");
}

void RPN::parseInput(std::string &input) {
	// extract each individual word
	std::istringstream stream(input);
	
	while (stream >> _token) {
		std::cout << "token is " << _token << std::endl;
	}
}