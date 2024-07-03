/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/29 16:03:29 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/03 16:53:08 by dreijans      ########   odam.nl         */
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
		
		Bureaucrat boss("Boss", 1);
		std::cout << boss << std::endl;
		boss.signForm(form1);
		boss.signForm(form2);
		boss.signForm(form3);
		boss.executeForm(form1);
		boss.executeForm(form2);
		boss.executeForm(form3);
	}
	catch(const std::exception& e)
	{
		std::cerr << BOLD_TEXT << "Exception caught: " << e.what() << RESET << std::endl;
	}
	
	// std::cout << "**\n\n---------------- creating invalid forms ----------------**" << std::endl;
    // try 
	// {
    //     AForm* form3 = new AForm("wrongHallPass1", 0, 20);
    //     std::cout << *form3 << std::endl;
    //     delete form3;
    // }
    // catch (const std::exception& e) 
	// {
    //     std::cerr << BOLD_TEXT << "Exception caught: " << e.what() << RESET << std::endl;
    // }

    // try 
	// {
    //     AForm* form4 = new AForm("wrongHallPass2", 20, 0);
    //     std::cout << *form4 << std::endl;
    //     delete form4;
    // }
    // catch (const std::exception& e) 
	// {
    //     std::cerr << BOLD_TEXT << "Exception caught: " << e.what() << RESET << std::endl;
    // }

    // try 
	// {
    //     AForm* form5 = new AForm("wrongHallPass3", 151, 20);
    //     std::cout << *form5 << std::endl;
    //     delete form5;
    // }
    // catch (const std::exception& e) 
	// {
    //     std::cerr << BOLD_TEXT << "Exception caught: " << e.what() << RESET << std::endl;
    // }

    // try 
	// {
    //     AForm* form6 = new AForm("wrongHallPass4", 20, 151);
    //     std::cout << *form6 << std::endl;
    //     delete form6;
    // }
    // catch (const std::exception& e) 
	// {
    //     std::cerr << BOLD_TEXT << "Exception caught: " << e.what() << RESET << std::endl;
    // }
	
	// std::cout << "**\n\n---------------- creating valid bureaucrats ----------------**" << std::endl;
	// try
	// {
	// 	//creating a default bureaucrat
	// 	Bureaucrat* bureaucrat1 = new Bureaucrat();
	// 	std::cout << *bureaucrat1 << std::endl;
		
	// 	//creating a parametric constructed valid bureaucrat
	// 	Bureaucrat* bureaucrat2 = new Bureaucrat("Henk", 2);
	// 	std::cout << *bureaucrat2 << std::endl;

	// 	//cleanup
	// 	delete bureaucrat1;
	// 	delete bureaucrat2;
	// }
	// catch (const std::exception &e)
	// {
	// 	std::cerr << BOLD_TEXT << "Exception caught: " << e.what() << RESET << std::endl;
	// }
	
	// std::cout << "**\n\n---------------- creating form too high to sign by bureaucrat ----------------**" << std::endl;
	
	// Bureaucrat* intern = new Bureaucrat("intern", 150);
	// std::cout << *intern << std::endl;
	// AForm* importantForm = new AForm("importantForm", 1, 20);
	// std::cout << *importantForm << std::endl;
	
	// try
	// {
	// 	intern->signForm(*importantForm);
	// }
	// catch (const std::exception& e)
	// {
	// 	std::cerr << BOLD_TEXT << "Exception caught: " << e.what() << RESET << std::endl;
	// }
	// delete intern;
	// delete importantForm;

	// std::cout << "**\n\n---------------- creating form good to sign by bureaucrat ----------------**" << std::endl;
	
	// Bureaucrat* manager = new Bureaucrat("Manager", 40);
	// std::cout << *manager << std::endl;
	// AForm* importantForm1 = new AForm("importantForm", 60, 20);
	// std::cout << *importantForm1 << std::endl;
	
	// try
	// {
	// 	manager->signForm(*importantForm1);
	// }
	// catch (const std::exception& e)
	// {
	// 	std::cerr << BOLD_TEXT << "Exception caught: " << e.what() << RESET << std::endl;
	// }
	// delete manager;
	// delete importantForm1;
	
	return 0;
}
