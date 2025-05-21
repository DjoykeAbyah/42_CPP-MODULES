/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/27 16:19:27 by dreijans      #+#    #+#                 */
/*   Updated: 2025/05/19 19:51:34 by djoyke        ########   odam.nl         */
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

//able to use positive int sequence as argument
//must merge-insert sort algorithm to sort positive int sequence
//need to use Ford-Johnson algortihm
//if error occurs message should be displayed on stdout
//use 2 different containers in code to validate
//program must be able to handle 3000 different ints at least
//implement algoritm for each container and avoid using generic function
//show difference between the two containers used in output
//show time used to perform operations

//class doesnt store state so could make it static.
class PmergeMe {
	private:
		std::vector<int> 	_vectorData;
		std::deque<int> 	_dequeData;
		
		void sortVector();
		void sortDeque();

		
		
};