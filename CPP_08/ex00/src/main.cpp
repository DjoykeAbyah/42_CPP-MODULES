/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/24 16:08:35 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/24 19:48:06 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main() {

	std::vector<int> 	myVector(10,5); //10 entries with 5 as value
	std::list<int> 		myList = {20, 10, 5, 6, 2};
	std::map<int, 		std::string> Mymap = {{30, "thirty"}, {10, "ten"},  {2, "two"}, {6, "six"}};
	std::deque<int> 	myDeque = {20, 10, 5, 6, 2};
	
	try {
		easyfind(myVector, 5);
	}
	catch (const std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
	
	return 0;
}