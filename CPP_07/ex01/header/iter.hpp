/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iter.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/23 16:03:24 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/23 19:30:40 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template<typename T, typename size_t, typename U>
void iter(T *address, size_t size, U showArray) {
	for (size_t i = 0; i < size; i++) {
		showArray(address[i]);
	}
}

template<typename U>
void showArray(U element) {
	std::cout << "function result is ";
	std::cout << element << std::endl;
}