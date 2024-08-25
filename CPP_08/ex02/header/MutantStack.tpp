/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MutantStack.tpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: djoyke <djoyke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/25 19:18:08 by djoyke        #+#    #+#                 */
/*   Updated: 2024/08/25 20:25:21 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack() : std::stack<T>() {}

// template<typename T, typename Container>
// MutantStack<T, Container>::MutantStack(const std::stack<T> &value) : std::stack<T>(value) {}

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack &copy) : std::stack<T, Container>(copy) {}

/*
Base Class Assignment: std::stack<T, Container>::operator=(copy); 
calls the assignment operator of the base class 
std::stack<T, Container>, 
effectively copying the internal stack data from copy to the current object.
*/
template<typename T, typename Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack &copy) {
	if (this != &copy)
		std::stack<T, Container>::operator=(copy);
	return *this;
}

template<typename T, typename Container>
MutantStack<T, Container>::~MutantStack() {}