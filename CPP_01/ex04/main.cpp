/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/04 18:16:12 by dreijans      #+#    #+#                 */
/*   Updated: 2024/06/06 22:42:47 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "sed.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Enter executable, filename, word, and word to replace with" << std::endl;
		return 1;
	}
	
	std::string filename = argv[1];
	std::string word = argv[2];
	std::string replaceWord = argv[3];

	WordReplacer replacer(filename, word, replaceWord);
	
	if (!replacer.validateInput())
		return 1;
	if (!replacer.processFile())
		return 1;
		
	return 0;
}