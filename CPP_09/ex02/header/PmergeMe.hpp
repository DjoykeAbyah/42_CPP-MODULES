/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/27 16:19:27 by dreijans      #+#    #+#                 */
/*   Updated: 2025/05/29 23:02:59 by djoyke        ########   odam.nl         */
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
		struct TreeNode
		{
			int 		value;
			TreeNode* 	left;
			TreeNode* 	right;
			TreeNode(int num) : value(num), left(nullptr), right(nullptr) {}
		};
		
		void _parseInput(int argc, char **argv);
		
		//ford-johnson per container
		void _fordJohnsonSortVector();
		void _fordJohnsonSortDeque();

		//binary insert vector
		TreeNode* _buildInsertionTreeVector(const std::vector<int>& min, int left, int right);
		void _traverseAndInsertVector(TreeNode* node, std::vector<int>& sorted, std::vector<std::pair<int, int>>& pairs);
		void _insertMinVector(std::vector<int>& sorted, int minValue, int correspondingMax);

		//binary insert deque
		TreeNode* _buildInsetionTreeDeque(const std::vector<int>& min, int left, int right);
		void _traverseAndInsertDeque(TreeNode* node, std::deque<int>& sorted, std::vector<std::pair<int, int>>& pairs);
		void _insertMinDeque(std::deque<int>& sorted, int minValue, int correspondingMax);
		
		//dynamic programming style Jacobsthal sequence
		std::vector<size_t> _getJacobsthalSequence(size_t n);
	
		// Display container content (generic)
		template <typename Container>
		void PmergeMe::_displayContainer(const std::string& label, const Container& container) const {
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
};