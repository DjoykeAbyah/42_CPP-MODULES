/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/24 16:09:12 by dreijans      #+#    #+#                 */
/*   Updated: 2024/08/20 14:42:02 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Span.cpp"

//want to use vector for dynamic resizing
//random access to elements
//works with sort, min element, max element 
//easily check current size to not exceed N

int main() {
	Span sp = Span(5);
	
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	return 0;
}