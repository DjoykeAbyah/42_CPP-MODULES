/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/29 16:03:29 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/08 14:34:06 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Bureaucrat.hpp"
#include "../header/ShrubberyCreationForm.hpp"
#include "../header/RobotomyRequestForm.hpp"
#include "../header/PresidentialPardonForm.hpp"
#include "../header/AForm.hpp"
#include "../header/Intern.hpp"
#include <iostream>
#include <stdexcept>

int main()
{
	std::cout << "**\n\n---------------- test ----------------**" << std::endl;
	
	Intern someRandomIntern;

	
	AForm* form1 = someRandomIntern.makeForm("robotomy request", "Bender");
	AForm* form2 = someRandomIntern.makeForm("presidential pardon", "Shoplifter");
	AForm* form3 = someRandomIntern.makeForm("shrubbery creation", "Lawn");
	AForm* form4 = someRandomIntern.makeForm("dietary restriction", "Donut"); //form an intern can't create
	std::cout << '\n';
	
	try
	{
		
		Bureaucrat boss("Boss", 1);
		std::cout << boss << std::endl;
		std::cout << '\n';
		
		boss.signForm(*form1);
		boss.signForm(*form2);
		boss.signForm(*form3);
		std::cout << '\n';
		
		boss.executeForm(*form1);
		boss.executeForm(*form2);
		boss.executeForm(*form3);
		std::cout << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << BOLD_TEXT << "Exception caught: " << e.what() << RESET << std::endl;
	}
	
	delete form1;
	delete form2;
	delete form3;
	delete form4;

	return 0;
}
