/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/30 19:18:40 by dreijans      #+#    #+#                 */
/*   Updated: 2024/06/30 19:30:07 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# define BOLD_TEXT "\033[1m"
# define RESET "\033[0m"
# define BLUE "\033[34m"
# define CYAN "\033[36m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define MAGENTA "\033[35m"
# define ORANGE "\033[38;2;255;165;0m"

#include <iostream>
#include <stdexcept>
class Bureacrat;

/**
 * write:
 * 			- getters for all attributes
 * 			- an overload of the insertion («) operator that prints all the form’s informations.
 * 			- Add also a beSigned() member function to the Form that takes a Bureaucrat as
			parameter. It changes the form status to signed if the bureaucrat’s grade is high enough
			(higher or egal to the required one). Remember, grade 1 is higher than grade 2.
			If the grade is too low, throw a Form::GradeTooLowException.
			- Lastly, add a signForm() member function to the Bureaucrat. If the form got signed,
			it will print something like:
											<bureaucrat> signed <form>
			Otherwise, it will print something like:
											<bureaucrat> couldn’t sign <form> because <reason>.
*/
class Form
{
	private:
		std::string const	_name;
		bool				_signed;
		int const			_signGrade;
		int const			_executeGrade;

	public:
		Form();
		Form(const std::string &name, int grade);
		Form(const Form &copy);
		Form& operator=(const Form &copy);
		~Form();

		void setGrade(const int grade);
		
		std::string const & getName() const;
		int getGrade() const;

		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw()
			{
				return "grade too high";
			}
		};
		
		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw()
			{
				return "grade too low";
			}					
		};
};

std::ostream & operator<<(std::ostream & stream, const Form& form);

#endif