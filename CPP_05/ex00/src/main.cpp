/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/29 16:03:29 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/03 12:10:52 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

int main()
{
	std::cout << "** creating valid bureacrats **" << std::endl;
	try
	{
		//creating a default bureaucrat
		Bureaucrat* bureaucrat1 = new Bureaucrat();
		std::cout << *bureaucrat1 << std::endl;
		
		//creating a parametric constructed valid bureaucrat
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

	std::cout << "** creating a bureacrat with grade too low **" << std::endl;
	try
	{
		//creating a bureaucrat with too low grade
		Bureaucrat* wrongBureaucrat1 = new Bureaucrat("Kees", 180);
		std::cout << *wrongBureaucrat1 << std::endl;

		//cleanup
		delete wrongBureaucrat1;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "** creating a bureacrat with grade to high **" << std::endl;
	try
	{
		//creating a bureaucrat with too high grade
		Bureaucrat* bureaucrat2 = new Bureaucrat("Kees", 0);
		std::cout << *bureaucrat2 << std::endl;

		//cleanup
		delete bureaucrat2;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	Bureaucrat Sally("Sally", 50);
	std::cout << "** promoting Sally **" << std::endl;
	try
	{
		Sally.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "** test if promotion succeeds if Sally is already at the top **" << std::endl;
	Sally.setGrade(1);
	std::cout << Sally << std::endl;
	
	try
	{
		Sally.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "** Sally was set on an improvement plan she's at the bottom now**" << std::endl;
	Sally.setGrade(149);
	std::cout << Sally << std::endl;

	std::cout << "** demoting Sally **" << std::endl;
	try
	{
		Sally.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "** demoting Sally again**" << std::endl;
	std::cout << Sally << std::endl;
	try
	{
		Sally.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
