/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/03 12:57:23 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/08 13:23:28 by dreijans      ########   odam.nl         */
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

#include <fstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string const _target;
		
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &copy);
		virtual ~ShrubberyCreationForm();
		
		// void execute(Bureaucrat const & execture) const;
    void action() const override;
};

#define ASCII_TREE "\n\
                                _,-/\"---, \n\
         ;\"\"\"\"\"\"\"\"\"\";         _/;; \"\"  <@`---v \n\
       ; :::::  ::  \"\\      _/ ;;  \"    _.../ \n\
      ;\"     ;;  ;;;  \\___/::    ;;,'\"\"\"\" \n\
     ;\"          ;;;;.  ;;  ;;;  ::/ \n\
    ,/ / ;;  ;;;______;;;  ;;; ::,/ \n\
    /;;V_;;   ;;;       \\       / \n\
    | :/ / ,/            \\_ \"\")/ \n\
    | | / /\"\"\"=            \\;;\"\"= \n\
    ; ;{::\"\"\"\"\"\"=            \\\"\"\"= \n\
 ;\"\"\"\"\"; \n\
 \\/\"\"\" \n"
