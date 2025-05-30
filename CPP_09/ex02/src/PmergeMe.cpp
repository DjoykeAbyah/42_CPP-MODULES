/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/27 16:19:52 by dreijans      #+#    #+#                 */
/*   Updated: 2025/05/30 15:13:58 by djoyke        ########   odam.nl         */
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
	return jacobsthalVector;
}

void PmergeMe::_fordJohnsonSortDeque() {
    if (_dequeData.size() <= 1) return;

    std::vector<std::pair<int, int>> pairs;
    std::vector<int> minValues;
    std::vector<int> maxValues;

    // Pair elements
    for (size_t i = 0; i + 1 < _dequeData.size(); i += 2) {
        int left = _dequeData[i];
        int right = _dequeData[i + 1];
        if (left < right) std::swap(left, right);
        pairs.push_back({left, right});
        minValues.push_back(right);
        maxValues.push_back(left);
    }
    if (_dequeData.size() % 2 == 1) {
        pairs.push_back({_dequeData.back(), -1});
        minValues.push_back(_dequeData.back());
    }

    std::sort(maxValues.begin(), maxValues.end());
    _dequeData = std::deque<int>(maxValues.begin(), maxValues.end());

    std::vector<size_t> jacobsthal = _getJacobsthalSequence(minValues.size());
    size_t previous = jacobsthal[0];

    for (size_t index : jacobsthal) {
        size_t current = index;
        while (index > previous) {
            if (index > minValues.size()) index = minValues.size();
            index--;
            _insertMinDeque(_dequeData, minValues[index], pairs[index].first);
        }
        previous = current;
    }
}

void PmergeMe::_fordJohnsonSortVector() {
	if (_vectorData.size() <= 1)
		return;
	
	std::vector<std::pair<int, int>> pairs; //max, min pair
	std::vector<int> minValues;
	std::vector<int> maxValues;

	//pair elements
	for (size_t i = 0; i + 1 < _vectorData.size(); i += 2) {
		int left = _vectorData[i];
		int right = _vectorData[i + 1];
		if (left < right) {
			std::swap(left, right); //left is now bigger than right
		}
		pairs.push_back({left, right});
		minValues.push_back(right);
		maxValues.push_back(left);
	}
	if (_vectorData.size() % 2 == 1) {
		pairs.push_back({_vectorData.back(), -1}); //last one has no pair because size uneven
		minValues.push_back(_vectorData.back());
	}

	//bst sort for maxValues/_vectorData
	std::sort(maxValues.begin(), maxValues.end());
	_vectorData = maxValues;

	//jacobsthal insertion
	std::vector<size_t> jacobsthal = _getJacobsthalSequence(minValues.size());
	// std::cout << "minvalues size = " << minValues.size() << std::endl;
	// std::cout << "min values = ";
	// print_vector(minValues);
	size_t previous = jacobsthal[0];
	// std::cout << "jacobsthal =  ";
	// for (size_t num : jacobsthal) {
	// 	std::cout << num << " ";
	// }
	// std::cout << std::endl;
	for (size_t index : jacobsthal) {
		size_t current = index; 
		while (index > previous) {
			if (index > minValues.size()) {
				index = minValues.size();
			}
			index--;
			_insertMinVector(_vectorData, minValues[index], pairs[index].first);
		}
		previous = current;
	}
}

void PmergeMe::_insertMinVector(std::vector<int>& sortedVector, int minValue, int matchingMaxValue) {
	std::cout << "min value = " << minValue << " matching value = " << matchingMaxValue << std::endl;
	auto position = std::lower_bound(sortedVector.begin(), sortedVector.end(), matchingMaxValue);
	sortedVector.insert(position, minValue);
}

void PmergeMe::_insertMinDeque(std::deque<int>& sorted, int minValue, int correspondingMax) {
    auto pos = std::lower_bound(sorted.begin(), sorted.end(), correspondingMax);
    sorted.insert(pos, minValue);
}

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

void PmergeMe::print_vector(std::vector<int> vector) {
	std::cout << "vector: ";
	for (size_t element : vector) {
		std::cout << element << " ";
	}
	std::cout << std::endl;
}