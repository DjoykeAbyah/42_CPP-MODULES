/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/24 16:08:35 by dreijans      #+#    #+#                 */
/*   Updated: 2024/08/27 18:28:02 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main() {

	std::vector<int> 	myVector(10, 0); //10 entries with 5 as value
	std::list<int> 		myList = {0,0,0,0,0};
    std::map<std::string, int> myMap = {
        {"thirty", 30},
        {"ten", 10},
        {"two", 2},
        {"six", 6}
    };	
	std::deque<int> 	myDeque = {20, 10, 5, 6, 2};
	
	try {
		easyfind(myVector, 5);
		std::cout << "Element found!" << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	try {
		easyfind(myVector, 6);
		std::cout << "Element found!" << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	try {
		easyfind(myList, 5);
		std::cout << "Element found!" << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	try {
		easyfind(myMap, 10);
		std::cout << "Element found!" << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	try {
		easyfind(myDeque, 5);
		std::cout << "Element found!" << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
	
	return 0;
}