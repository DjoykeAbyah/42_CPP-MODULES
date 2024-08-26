/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MutantStack.tpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: djoyke <djoyke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/25 19:18:08 by djoyke        #+#    #+#                 */
/*   Updated: 2024/08/26 15:18:44 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack() : std::stack<T>() {}

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
	if (this != &copy)//comparing addresses
		std::stack<T, Container>::operator=(copy);
	//This calls the assignment operator of the base class 
	//(std::stack<T, Container>), which does the actual copying 
	//of the stack contents from copy to the current object
	return *this;
}

template<typename T, typename Container>
MutantStack<T, Container>::~MutantStack() {}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin() {
	return this->c.begin();
}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end() {
	return this->c.end();
}