/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/27 16:19:27 by dreijans      #+#    #+#                 */
/*   Updated: 2025/06/06 10:53:23 by djoyke        ########   odam.nl         */
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
#include <unordered_set>

class PmergeMe {
	private:
		std::vector<int> 	_vectorData;
		std::deque<int> 	_dequeData;

		void 				_parseInput(int argc, char **argv);
		
		//ford-johnson per container
		void 				_fordJohnsonSortVector();
		void 				_fordJohnsonSortDeque();

		//insert for vector and deque
		void 				_insertVector(std::vector<int>& sorted, int value);
		void 				_insertDeque(std::deque<int>& sorted, int value);
		
		//dynamic programming style Jacobsthal sequence
		std::vector<size_t> _getJacobsthalSequence(size_t n);
	
		// Display container content
		template <typename Container>
		void _displayContainer(const std::string& label, const Container& container) const {
			std::cout << label << ": ";
			for (size_t i = 0; i < container.size(); i++) {
				std::cout << container[i];
				if (i + 1 < container.size())
					std::cout << " "; 
			}
			std::cout << std::endl;
		}

	public:
		PmergeMe();
		PmergeMe(int argc, char **argv);
		PmergeMe(const PmergeMe& copy);
		PmergeMe& operator=(const PmergeMe& copy);
		~PmergeMe();
		
		void sort();
		void print_vector(std::vector<int> vector);
};
