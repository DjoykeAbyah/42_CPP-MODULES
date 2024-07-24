/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   easyfind.tpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/24 18:42:36 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/24 19:21:00 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "easyfind.hpp"


class ElementNotFoundException : public std::exception {
    virtual const char* what() const throw() {
        return "Element not found.";
    }
};

template<typename T>
bool easyfind(const T& container, int num) {
	const T::const_iterator it = container.begin();
	const T::const_iterator ite = container.end();

	for (it != ite; it++) {
		std::for_each(it, ite, find(num));
	}
	else
		throw ElementNotFoundException();
}