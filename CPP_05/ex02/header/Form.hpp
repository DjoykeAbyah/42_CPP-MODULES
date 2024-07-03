/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/30 19:18:40 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/03 12:22:43 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

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
#include <Bureaucrat.hpp>
class Bureaucrat;

class Form
{
	private:
		std::string const	_name;
		bool				_signed;
		int const			_signGrade;
		int const			_executeGrade;

	public:
		Form();
		Form(const std::string &name, int signGrade, int executeGrade);
		Form(const Form &copy);
		Form& operator=(const Form &copy);
		~Form();
		
		std::string const & getName() const;
		bool getSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;

		void beSigned(Bureaucrat bureaucrat);

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
