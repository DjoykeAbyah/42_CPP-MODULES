/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/08 18:46:16 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/17 16:43:07 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main() {

	std::cout << '\n' << "testing identify with Base &p function" << '\n' << std::endl;
	A a;
	B b;
	C c;

	Base& ref1 = a;
	Base& ref2 = b;
	Base& ref3 = c;

	identify(ref1);
	identify(ref2);
	identify(ref3);
	
	std::cout << '\n' << "testing identify with Base *p function" << '\n' << std::endl;
	for (int i = 0; i < 10; i++)
	{
		Base * object = generate();
		if (object)
		{
			identify(*object);
			delete object;
		}	
	}
	return 0;
	
}