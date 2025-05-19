/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/27 16:18:53 by dreijans      #+#    #+#                 */
/*   Updated: 2025/05/19 18:13:42 by djoyke        ########   odam.nl         */
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

bool RPN::isOperator(const std::string &character) {
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
	std::istringstream 	stream(input);
	std::string 		token;
	
	while (stream >> token) {
		if (token.length() == 1 && isdigit(token[0])) {
			_stack.push(token[0] - '0');
		}
		else if (isOperator(token)) {
			if (_stack.size() < 2) {
				throw std::runtime_error("operand digit imbalance");
			}
			
			int right = _stack.top();
			_stack.pop();
			int left = _stack.top();
			_stack.pop();

			int result = calculate(left, right, token[0]);
			_stack.push(result);
		}
		else {
			throw InvalidCharacterException();
		}
	}

	if (_stack.size() != 1) {
		throw std::runtime_error("RPN input invalid");
	}
	std::cout << _stack.top() << std::endl;
}