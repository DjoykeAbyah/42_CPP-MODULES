/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/03 18:40:59 by dreijans      #+#    #+#                 */
/*   Updated: 2024/06/03 18:49:19 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string* stringPTR = &brain;
	std::string& stringREF = brain;
	
	std::cout << "memory address of brain = " << "\t" << &brain << std::endl;
	std::cout << "memory address of stringPTR = " << "\t" << stringPTR << std::endl;
	std::cout << "memory address of stringREF = " << "\t" << &stringREF << std::endl;

	std::cout << "value of brain = " << "\t" << brain << std::endl;
	std::cout << "value of stringPTR = " << "\t" << *stringPTR << std::endl;
	std::cout << "value of stringREF = " << "\t" << stringREF << std::endl;
}