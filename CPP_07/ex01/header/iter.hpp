/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iter.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/23 16:03:24 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/23 18:41:01 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template<typename T>
void iter(T *address, T lenght, void(*func)(T*, int)) {
	std::cout << "address is " << &address << std::endl;
	std::cout << "lenght is " << lenght << std::endl;
	std::cout << "function result is ";
	func(address, lenght);
	std::cout << std::endl;
}

template<typename T>
void showArray(T *array, int size) {
	for (int i = 0; i < size; i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}