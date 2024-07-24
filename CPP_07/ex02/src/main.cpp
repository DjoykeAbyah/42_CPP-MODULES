/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/17 16:48:46 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/24 16:06:50 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Array.hpp"

/**
 * @todo how to test if deep copy?
 */
int main() {
	
	std::cout << BOLD_TEXT MAGENTA "\n\ntesting int arrays\n\n" RESET << std::endl;
	Array<int> intArray1; //empty array
	Array<int> intArray2(5); //array with 5 elements to default.
	
	try {
		std::cout << "Size of intArray1: " << intArray1.size() << std::endl;
		std::cout << "Size of intArray2: " << intArray2.size() << std::endl;
		
		for (int i = 0; i < intArray2.size(); i++)
			intArray2[i] = i * 10;

		std::cout << "intArray2 = " << intArray2 << std::endl;

		//accessing out of bounds element
		std::cout << MAGENTA "Trying to access out of bounds element intArray2:" RESET << std::endl;
		std::cout << intArray2[10] << std::endl; //should throw exception
	}
	catch (const std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << MAGENTA "Trying the copy constructor and assignment overloader" RESET << std::endl;
	
	Array<int>intArray3 = intArray2; //copy constructor called
	intArray1 = intArray3;// assignment overloader called
	std::cout << "intArray3 = " << intArray3 << std::endl;
	std::cout << "intArray1 = " << intArray1 << std::endl;
	
	std::cout << MAGENTA "Trying to access out of bounds element intArray1:" RESET << std::endl;
	try {
		intArray1[2];
	}
	catch (const std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << BOLD_TEXT CYAN "\n\ntesting char arrays\n\n" RESET << std::endl;
	Array<char> charArray1; //empty array
	Array<char> charArray2(5); //array with 5 elements to default.
	
	try {
		std::cout << "Size of charArray1: " << charArray1.size() << std::endl;
		std::cout << "Size of charArray2: " << charArray2.size() << std::endl;
		
		for (int i = 0; i < charArray2.size(); i++)
			charArray2[i] = 'a' + i;

		std::cout << "charArray2 = " << charArray2 << std::endl;

		//accessing out of bounds element
		std::cout << CYAN "Trying to access out of bounds element charArray2:" RESET << std::endl;
		std::cout << charArray2[10] << std::endl; //should throw exception
	}
	catch (const std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << CYAN "Trying the copy constructor and assignment overloader" RESET << std::endl;
	
	Array<char>charArray3 = charArray2; //copy constructor called
	charArray1 = charArray3;// assignment overloader called
	std::cout << "charArray3 = " << charArray3 << std::endl;
	std::cout << "charArray1 = " << charArray1 << std::endl;
	
	std::cout << CYAN "Trying to access out of bounds element charArray1:" RESET << std::endl;
	try {
		charArray1[2];
	}
	catch (const std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << BOLD_TEXT ORANGE "\n\ntesting string arrays\n\n" RESET << std::endl;
	Array<std::string> stringArray1; //empty array
	Array<std::string> stringArray2(5); //array with 5 elements to default.
	
	try {
		std::cout << "Size of stringArray1: " << stringArray1.size() << std::endl;
		std::cout << "Size of stringArray2: " << stringArray2.size() << std::endl;
		
		for (int i = 0; i < stringArray2.size(); i++) {
			if (i % 2 == 0)
				stringArray2[i] = "even";
			else
				stringArray2[i] = "uneven";
		}

		std::cout << "stringArray2 = " << stringArray2 << std::endl;

		//accessing out of bounds element
		std::cout << ORANGE "Trying to access out of bounds element stringArray2:" RESET << std::endl;
		std::cout << stringArray2[10] << std::endl; //should throw exception
	}
	catch (const std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << ORANGE "Trying the copy constructor and assignment overloader" RESET << std::endl;
	
	Array<std::string>stringArray3 = stringArray2; //copy constructor called
	stringArray1 = stringArray3;// assignment overloader called
	std::cout << "stringArray3 = " << stringArray3 << std::endl;
	std::cout << "stringArray1 = " << stringArray1 << std::endl;
	
	std::cout << ORANGE "Trying to access out of bounds element stringArray1:" RESET << std::endl;
	try {
		stringArray1[2];
	}
	catch (const std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
	
	return 0;
}