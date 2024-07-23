/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/17 16:48:18 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/23 18:41:20 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main() {
	int intArray[] = {1, 2, 3};
	char charArray[] = {'a', 'b', 'c'};
	const char *stringArray[] = {"one", "two", "three"};
	
	iter<int>(intArray, sizeof(intArray), showArray);
	iter<char>(charArray, sizeof(charArray), showArray);
	iter<char *>(stringArray, sizeof(stringArray), showArray);
}