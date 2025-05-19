/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/27 16:18:49 by dreijans      #+#    #+#                 */
/*   Updated: 2025/05/19 18:16:49 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cout << "Usage: ./RPN \"<RPN expression>\"\n";
		std::cout << "Example: ./RPN \"3 4 +\"\n";
		return 1;
	}
	
	RPN RPN;
	std::string input = argv[1];
	try {
		RPN.parseInput(input);
	}
	catch (const std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}