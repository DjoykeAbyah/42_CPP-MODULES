/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MutantStack.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/21 12:55:02 by dreijans      #+#    #+#                 */
/*   Updated: 2024/08/26 16:58:45 by dreijans      ########   odam.nl         */
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

		using reverse_iterator = typename std::deque<T>::reverse_iterator;
		
		reverse_iterator rbegin();
		reverse_iterator rend();

		using const_iterator = typename std::deque<T>::const_iterator;
		
		const_iterator cbegin() const;
		const_iterator cend() const;

		using const_reverse_iterator = typename std::deque<T>::const_reverse_iterator;
		
		const_reverse_iterator crbegin() const;
		const_reverse_iterator crend() const;	
};

//include implementation
#include "MutantStack.tpp"