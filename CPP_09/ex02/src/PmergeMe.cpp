/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/27 16:19:52 by dreijans      #+#    #+#                 */
/*   Updated: 2025/05/30 00:12:41 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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

std::vector<size_t> PmergeMe::_getJacobsthalSequence(size_t num) {
	std::vector<size_t> sequence;
	if (num == 0) {
		return sequence;
	}

	std::vector<size_t> jacobsthalVector;
	jacobsthalVector.push_back(1);
	
	//build sequence [1, 3, 5, 11, ...] etc
	size_t current = 1;
	size_t followUp = 3;
	while (current < num) {
		jacobsthalVector.push_back(followUp);
		size_t temp = followUp;
		followUp = followUp + 2 * current;
		current = temp;
	}

	//marks indices to not used (false)
	std::vector<bool> usedElements(num, false);
	//For each Jacobsthal number num, check if it’s ≤ n and hasn’t been added yet (!used[num-1]).
	//Add num-1 to the sequence (because Jacobsthal numbers start at 1, but indices are 0-based).
	//Example for n=6: Jacobsthal numbers: [1, 3, 5]. It adds indices: 0 (1-1), 2 (3-1), 4 (5-1).
	for (size_t element : jacobsthalVector) {
		if (element <= num && !usedElements[element - 1]) {
			sequence.push_back(element - 1);
			usedElements[element - 1] = true;		
		}
	}

	for (size_t i = 0; i < num; i++) {
		if (!usedElements[i]) {
			sequence.push_back(i);
		}
	}
	return sequence;
}

void PmergeMe::_fordJohnsonSortVector() {
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

	//jacobsthal insertion
	std::vector<size_t> jacobsthal = _getJacobsthalSequence(minValues.size());
	for (size_t index : jacobsthal) {
		if (index < minValues.size()) {
			int minValue = minValues[index];
			int matchingMaxValue = pairs[index].first;
			_insertMinVector(_vectorData, minValue, matchingMaxValue);
		}
	}
}

//_buildMinBST
//_collectMinNodesInJacobOrder


void PmergeMe::_insertMinVector(std::vector<int>& sortedVector, int minValue, int matchingMaxValue) {
	auto position = std::lower_bound(sortedVector.begin(), sortedVector.end(), matchingMaxValue);
	sortedVector.insert(position, minValue);
}

//_inserMinDeque

void PmergeMe::sort() {
	_displayContainer("Before", _vectorData); //both are the same at this point
	
	//capture timestamp
	auto startVectorTime = std::chrono::high_resolution_clock::now();
	_fordJohnsonSortVector();
	auto endVectorTime = std::chrono::high_resolution_clock::now();
	
	//capture timestamp
	auto startDequeTime = std::chrono::high_resolution_clock::now();
	_fordJohnsonSortDeque();
	auto endDequeTime = std::chrono::high_resolution_clock::now();

	_displayContainer("After Vector", _vectorData);
	_displayContainer("After Deque", _dequeData);

	//duration in microseconds
	auto vectorTime = std::chrono::duration<double, std::micro>(endVectorTime - startVectorTime).count();
	auto dequeTime = std::chrono::duration<double, std::micro>(endDequeTime - startDequeTime).count();
	
	std::cout << "Total time of process of size " << _vectorData.size() << " with a vector: " << vectorTime << "us\n ";
	std::cout << "Total time of process of size " << _dequeData.size() << " with a deque: " << dequeTime << "us\n";
}


// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        ::::::::            */
// /*   PmergeMe.cpp                                       :+:    :+:            */
// /*                                                     +:+                    */
// /*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
// /*                                                   +#+                      */
// /*   Created: 2024/08/27 16:19:52 by dreijans      #+#    #+#                 */
// /*   Updated: 2025/05/29 23:17:52 by djoyke        ########   odam.nl         */
// /*                                                                            */
// /* ************************************************************************** */

// #include "PmergeMe.hpp"

// PmergeMe::PmergeMe(int argc, char **argv) {
// 	_parseInput(argc, argv);
// }

// PmergeMe::PmergeMe(const PmergeMe& copy) : _vectorData(copy._vectorData), _dequeData(copy._dequeData) {}

// PmergeMe& PmergeMe::operator=(const PmergeMe& copy) {
// 	if (this != &copy) {
// 		_vectorData = copy._vectorData;
// 		_dequeData = copy._dequeData;
// 	}
// 	return *this;
// }

// PmergeMe::~PmergeMe() = default;

