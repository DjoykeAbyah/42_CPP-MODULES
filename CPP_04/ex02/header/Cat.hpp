/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/17 15:51:46 by dreijans      #+#    #+#                 */
/*   Updated: 2024/06/19 16:02:30 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	private:
		Brain* _brain;
		
	public:
		Cat();
		Cat(const std::string& name);
		Cat(const Cat& copy);
		Cat& operator=(const Cat& copy);
		virtual ~Cat();
		
		void setIdea(int index, const std::string& idea);
		std::string getIdea(int index) const;
		
		void makeSound() const override;
};

#endif