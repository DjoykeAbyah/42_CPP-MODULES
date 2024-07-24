/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   easyfind.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/24 18:41:51 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/24 19:54:37 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <map>
#include <deque>

/**
 * @todo		why use reference
 */
template<typename T>
bool easyfind(const T& container, int num);

class ElementNotFoundException : public std::exception {
    virtual const char* what() const throw() {
        return "Element not found.";
    }
};

#include "easyfind.tpp"