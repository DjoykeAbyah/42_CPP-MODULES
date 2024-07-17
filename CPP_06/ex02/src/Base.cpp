/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Base.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/17 13:39:57 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/17 16:39:05 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

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
		std::cout << "this is an A class" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "this is an B class" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "this is an C class" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

/**
 * @note 	a way to explicitly discard the result of the cast. 
 * 			This indicates to the compiler and other developers that the cast is intentional 
 * 			and that the result is not needed, which prevents the unused variable warning
 */
void identify(Base &p) {
	try {
		(void) dynamic_cast<A&>(p);
		std::cout << "this is an A class" << std::endl;
		return ;
	}
	catch (const std::bad_cast&) {} //Catches the exception by reference, avoiding copying the exception object, which is more efficient
	try {
		(void) dynamic_cast<B&>(p);
		std::cout << "this is an B class" << std::endl;
		return ;
	}
	catch (const std::bad_cast&) {}
	try {
		(void) dynamic_cast<C&>(p);
		std::cout << "this is an C class" << std::endl;
		return ;
	}
	catch (const std::bad_cast&) {}
	std::cout << "Unknown type" << std::endl;
}

