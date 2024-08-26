/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MutantStack.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/21 12:55:02 by dreijans      #+#    #+#                 */
/*   Updated: 2024/08/26 15:18:17 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <deque>

//allows to specify data type and underlying container type
template<typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T> {

	public:
		MutantStack();
    	MutantStack(const MutantStack& copy);
		MutantStack & operator=(const MutantStack& copy);
		~MutantStack();

		using iterator = typename std::deque<T>::iterator;
		
		iterator begin();
		iterator end();
			
};

//include implementation file
#include "MutantStack.tpp"