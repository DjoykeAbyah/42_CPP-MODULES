/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MutantStack.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/21 12:55:02 by dreijans      #+#    #+#                 */
/*   Updated: 2024/08/25 19:20:20 by djoyke        ########   odam.nl         */
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
		MutantStack(const MutantStack &copy);
		MutantStack<T> &operator=(const MutantStack &copy);
		~MutantStack();
			
};

//include implementation file
#include "MutantStack.tpp"