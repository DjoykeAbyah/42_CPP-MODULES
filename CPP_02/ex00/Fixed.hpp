/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/10 11:05:04 by dreijans      #+#    #+#                 */
/*   Updated: 2024/06/11 19:22:29 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed
{
	private:
		int _fixedPointVal;
		static const int _fractBitNum = 8;
	
	public:
		Fixed(void);//default constructor
		Fixed(const Fixed& other); //copy constructor
		Fixed& operator=(const Fixed& other); //copy assignment operator overload
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif