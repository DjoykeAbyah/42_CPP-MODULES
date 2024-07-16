#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>

# define BOLD_TEXT "\033[1m"
# define RESET "\033[0m"
# define BLUE "\033[34m"
# define CYAN "\033[36m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define MAGENTA "\033[35m"
# define ORANGE "\033[38;2;255;165;0m"

class AAnimal
{
	protected:
		std::string		_type;
		std::string		_name;
		
	public:
		AAnimal();
		AAnimal(const std::string& name);
		AAnimal(const AAnimal& copy);
		AAnimal& operator=(const AAnimal& copy);
		virtual ~AAnimal();
		
		const std::string& getType() const;
		const std::string& getName() const;
		
		void setName(const std::string& name);
		void setType(const std::string& type);
		
		virtual void makeSound() const = 0;// making this a pure method
};

#endif