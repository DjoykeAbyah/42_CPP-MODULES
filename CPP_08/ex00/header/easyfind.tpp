/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   easyfind.tpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/24 18:42:36 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/31 18:28:52 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "easyfind.hpp"

template<typename T>
bool easyfind(const T& container, int num) {

	typename T::const_iterator it = std::find(container.begin(), container.end(), num);
	if (it == container.end()) {
		throw ElementNotFoundException();
	}
	return true;
}

template<typename Key, typename Value>
bool easyfind(const std::map<Key, Value>& container, int num) {

	for (auto& pair : container) { //range based for loop
		if (pair.second == num)
			return true;
	}
	throw ElementNotFoundException();
}