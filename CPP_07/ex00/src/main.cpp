/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/17 16:47:52 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/22 19:40:02 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main() {
	
	int a = 21;
	int b = 50;

	std::cout << "Max of " << a << " and " << b << " is ";
	std::cout << max<int>(a, b) << std::endl;
	std::cout << "Min of " << a << " and " << b << " is ";
	std::cout << min<int>(a, b) << std::endl;
	std::cout << "Swapping " << a << " and " << b << std::endl; 
	swap<int>(a, b);
	std::cout <<" a = " << a << " and b = " << b << std::endl;

	char c = 'c';
	char d = 'd';

	std::cout << "Max of " << c << " and " << d << " is ";
	std::cout << max<char>(c, d) << std::endl;
	std::cout << "Min of " << c << " and " << d << " is ";
	std::cout << min<char>(c, d) << std::endl;
	std::cout << "Swapping " << c << " and " << d << std::endl; 
	swap<char>(c, d);
	std::cout <<" c = " << c << " and d = " << d << std::endl;

	float e = 21.1f;
	float f = 5.1f;

	std::cout << "Max of " << e << " and " << f << " is ";
	std::cout << max<float>(e, f) << std::endl;
	std::cout << "Min of " << e << " and " << f << " is ";
	std::cout << min<float>(e, f) << std::endl;
	std::cout << "Swapping " << e << " and " << f << std::endl; 
	swap<float>(e, f);
	std::cout <<" e = " << e << " and d = " << f << std::endl;	
}