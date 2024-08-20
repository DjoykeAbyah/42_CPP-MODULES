/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/19 14:44:36 by dreijans      #+#    #+#                 */
/*   Updated: 2024/08/20 18:27:18 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Span.hpp"

Span::Span(unsigned int num) : _N(num) {}

Span::Span(const Span &copy) : _N(copy._N), _vector(copy._vector) {}

Span& Span::operator=(const Span &copy) {
	if (this != &copy) {
		_N = copy._N;
		_vector = copy._vector;	
	}
	return *this;
}

Span::~Span() {}

std::vector<int>& Span::getVector() {
	return _vector;
}

void Span::addNumber(int num) {
	if (_vector.size() < _N)
		_vector.push_back(num);
	else
		throw VectorLimitException();
}

int Span::shortestSpan() {
	if (_vector.size() < 2)
		throw VectorTooSmall();

	std::sort(_vector.begin(), _vector.end());
	int min_span = std::numeric_limits<int>::max();
	
		for (size_t i = 0; i < _vector.size() - 1; i++) {
			int span = _vector[i + 1] - _vector[i];
			if (span < min_span)
				min_span = span;
		}
		return min_span;
}

int Span::longestSpan() {
	if (_vector.size() < 2)
		throw VectorTooSmall();
	
	int min_num = *std::min_element(_vector.begin(), _vector.end());
	int max_num = *std::max_element(_vector.begin(), _vector.end());

	return max_num - min_num;
}