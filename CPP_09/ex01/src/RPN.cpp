/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/27 16:18:53 by dreijans      #+#    #+#                 */
/*   Updated: 2025/05/17 20:45:23 by djoyke        ########   odam.nl         */
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

bool RPN::isOperator(std::string &string) {
	return (string == "+" || string == "-" || string == "/" || string == "*");
}

