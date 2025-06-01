/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/17 16:48:18 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/23 19:27:30 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main() {
	
	int intArray[] = {40, 41, 42};
	float floatArray[] = {20.1f, 21.1f, 22.1f};
	char charArray[] = {'a', 'b', 'c'};
	std::string stringArray[] = {"one", "two", "three"};
	
	int size = 3;
	
	iter(intArray, size, showArray<int>);
	iter(floatArray, size, showArray<float>);
	iter(charArray, size, showArray<char>);
	iter(stringArray, size, showArray<std::string>);
}