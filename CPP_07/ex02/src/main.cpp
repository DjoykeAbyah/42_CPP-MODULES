/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/17 16:48:46 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/24 15:32:00 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Array.hpp"

/**
 * try to compile int * a = new int() then display *a
 */
int main() {
	
	Array<int> intArray1; //empty array
	Array<int> intArray2(5); //array with 5 elements to default.
	
	try {
		std::cout << "Size of intArray1: " << intArray1.size() << std::endl;
		std::cout << "Size of intArray2: " << intArray2.size() << std::endl;
		
		for (int i = 0; i < intArray2.size(); i++)
			intArray2[i] = i * 10;

		std::cout << intArray2 << std::endl;

		//accessing out of bounds element
		std::cout << "Trying to access out of bounds element intArray2:" << std::endl;
		std::cout << intArray2[10] << std::endl; //should throw exception
	}
	catch (const std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
	
	std::cout << "Trying to access out of bounds element intArray1:" << std::endl;
	try {
		intArray1[2];
	}
	catch (const std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
	
	return 0;
}