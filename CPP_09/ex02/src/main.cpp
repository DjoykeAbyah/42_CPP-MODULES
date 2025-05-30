/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/27 16:19:49 by dreijans      #+#    #+#                 */
/*   Updated: 2025/05/30 12:59:45 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
//handle duplicates

int main(int argc, char **argv) {
	try {
		PmergeMe pmergeme(argc, argv);
		pmergeme.sort();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}