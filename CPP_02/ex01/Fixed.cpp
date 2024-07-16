/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/10 11:05:01 by dreijans      #+#    #+#                 */
/*   Updated: 2024/06/10 21:52:24 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPointVal(0)
{
	std::cout << "default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "copy constructor called" << std::endl;
	*this = other; // same as : _fixedPointVal(other._fixedPointVal)
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "copy assignment operator called" << std::endl;
	if (this != &other)
		_fixedPointVal = other._fixedPointVal;
	return *this;
}

Fixed::Fixed(const int intNum)
{
	std::cout << "int constructor called" << std::endl;
	this->_fixedPointVal = intNum<<_fractBitNum;
}

Fixed::Fixed(const float& floatNum)
{
	std::cout << "float constructor called" << std::endl;
	this->_fixedPointVal = floatNum * (1<<_fractBitNum);// times the destination bit = 1 * (2^8) or 256
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

float Fixed::toFloat(void) const // bits fixedpointvalue to float
{
	return (float)this->_fixedPointVal / (1<<_fractBitNum);
}

int Fixed::toInt(void) const // bits fixedpointvalue to int
{
	return (int)this->_fixedPointVal >>_fractBitNum;
}

std::ostream & operator<<(std::ostream & stream, const Fixed& other)
{
	return (stream << other.toFloat());
}