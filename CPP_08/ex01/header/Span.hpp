/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/31 15:54:44 by dreijans      #+#    #+#                 */
/*   Updated: 2024/08/20 16:29:39 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>

class Span {
	
	private:
		unsigned int _N;
		std::vector<int> _vector;
	
	public:
		Span() = delete;
		Span(unsigned int num);
		Span(const Span &copy);
		Span& operator=(const Span &copy);
		~Span();
		
		void	addNumber(int num);
		int		shortestSpan();
		int		longestSpan();

	class	
	
};
