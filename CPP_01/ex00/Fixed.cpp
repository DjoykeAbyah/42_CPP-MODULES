/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/10 11:05:01 by dreijans      #+#    #+#                 */
/*   Updated: 2024/06/10 18:07:19 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPointVal(0)
{
	std::cout << "default constructor called" << std::endl;
}

/**
 * @brief 	A copy constructor is a special constructor 
 *          that creates a new object as a copy of an existing object.
 * 
 *          It initializes the new object using the state of an existing object
 *          of the same class. This ensures a deep copy when the class involves
 *          dynamically allocated memory or resources, so each object has its own
 *          copy of the resources.
 *          
 *          By ensuring the new object is an independent copy, the copy constructor
 *          prevents issues related to shared or shallow copies.
 *
 * @example Example Usage:
 *          Fixed A;
 *          Fixed B = A;  // Calls copy constructor
 *          Fixed B(A);   // Calls copy constructor
 */
Fixed::Fixed(const Fixed& other): _fixedPointVal(other._fixedPointVal)
{
	std::cout << "copy constructor called" << std::endl;
}

/**
 * @brief 	The copy assignment operator is a special operator 
 *          that assigns the values from one existing object to another existing object
 *          of the same class.
 * 
 *          It replaces the current contents of the target object with the contents
 *          of the source object. This ensures a deep copy when the class involves
 *          dynamically allocated memory or resources, so each object maintains its own
 *          independent copy of the resources.
 *          
 *          By ensuring the target object is an independent copy, the copy assignment operator
 *          prevents issues related to shared or shallow copies.
 * 
 *          The operator must handle self-assignment by checking if the source and target objects
 *          are the same and avoid unnecessary operations in such cases.
 *
 * @example Example Usage:
 *          Fixed A;
 *          Fixed B;
 *          B = A;  // Calls copy assignment operator
 */
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "copy assignment operator called" << std::endl;
	if (this != &other)
		_fixedPointVal = other._fixedPointVal;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "deconstructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointVal;
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointVal = raw;
}