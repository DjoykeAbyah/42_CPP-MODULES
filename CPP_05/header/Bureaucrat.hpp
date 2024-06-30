/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/29 16:04:27 by dreijans      #+#    #+#                 */
/*   Updated: 2024/06/30 18:18:00 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

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

class Bureaucrat
{
	private:
			std::string const 	_name;
			int 				_grade; //1 highest to 150 lowest

	public:
			Bureaucrat();
			Bureaucrat(std::string &name, int grade);
			Bureaucrat(const Bureaucrat &copy);
			Bureaucrat& operator=(const Bureaucrat &copy);
			~Bureaucrat();

			void setName(const std::string name);
			void setGrade(const int grade);
			
			std::string const & getName() const;
			int const getGrade() const;

			void incrementGrade();
			void decrementGrade();

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

std::ostream & operator<<(std::ostream & stream, const Bureaucrat& bureaucrat);

#endif