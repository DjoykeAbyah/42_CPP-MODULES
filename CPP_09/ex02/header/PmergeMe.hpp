/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/27 16:19:27 by dreijans      #+#    #+#                 */
/*   Updated: 2025/05/24 14:41:54 by djoyke        ########   odam.nl         */
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

		//ford-johnson per container
		std::vector<int> _fordJonsonVector(const std::vector<int>& input);
		std::deque<int> _fordJonsonDeque(const std::deque<int>& input);
		
		//sorting logic template
		template <typename T>
		T _fordJohnsonSort(const T& input);

		//dynamic programming style Jacobsthal sequence
		std::vector<size_t> _getJacobsthalSequence(size_t n);

		template <typename T>
		void _binaryInsert(T& container, typename T::value_type value, size_t maxIndex);
	
		void _parseInput(int argc, char **argv);
		void _displayBefore() const;
		void _displayAfter(const std::vector<int>& result) const;	

	public:
		PmergeMe(int argc, char **argv);
		PmergeMe(const PmergeMe& copy);
		PmergeMe& operator=(const PmergeMe& copy);
		~PmergeMe();
		
		void sort();
};