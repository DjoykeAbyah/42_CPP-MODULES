/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/29 16:04:27 by dreijans      #+#    #+#                 */
/*   Updated: 2024/06/29 17:02:09 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	private:
			std::string const name;
			int grade; //1 highest to 150 lowest

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
				
			};
			
			class GradeTooLowException : public std::exception
			{
				
			};
};

#endif