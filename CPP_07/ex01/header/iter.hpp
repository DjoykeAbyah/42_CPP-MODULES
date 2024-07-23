/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iter.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/23 16:03:24 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/23 18:11:38 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template<typename T>
void iter(T *address, T lenght, T *()) {
	std::cout << "address is " << &address << std::endl;
	std::cout << "lenght is " << lenght << std::endl;
	std::cout << "function result is" << *() << std::endl;
}

template<typename T>
T showArray(T *array, T lenght) {
	for (int i = 0; i < lenght; i++)
		std::cout << array[i] << std::endl;
}