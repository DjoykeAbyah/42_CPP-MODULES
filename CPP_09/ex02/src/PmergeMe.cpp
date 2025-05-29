/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/27 16:19:52 by dreijans      #+#    #+#                 */
/*   Updated: 2025/05/29 22:53:23 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//pairing elements
//recursively sorting max values
//insert min values into sorted list using jacobsthal sequence

PmergeMe::PmergeMe(int argc, char **argv) {
	_parseInput(argc, argv);
}

PmergeMe::PmergeMe(const PmergeMe& copy) : _vectorData(copy._vectorData), _dequeData(copy._dequeData) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& copy) {
	if (this != &copy) {
		_vectorData = copy._vectorData;
		_dequeData = copy._dequeData;
	}
	return *this;
}

PmergeMe::~PmergeMe() = default;

void PmergeMe::_parseInput(int argc, char** argv) {
	for (int i = 1; i < argc; i++) {
		std::string argument(argv[i]);
		for (char c : argument) {
			if (!std::isdigit(c))
				throw std::invalid_argument("Argument is not a digit");
		}
		int num = std::stoi(argument);
		if (num <= 0)
			throw std::invalid_argument("Argument is not a positive digit");
		
		_vectorData.push_back(num);
		_dequeData.push_back(num);
	}
}

void PmergeMe::sort() {
	_displayContainer("Before", _vectorData); //both are the same at this point
	
	//capture timestamp
	auto startVectorTime = std::chrono::high_resolution_clock::now();
	//ford johnson algorithm here for vector
	_fordJonsoSortVector();
	auto endVectorTime = std::chrono::high_resolution_clock::now();
	
	//capture timestamp
	auto startDequeTime = std::chrono::high_resolution_clock::now();
	_fordJonsonSortDeque();
	auto endDequeTime = std::chrono::high_resolution_clock::now();

	_displayContainer("After Vector", _vectorData);
	_displayContainer("After Deque", _dequeData);

	//duration in microseconds
	auto vectorTime = std::chrono::duration<double, std::micro>(endVectorTime - startVectorTime).count();
	auto dequeTime = std::chrono::duration<double, std::micro>(endDequeTime - startDequeTime).count();
	
	std::cout << "Total time of process of size " << _vectorData.size() << " with a vector: " << vectorTime << "us\n ";
	std::cout << "Total time of process of size " << _dequeData.size() << " with a deque: " << dequeTime << "us\n";
}

void PmergeMe::_fordJonsoSortVector() {
	if (_vectorData.size() <= 1)
		return;
	
	std::vector<std::pair<int, int>> pairs; //max, min pair
	std::vector<int> minValues;

	//pair elements
	for (size_t i = 0; i + 1 < _vectorData.size(); i += 2) {
		int left = _vectorData[i];
		int right = _vectorData[i + 1];
		if (left < right) {
			std::swap(left, right); //left is now bigger than right
		}
		pairs.push_back({left, right});
		minValues.push_back(right);
	}
	if (_vectorData.size() % 2 == 1) {
		pairs.push_back({_vectorData.back(), -1}); //last one has no pair because size uneven
	}
	
	//sort max elements
	std::vector<int> maxValues;
	for (auto& pair : pairs) {
		maxValues.push_back(pair.first);
		std::sort(maxValues.begin(), maxValues.end());
		_vectorData = maxValues;
	}

	//build insertion tree and insert minValues
	TreeNode* root = _buildInsetionTreeVector(minValues, 0, minValues.size() - 1);
	_traverseAndInsertVector(root, _vectorData, pairs);
	//need to free memoiry?
}

PmergeMe::TreeNode* PmergeMe::_buildInsetionTreeVector(const std::vector<int>& min, int left, int right) {
	//base case
	if (left > right) {
		return nullptr;
	}
	
	size_t middle = (left + right) / 2;
	TreeNode* node = new TreeNode(min[middle]);

	node->left = _buildInsetionTreeVector(min, left, middle - 1); //start from left side from vector to new middle
	node->right = _buildInsetionTreeVector(min, middle + 1, right); //start is middle + 1 to right side of vector
	return node;
}