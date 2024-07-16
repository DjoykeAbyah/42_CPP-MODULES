/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: djoyke <djoyke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/16 21:34:50 by djoyke        #+#    #+#                 */
/*   Updated: 2024/06/19 15:43:31 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

# define BOLD_TEXT "\033[1m"
# define RESET "\033[0m"
# define BLUE "\033[34m"
# define CYAN "\033[36m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define MAGENTA "\033[35m"

class Animal
{
	protected:
		std::string		_type;
		std::string		_name;
		
	public:
		Animal();
		Animal(const std::string& name);
		Animal(const Animal& copy);
		Animal& operator=(const Animal& copy);
		virtual ~Animal();
		
		const std::string& getType() const;
		const std::string& getName() const;
		
		void setName(const std::string& name);
		void setType(const std::string& type);
		
		virtual void makeSound() const ;// virtual to overwrite
};

#endif