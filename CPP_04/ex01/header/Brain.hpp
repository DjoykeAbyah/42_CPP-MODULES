/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/17 20:32:03 by dreijans      #+#    #+#                 */
/*   Updated: 2024/06/19 14:32:46 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include "Animal.hpp"

# define BOLD_TEXT "\033[1m"
# define RESET "\033[0m"
# define BLUE "\033[34m"
# define CYAN "\033[36m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define MAGENTA "\033[35m"

class Brain
{
	private:
		std::string 	_ideas[100];
		
	public:
		Brain();
		Brain(const Brain& copy);
		Brain& operator=(const Brain& copy);
		virtual ~Brain();

		std::string getIdeas(int index) const;
		void setIdeas(int index, const std::string& idea);
};

#endif