// void PmergeMe::_parseInput(int argc, char** argv) {
// 	for (int i = 1; i < argc; i++) {
// 		std::string argument(argv[i]);
// 		for (char c : argument) {
// 			if (!std::isdigit(c))
// 				throw std::invalid_argument("Argument is not a digit");
// 		}
// 		int num = std::stoi(argument);
// 		if (num <= 0)
// 			throw std::invalid_argument("Argument is not a positive digit");
		
// 		_vectorData.push_back(num);
// 		_dequeData.push_back(num);
// 	}
// }

// void PmergeMe::sort() {
// 	_displayContainer("Before", _vectorData); //both are the same at this point
	
// 	//capture timestamp
// 	auto startVectorTime = std::chrono::high_resolution_clock::now();
// 	//ford johnson algorithm here for vector
// 	_fordJohnsonSortVector();
// 	auto endVectorTime = std::chrono::high_resolution_clock::now();
	
// 	//capture timestamp
// 	auto startDequeTime = std::chrono::high_resolution_clock::now();
// 	_fordJohnsonSortDeque();
// 	auto endDequeTime = std::chrono::high_resolution_clock::now();

// 	_displayContainer("After Vector", _vectorData);
// 	_displayContainer("After Deque", _dequeData);

// 	//duration in microseconds
// 	auto vectorTime = std::chrono::duration<double, std::micro>(endVectorTime - startVectorTime).count();
// 	auto dequeTime = std::chrono::duration<double, std::micro>(endDequeTime - startDequeTime).count();
	
// 	std::cout << "Total time of process of size " << _vectorData.size() << " with a vector: " << vectorTime << "us\n ";
// 	std::cout << "Total time of process of size " << _dequeData.size() << " with a deque: " << dequeTime << "us\n";
// }

// void PmergeMe::_fordJohnsonSortVector() {
// 	if (_vectorData.size() <= 1)
// 		return;
	
// 	std::vector<std::pair<int, int>> pairs; //max, min pair
// 	std::vector<int> minValues;

// 	//pair elements
// 	for (size_t i = 0; i + 1 < _vectorData.size(); i += 2) {
// 		int left = _vectorData[i];
// 		int right = _vectorData[i + 1];
// 		if (left < right) {
// 			std::swap(left, right); //left is now bigger than right
// 		}
// 		pairs.push_back({left, right});
// 		minValues.push_back(right);
// 	}
// 	if (_vectorData.size() % 2 == 1) {
// 		pairs.push_back({_vectorData.back(), -1}); //last one has no pair because size uneven
// 	}
	
// 	//sort max elements
// 	std::vector<int> maxValues;
// 	for (auto& pair : pairs) {
// 		maxValues.push_back(pair.first);
// 		std::sort(maxValues.begin(), maxValues.end());
// 		_vectorData = maxValues;
// 	}

// 	//build insertion tree and insert minValues
// 	TreeNode* root = _buildInsertionTreeVector(minValues, 0, minValues.size() - 1);
// 	_traverseAndInsertVector(root, _vectorData, pairs);
// 	//need to free memory?
// }

// PmergeMe::TreeNode* PmergeMe::_buildInsertionTreeVector(const std::vector<int>& min, int left, int right) {
// 	//base case
// 	if (left > right) {
// 		return nullptr;
// 	}
	
// 	size_t middle = (left + right) / 2;
// 	TreeNode* node = new TreeNode(min[middle]);

// 	node->left = _buildInsertionTreeVector(min, left, middle - 1); //start from left side from vector to new middle
// 	node->right = _buildInsertionTreeVector(min, middle + 1, right); //start is middle + 1 to right side of vector
// 	return node;
// }

// void PmergeMe::_traverseAndInsertVector(TreeNode* node, std::vector<int>& sortedVector, std::vector<std::pair<int, int>>& pairs) {
// 	//base case
// 	if (!node) {
// 		return;
// 	}
	
// 	//find max for min value
// 	for (auto& pair : pairs) {
// 		if (pair.second == node->value) {
// 			_insertMinVector(sortedVector, node->value, pair.first); //insert min before paired max
// 			break;
// 		}
// 	}
// 	//recursive process left and right
// 	_traverseAndInsertVector(node->left, sortedVector, pairs);
// 	_traverseAndInsertVector(node->right, sortedVector, pairs);
// }

// void PmergeMe::_insertMinVector(std::vector<int>& sortedVector, int minValue, int matchingMaxValue) {
// 	auto position = std::lower_bound(sortedVector.begin(), sortedVector.end(), matchingMaxValue);
// 	sortedVector.insert(position, minValue);
// }