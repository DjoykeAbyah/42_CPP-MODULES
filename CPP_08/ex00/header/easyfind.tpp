/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   easyfind.tpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/24 18:42:36 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/31 14:03:24 by dreijans      ########   odam.nl         */
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