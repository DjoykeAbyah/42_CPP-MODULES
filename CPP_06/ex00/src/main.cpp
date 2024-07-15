/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/08 18:44:58 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/15 14:26:06 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char** argv){
	if (argc != 2){
		std::cerr << "input: convert 'char/int/float or double'" << std::endl;
		return 1;
	}

	std::string input(argv[1]);
	ScalarConverter::convert(input);
	return 0;
}
