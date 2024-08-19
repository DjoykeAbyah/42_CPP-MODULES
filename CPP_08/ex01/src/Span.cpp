/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/19 14:44:36 by dreijans      #+#    #+#                 */
/*   Updated: 2024/08/19 15:17:47 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Span.hpp"

Span::Span() : _N(0) {}

Span::Span(unsigned int num) : _N(num) {}

Span::Span(const Span &copy) : _N(copy._N) {}

Span& Span::operator=(const Span &copy) {
	if (this != &copy)
		_N = copy._N;
	return *this;
}

Span::~Span() {}

void Span::addNumber(int num) {
	//add number to container
}

int Span::shortestSpan() {
	//check between numbers what shortest span is
	//return the shortest
}

int Span::longestSpan() {
	//check between numbers for longest span
	//return longest span
}