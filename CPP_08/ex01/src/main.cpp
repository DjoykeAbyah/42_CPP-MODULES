/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/24 16:09:12 by dreijans      #+#    #+#                 */
/*   Updated: 2024/08/20 18:42:42 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Span.hpp"
#include <iostream>
#include <random>
#include <iterator>

# define RESET "\033[0m"
# define BLUE "\033[34m"

/**
 * @todo 
 * 			- for 10.000 longest span check min and max 
 * 			to see if it works.
 * 			- add more tests
 */
int main() {
	std::cout << BLUE << "test with 5 numbers\n" << RESET << std::endl;
	Span sp = Span(5);
	
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	Span bigSpan = Span(10000);
	
	std::mt19937 range; //random number generator
	range.seed(std::random_device()());

	std::cout << BLUE << "\ntest with 10.000 random created numbers\n" << RESET << std::endl;
	std::generate_n(std::back_inserter(bigSpan.getVector()), 10000, range);
	
	std::cout << "min num: " << *std::min_element(bigSpan.getVector().begin(), bigSpan.getVector().end()) << std::endl;
	std::cout << "max num: " << *std::max_element(bigSpan.getVector().begin(), bigSpan.getVector().end()) << std::endl;
	std::cout << "shortest bigSpan: " << bigSpan.shortestSpan() << std::endl;
	std::cout << "longest bigSpan: " << bigSpan.longestSpan() << std::endl;
	
	return 0;
}