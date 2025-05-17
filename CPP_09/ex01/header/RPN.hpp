/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/27 16:18:26 by dreijans      #+#    #+#                 */
/*   Updated: 2025/05/17 20:44:13 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <stdexcept>

//program nust take inverted Polish mathematical expression as argument
//numbers passed will be less than 10
//program must process this expression and output correct result
//if error ocurs erros message must be displayed on stdout
//program must be able to handle +, -, /, *.
//container used here cannot be used in other exercise
//don't need to handle brackets or decimals

class RPN {
	private:
		//one stack is enough
		std::stack<int> _stack;

	public:
		RPN();
		RPN(const RPN &copy);
		RPN& operator=(const RPN &copy);
		~RPN();
		
		bool isOperator(std::string &string);

		class InvalidCharacterException : public std::exception {
			virtual const char* what() const throw() {
				return "invalid charachter";
			}
		};
};