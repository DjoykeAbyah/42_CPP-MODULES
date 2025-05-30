/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/27 16:19:27 by dreijans      #+#    #+#                 */
/*   Updated: 2025/05/30 15:04:36 by djoyke        ########   odam.nl         */
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

//handle duplicates
class PmergeMe {
	private:
		std::vector<int> 	_vectorData;
		std::deque<int> 	_dequeData;

		void 				_parseInput(int argc, char **argv);
		
		//ford-johnson per container
		void 				_fordJohnsonSortVector();
		void 				_fordJohnsonSortDeque();

		//binary insert vector and deque
		void 				_insertMinVector(std::vector<int>& sorted, int minValue, int correspondingMax);
		void 				_insertMinDeque(std::deque<int>& sorted, int minValue, int correspondingMax);
		
		//dynamic programming style Jacobsthal sequence
		std::vector<size_t> _getJacobsthalSequence(size_t n);
	
		// Display container content (generic)
		template <typename Container>
		void _displayContainer(const std::string& label, const Container& container) const {
			std::cout << label << ": ";
			for (size_t i = 0; i < container.size(); i++) {
				std::cout << container[i];
				if (i + 1 < container.size())
					std::cout << " ";  // Separate elements with a space
			}
			std::cout << std::endl;  // Newline at the end
		}

	public:
		PmergeMe(int argc, char **argv);
		PmergeMe(const PmergeMe& copy);
		PmergeMe& operator=(const PmergeMe& copy);
		~PmergeMe();
		
		void sort();
		void print_vector(std::vector<int> vector);
};
