/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/27 16:18:49 by dreijans      #+#    #+#                 */
/*   Updated: 2025/05/17 21:20:03 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << "incorrect input" << std::endl;
		return 1;
	}
	
	RPN RPN;
	std::string input = argv[1];

	RPN.parseInput(input);
	return 0;
}