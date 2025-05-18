/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/27 16:18:53 by dreijans      #+#    #+#                 */
/*   Updated: 2025/05/18 13:04:12 by djoyke        ########   odam.nl         */
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

int RPN::calculate(int left, int right, char operand) {
	if (operand == '+') {
		return (left + right);
	}
	else if (operand == '-') {
		return (left - right); 
	}
	else if (operand == '/') {
		if (right == 0) {
			throw std::runtime_error("cannot divide by 0");
		}
		return (left / right);
	}
	else if (operand == '*') {
		return (left * right);
	}
	throw std::runtime_error("unknown operator");
}

void RPN::parseInput(std::string &input) {
	// extract each individual word
	std::istringstream stream(input);
	
	while (stream >> _token) {
		std::cout << "token is " << _token << std::endl;
		if (_token.length() == 1 && isdigit(_token[0])) {
			_stack.push(_token[0] - '0');
		}
		else if (isOperator(_token)) {
			if (_stack.size() < 2) {
				throw std::runtime_error("operand digit imbalance");
			}
			
			int right = _stack.top();
			_stack.pop();
			int left = _stack.top();
			_stack.pop();

			int result = calculate(left, right, _token[0]);
			_stack.push(result);
			std::cout << "stack is " << result << std::endl;
			
			
		}
		
	}
}