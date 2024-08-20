/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/19 14:44:36 by dreijans      #+#    #+#                 */
/*   Updated: 2024/08/20 16:32:40 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Span.hpp"

Span::Span() : _N(0) {}

/**
 * resize would only be useful 
 * if you know how many numbers will be added in total
**/
Span::Span(unsigned int num) : _N(num) {}

Span::Span(const Span &copy) : _N(copy._N) {}

Span& Span::operator=(const Span &copy) {
	if (this != &copy)
		_N = copy._N;
	return *this;
}

Span::~Span() {}

void Span::addNumber(int num) {
	if (_vector.size() < _N)
		_vector.push_back(num);
	else
		throw VectorLimitException();
}

int Span::shortestSpan() {
	//check between numbers what shortest span is
	//return the shortest
}

int Span::longestSpan() {
	//check between numbers for longest span
	//return longest span
}