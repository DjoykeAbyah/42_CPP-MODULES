/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/29 16:03:29 by dreijans      #+#    #+#                 */
/*   Updated: 2024/06/30 18:39:08 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

//exceptions
//catch and try blocks
int main()
{
	try
	{
		//creating a default bureacrat
		Bureaucrat* bureaucrat1 = new Bureaucrat();
		std::cout << *bureaucrat1 << std::endl;
		
		//creating a parametric constructed bureaucrat
		Bureaucrat* bureaucrat2 = new Bureaucrat("Henk", 2);
		std::cout << *bureaucrat2 << std::endl;

		//cleanup
		delete bureaucrat1;
		delete bureaucrat2;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
