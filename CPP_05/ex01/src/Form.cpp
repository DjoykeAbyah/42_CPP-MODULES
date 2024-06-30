/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/30 19:18:42 by dreijans      #+#    #+#                 */
/*   Updated: 2024/06/30 19:34:06 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/**
 * @todo write an overload of the insertion («) operator that prints all the form’s informations
*/
std::ostream & operator<<(std::ostream & stream, const Form& form){
	stream << ORANGE <<"form name: "
	<< RESET << YELLOW << form.getName() 
	<< RESET << ORANGE << ", form grade " 
	<< RESET << YELLOW << form.getSignedGrade() 
	<< RESET << std::endl;
	return stream;
}