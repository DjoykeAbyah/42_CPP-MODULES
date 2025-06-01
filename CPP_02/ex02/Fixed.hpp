/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/10 11:05:04 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/24 14:30:42 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int _fixedPointVal;
		static const int _fractBitNum = 8;
	
	public:
		//default constructor
		Fixed(void);
		
		//custom constructor taking an int as parameter and converting it to it's fixed point value
		Fixed(const int intNum);

		//custom constructor taking a float  as parameter and converting it to it's fixed point value
		Fixed(const float& floatNum);
		
		//copy constructor
		Fixed(const Fixed& other);

		//deconstructor
		~Fixed();
		
		//copy assignment operator overloader
		Fixed& operator=(const Fixed& other);
		
		//comparison operator overloaders returning boolean result
		bool operator>(const Fixed& other) const; 
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;
		
	//arithmetic operator overloaders
		Fixed operator+(const Fixed& other); 
		Fixed operator-(const Fixed& other);
		Fixed operator*(const Fixed& other); 
		Fixed operator/(const Fixed& other);
		
		//increment operator overloader
		Fixed &operator++();		//pre-increment
		Fixed operator++(int);		//post-increment
		Fixed &operator--();		//pre-decrement
		Fixed operator--(int);		//post-decrement

		static Fixed& min(Fixed& fixedPoint1, Fixed& fixedPoint2);
		static const Fixed& min(const Fixed& fixedPoint1, const Fixed& fixedPoint2);
		static Fixed& max(Fixed& fixedPoint1, Fixed& fixedPoint2);
		static const Fixed& max(const Fixed& fixedPoint1, const Fixed& fixedPoint2);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream & operator<<(std::ostream & stream, const Fixed& other);

#endif