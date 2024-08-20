/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/19 14:44:36 by dreijans      #+#    #+#                 */
/*   Updated: 2024/08/20 17:06:43 by dreijans      ########   odam.nl         */
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
	if (_vector.size() < 2)
		throw VectorTooSmall();
	else {
		std::sort(_vector.begin(), _vector.end());
		int min_num = *std::min_element(_vector.begin(), _vector.end());
		int span = _vector[1] - _vector[0];
		return span;
	}
}

int Span::longestSpan() {
	if (_vector.size() < 2)
		throw VectorTooSmall();
	else {
		std::sort(_vector.begin(), _vector.end());
		int max_num = *std::min_element(_vector.begin(), _vector.end());
		for (int num : _vector) {
			if (max_num - num > max_num)
				max_num = max_num - num; 
			else
				return max_num;
		}
	}
}