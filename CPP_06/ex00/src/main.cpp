/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/08 18:44:58 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/15 15:49:45 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


/**
 * ./convert \'$(printf '\01')\'
 */
int main(int argc, char** argv){
	if (argc != 2){
		
		char c = 'c';
		int i = 1;
		float f = 1.1f;
		double d = 1.1;

		std::cerr << "for a char ./convert "<< "\'" << c << "\'" << '\n';
		std::cerr << "for an int ./convert \""<< i << "\"" << '\n';
		std::cerr << "for an float ./convert \""<< f << "f\"" << '\n';
		std::cerr << "for an double ./convert \""<< d << "\"" << '\n';
		
		return 1;
	}

	std::string input(argv[1]);
	ScalarConverter::convert(input);
	return 0;
}
