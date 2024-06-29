/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/29 16:04:27 by dreijans      #+#    #+#                 */
/*   Updated: 2024/06/29 17:25:30 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

/**
 * Implement also two member functions to increment or decrement the bureaucrat grade. 
 * WHAT DO YOU MEAN? >> If the grade is out of range, both of them will throw the same exceptions as the constructor. 
*/
class Bureaucrat
{
	private:
			std::string const 	_name;
			int 				_grade; //1 highest to 150 lowest

	public:
			Bureaucrat();
			Bureaucrat(std::string &name);
			Bureaucrat(const Bureaucrat &copy);
			Bureaucrat& operator=(const Bureaucrat &copy);
			~Bureaucrat();

			void setName(const std::string name);
			void setGrade(const int grade);
			
			std::string const & getName() const;
			int const getGrade() const;

			void incrementGrade(int grade);//throw exception if out of range // incrementing means grade--
			void decrementGrade(int grade);//throw exception if out of range // decrementing means grade++

			class GradeTooHighException : public std::exception
			{
				virtual const char* what() const throw()
				{
					return ("grade too high");
				}
			};
			
			class GradeTooLowException : public std::exception
			{
				virtual const char* what() const throw()
				{
					return ("grade too low");
				}					
			};
};

std::ostream & operator<<(std::ostream & stream, const Bureaucrat& bureaucrat);

#endif