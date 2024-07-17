/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Base.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/17 13:39:57 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/17 15:31:23 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base(){}

Base* generate(void) {
	
	static std::random_device randomNum; //seed random number generatori it's designed for seeding
	static std::mt19937 generate(randomNum()); //Mersenne Twister RNG
	static std::uniform_int_distribution<> dis(0, 2); //range 0 to 2
	//could also have used std::rand() % 3

	switch (dis(generate)) {
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			std::cout << "something went wrong generating random numbers" << std::endl;
			return nullptr;
	}
	
}

void identify(Base *p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base &p) {
	
}

