/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/29 16:03:29 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/04 19:42:23 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Bureaucrat.hpp"
#include "../header/ShrubberyCreationForm.hpp"
#include "../header/RobotomyRequestForm.hpp"
#include "../header/PresidentialPardonForm.hpp"
#include "../header/AForm.hpp"
#include <iostream>
#include <stdexcept>

int main()
{
	std::cout << "**\n\n---------------- creating valid forms ----------------**" << std::endl;
	try
	{
		ShrubberyCreationForm form1("Kitchen");
		std::cout << form1 << std::endl;
		PresidentialPardonForm form2("Criminal");
		std::cout << form2 << std::endl;
		RobotomyRequestForm form3("Ron");
		std::cout << form3 << std::endl;
		std::cout << '\n';
		
		Bureaucrat boss("Boss", 1);
		std::cout << boss << std::endl;
		std::cout << '\n';
		
		boss.signForm(form1);
		boss.signForm(form2);
		boss.signForm(form3);
		std::cout << '\n';
		
		boss.executeForm(form1);
		boss.executeForm(form2);
		boss.executeForm(form3);
		std::cout << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << BOLD_TEXT << "Exception caught: " << e.what() << RESET << std::endl;
	}
	
	std::cout << "**\n\n---------------- creating form bureaucrat can't sign ----------------**" << std::endl;
    try 
	{
		ShrubberyCreationForm form1("Garden");
		std::cout << form1 << std::endl;
		PresidentialPardonForm form2("Shoplifter");
		std::cout << form2 << std::endl;
		RobotomyRequestForm form3("Toaster");// output changes because of random generator
		std::cout << form3 << std::endl;
		std::cout << '\n';

		Bureaucrat newbie("Newbie", 150);
		std::cout << newbie << std::endl;
		std::cout << '\n';

		newbie.signForm(form1);
		newbie.signForm(form2);
		newbie.signForm(form3);
		std::cout << '\n';
		
		newbie.executeForm(form1);
		newbie.executeForm(form2);
		newbie.executeForm(form3);
		std::cout << '\n';
    }
    catch (const std::exception& e) 
	{
        std::cerr << BOLD_TEXT << "Exception caught: " << e.what() << RESET << std::endl;
    }

	std::cout << "**\n\n---------------- creating Shrubbery form can't execute ----------------**" << std::endl;
    try 
	{
		ShrubberyCreationForm form1("Garden");
		std::cout << form1 << std::endl;
		std::cout << '\n';

		Bureaucrat newbie1("Newbie1", 145);
		Bureaucrat newbie2("Newbie2", 140);
		std::cout << newbie1 << std::endl;
		std::cout << newbie2 << std::endl;
		std::cout << '\n';

		newbie1.signForm(form1);
		std::cout << '\n';
		
		newbie2.executeForm(form1);
		std::cout << '\n';
    }
    catch (const std::exception& e) 
	{
        std::cerr << BOLD_TEXT << "Exception caught: " << e.what() << RESET << std::endl;
    }

	std::cout << "**\n\n---------------- creating Robotomy form can't execute ----------------**" << std::endl;
    try 
	{
		RobotomyRequestForm form1("Microwave");
		std::cout << form1 << std::endl;
		std::cout << '\n';

		Bureaucrat newbie1("Newbie1", 70);
		Bureaucrat newbie2("Newbie2", 60);
		std::cout << newbie1 << std::endl;
		std::cout << newbie2 << std::endl;
		std::cout << '\n';

		newbie1.signForm(form1);
		std::cout << '\n';
		
		newbie2.executeForm(form1);
		std::cout << '\n';
    }
    catch (const std::exception& e) 
	{
        std::cerr << BOLD_TEXT << "Exception caught: " << e.what() << RESET << std::endl;
    }
	
	std::cout << "**\n\n---------------- creating Presidentail form can't execute ----------------**" << std::endl;
    try 
	{
		PresidentialPardonForm form1("JoyRider");
		std::cout << form1 << std::endl;
		std::cout << '\n';

		Bureaucrat newbie1("Newbie1", 20);
		Bureaucrat newbie2("Newbie2", 10);
		std::cout << newbie1 << std::endl;
		std::cout << newbie2 << std::endl;
		std::cout << '\n';

		newbie1.signForm(form1);
		std::cout << '\n';
		
		newbie2.executeForm(form1);
		std::cout << '\n';
    }
    catch (const std::exception& e) 
	{
        std::cerr << BOLD_TEXT << "Exception caught: " << e.what() << RESET << std::endl;
    }

	return 0;
}
