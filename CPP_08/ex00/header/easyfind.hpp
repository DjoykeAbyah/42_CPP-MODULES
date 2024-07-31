/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   easyfind.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/24 18:41:51 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/31 16:37:51 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <list>
#include <map>
#include <vector>
#include <deque>

/**
 * @note    Passing a container by reference avoids making a copy of the entire container. 
 *          Copying a container can be expensive in terms of both time and memory, 
 *          especially if the container holds a large number of elements.
 */
template<typename T>
bool easyfind(const T& container, int num);

template<typename Key, typename Value>
bool easyfind(const std::map<Key, Value>& container, int num);

class ElementNotFoundException : public std::exception {
    virtual const char* what() const throw() {
        return "Element not found.";
    }
};

#include "easyfind.tpp"