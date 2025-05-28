/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/27 16:19:27 by dreijans      #+#    #+#                 */
/*   Updated: 2025/05/28 18:16:10 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <stdexcept>
#include <sstream>
#include <chrono>
#include <algorithm>
#include <cctype>
#include <iterator>

//able to use positive int sequence as argument
//must merge-insert sort algorithm to sort positive int sequence
//need to use Ford-Johnson algortihm
//if error occurs message should be displayed on stdout
//use 2 different containers in code to validate
//program must be able to handle 3000 different ints at least
//implement algoritm for each container and avoid using generic function
//show difference between the two containers used in output
//show time used to perform operations

//each min element must be inserted only before its paired max

//class doesnt store state so could make it static.
class PmergeMe {
	private:
		std::vector<int> 	_vectorData;
		std::deque<int> 	_dequeData;

		void _parseInput(int argc, char **argv);
		
		//ford-johnson per container
		void _fordJonsoSortVector();
		void _fordJonsonSortDeque();

		//binary insert per container
		void _binaryInsertVector(int value, size_t maxIndex);
		void _binaryInsertDeque(int value, size_t maxIndex);
		
		//dynamic programming style Jacobsthal sequence
		std::vector<size_t> _getJacobsthalSequence(size_t n);
	
		void _displayContainerVector() const;
		void _displayContainerDeque() const;

	public:
		PmergeMe(int argc, char **argv);
		PmergeMe(const PmergeMe& copy);
		PmergeMe& operator=(const PmergeMe& copy);
		~PmergeMe();
		
		void sort();
};