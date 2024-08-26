/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/24 16:09:45 by dreijans      #+#    #+#                 */
/*   Updated: 2024/08/26 17:15:11 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

# define RESET "\033[0m"
# define ORANGE "\033[38;2;255;165;0m"

int main() {
	
	std::cout << ORANGE << "Test from subject" << RESET << std::endl;
	MutantStack<int> mstack;
	
	mstack.push(5);
	mstack.push(17);
	
	std::cout << "After pushing 5 and 17, top element is: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "After popping, stack size is: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	
	std::cout << "Final stack state:" << std::endl;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	//---------------------------------------------------------------------------------
	
	std::cout << ORANGE << "Test const" << RESET << std::endl;
	MutantStack<int> const cstack(mstack);

	std::cout << "top element is: " << cstack.top() << std::endl;
	MutantStack<int>::const_iterator cIt = cstack.cbegin();
	MutantStack<int>::const_iterator cIte = cstack.cend();
	++cIt;
	--cIt;
	
	std::cout << "Final stack state:" << std::endl;
	while (cIt != cIte) {
		std::cout << *cIt << std::endl;
		++cIt;
	}
	std::stack<int> c(cstack);

	//---------------------------------------------------------------------------------

	std::cout << ORANGE << "Test with list" << RESET << std::endl;
	MutantStack<int, std::list<int>> listStack;
	
	listStack.push(5);
	listStack.push(17);
	
	std::cout << "After pushing 5 and 17, top element is: " << listStack.top() << std::endl;
	listStack.pop();
	std::cout << "After popping, stack size is: " << listStack.size() << std::endl;
	listStack.push(3);
	listStack.push(5);
	listStack.push(737);
	listStack.push(0);
	MutantStack<int, std::list<int>>::iterator listIt = listStack.begin();
	MutantStack<int, std::list<int>>::iterator listIte = listStack.end();
	++listIt;
	--listIt;
	
	std::cout << "Final stack state:" << std::endl;
	while (listIt != listIte) {
		std::cout << *listIt << std::endl;
		++listIt;
	}
	std::stack<int> ls(listStack);

	//---------------------------------------------------------------------------------

	std::cout << ORANGE << "Test reverse" << RESET << std::endl;
	MutantStack<int> reverseStack;
	
	reverseStack.push(5);
	reverseStack.push(17);
	
	std::cout << "After pushing 5 and 17, top element is: " << reverseStack.top() << std::endl;
	reverseStack.pop();
	std::cout << "After popping, stack size is: " << reverseStack.size() << std::endl;
	reverseStack.push(3);
	reverseStack.push(5);
	reverseStack.push(737);
	reverseStack.push(0);
	MutantStack<int, std::list<int>>::reverse_iterator testIt = reverseStack.rbegin();
	MutantStack<int, std::list<int>>::reverse_iterator testIte = reverseStack.rend();
	++testIt;
	--testIt;
	
	std::cout << "Final stack state (reverse order):" << std::endl;
	while (testIt != testIte) {
		std::cout << *testIt << std::endl;
		++testIt;
	}
	std::stack<int> ts(reverseStack);

	//---------------------------------------------------------------------------------

	std::cout << ORANGE << "Test const reverse" << RESET << std::endl;
	MutantStack<int> const constStack(reverseStack);
	
	std::cout << "Top element is: " << constStack.top() << std::endl;
	std::cout << "Stack size is: " << constStack.size() << std::endl;
	MutantStack<int, std::list<int>>::const_reverse_iterator constIt = constStack.crbegin();
	MutantStack<int, std::list<int>>::const_reverse_iterator constIte = constStack.crend();
	++constIt;
	--constIt;
	
	std::cout << "Final stack state const (reverse):" << std::endl;
	while (constIt != constIte) {
		std::cout << *constIt << std::endl;
		++constIt;
	}
	std::stack<int> cs(constStack);

	return 0;
}
