/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/29 16:03:29 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/08 14:21:50 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Bureaucrat.hpp"
#include "../header/Form.hpp"
#include <iostream>
#include <stdexcept>

int main()
{
	std::cout << "**\n\n---------------- creating valid forms ----------------**" << std::endl;
	try
	{
		//creating default constructor form
		Form* form1 = new Form();
		std::cout << *form1 << std::endl;

		//creating parametric constructor form
		Form* form2 = new Form("Hallpass", 20, 20);
		std::cout << *form2 << std::endl;

		delete form1;
		delete form2;
	}
	catch(const std::exception& e)
	{
		std::cerr << BOLD_TEXT << "Exception caught: " << e.what() << RESET << std::endl;
	}
	
	std::cout << "**\n\n---------------- creating invalid forms ----------------**" << std::endl;
    try 
	{
        Form* form3 = new Form("wrongHallPass1", 0, 20);
        std::cout << *form3 << std::endl;
        delete form3;
    }
    catch (const std::exception& e) 
	{
        std::cerr << BOLD_TEXT << "Exception caught: " << e.what() << RESET << std::endl;
    }

    try 
	{
        Form* form4 = new Form("wrongHallPass2", 20, 0);
        std::cout << *form4 << std::endl;
        delete form4;
    }
    catch (const std::exception& e) 
	{
        std::cerr << BOLD_TEXT << "Exception caught: " << e.what() << RESET << std::endl;
    }

    try 
	{
        Form* form5 = new Form("wrongHallPass3", 151, 20);
        std::cout << *form5 << std::endl;
        delete form5;
    }
    catch (const std::exception& e) 
	{
        std::cerr << BOLD_TEXT << "Exception caught: " << e.what() << RESET << std::endl;
    }

    try 
	{
        Form* form6 = new Form("wrongHallPass4", 20, 151);
        std::cout << *form6 << std::endl;
        delete form6;
    }
    catch (const std::exception& e) 
	{
        std::cerr << BOLD_TEXT << "Exception caught: " << e.what() << RESET << std::endl;
    }
	
	std::cout << "**\n\n---------------- creating valid bureaucrats ----------------**" << std::endl;
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
		std::cerr << BOLD_TEXT << "Exception caught: " << e.what() << RESET << std::endl;
	}
	
	std::cout << "**\n\n---------------- creating form too high to sign by bureaucrat ----------------**" << std::endl;
	
	Bureaucrat* intern = new Bureaucrat("intern", 150);
	std::cout << *intern << std::endl;
	Form* importantForm = new Form("importantForm", 1, 20);
	std::cout << *importantForm << std::endl;
	
	try
	{
		intern->signForm(*importantForm);
	}
	catch (const std::exception& e)
	{
		std::cerr << BOLD_TEXT << "Exception caught: " << e.what() << RESET << std::endl;
	}
	delete intern;
	delete importantForm;

	std::cout << "**\n\n---------------- creating form good to sign by bureaucrat ----------------**" << std::endl;
	
	Bureaucrat* manager = new Bureaucrat("Manager", 40);
	std::cout << *manager << std::endl;
	Form* importantForm1 = new Form("importantForm", 60, 20);
	std::cout << *importantForm1 << std::endl;
	
	try
	{
		manager->signForm(*importantForm1);
	}
	catch (const std::exception& e)
	{
		std::cerr << BOLD_TEXT << "Exception caught: " << e.what() << RESET << std::endl;
	}
	delete manager;
	delete importantForm1;
	
	return 0;
}
