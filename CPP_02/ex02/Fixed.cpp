/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/10 11:05:01 by dreijans      #+#    #+#                 */
/*   Updated: 2024/06/11 19:12:46 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPointVal(0) 
{
    std::cout << "default constructor called" << std::endl;
}

Fixed::Fixed(const int intNum) 
{
    std::cout << "int constructor called" << std::endl;
    this->_fixedPointVal = intNum << _fractBitNum;
}

/**
 * times the destination bit = 1 * (2^8) or 256
 * Using roundf ensures that the conversion from float to fixed-point 
 * representation maintains accuracy by rounding to the nearest integer
*/
Fixed::Fixed(const float& floatNum) 
{
    std::cout << "float constructor called" << std::endl;
    this->_fixedPointVal = static_cast<int>(roundf(floatNum * (1 << _fractBitNum)));
}

// same as : _fixedPointVal(other._fixedPointVal)
Fixed::Fixed(const Fixed& other) 
{
    std::cout << "copy constructor called" << std::endl;
    *this = other;
}

Fixed::~Fixed()
{
    std::cout << "deconstructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other)
        _fixedPointVal = other._fixedPointVal;
    return *this;
}

// Comparison operators
bool Fixed::operator>(const Fixed& other) const
{
    return this->_fixedPointVal > other._fixedPointVal;
}

bool Fixed::operator<(const Fixed& other) const 
{
    return this->_fixedPointVal < other._fixedPointVal;
}

bool Fixed::operator>=(const Fixed& other) const 
{
    return this->_fixedPointVal >= other._fixedPointVal;
}

bool Fixed::operator<=(const Fixed& other) const 
{
    return this->_fixedPointVal <= other._fixedPointVal;
}

bool Fixed::operator==(const Fixed& other) const 
{
    return this->_fixedPointVal == other._fixedPointVal;
}

bool Fixed::operator!=(const Fixed& other) const 
{
    return this->_fixedPointVal != other._fixedPointVal;
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed& other) 
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) 
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) 
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) 
{
    return Fixed(this->toFloat() / other.toFloat());
}

// Increment and decrement operators

/**
 * pre-increment operator, 
 * increase the value of _fixedPointVal and 
 * then return the incremented object.
*/
Fixed& Fixed::operator++() 
{
    _fixedPointVal++;
    return *this;
}

/**
 * post-increment operator,
 * save the current state of the object, 
 * increase the value of _fixedPointVal,
 * then return the saved state.
*/
Fixed Fixed::operator++(int) 
{
    Fixed temp(*this);
    _fixedPointVal++;
    return temp;
}

/**
 * pre-decrement operator, 
 * increase the value of _fixedPointVal and 
 * then return the incremented object.
*/
Fixed& Fixed::operator--() 
{
    _fixedPointVal--;
    return *this;
}

/**
 * post-decrement operator,
 * save the current state of the object, 
 * increase the value of _fixedPointVal,
 * then return the saved state.
*/
Fixed Fixed::operator--(int) 
{
    Fixed temp(*this);
    _fixedPointVal--;
    return temp;
}

// Min and max functions

/**
 * The ternary operator ? : is a shorthand for an if-else statement 
 * that returns one of two values based on a condition. 
 * here it is used to return the smaller of the two Fixed objects.
*/
Fixed& Fixed::min(Fixed& fixedPoint1, Fixed& fixedPoint2) 
{
    return (fixedPoint1.getRawBits() < fixedPoint2.getRawBits()) ? fixedPoint1 : fixedPoint2;
}

const Fixed& Fixed::min(const Fixed& fixedPoint1, const Fixed& fixedPoint2) 
{
    return (fixedPoint1.getRawBits() < fixedPoint2.getRawBits()) ? fixedPoint1 : fixedPoint2;
}

Fixed& Fixed::max(Fixed& fixedPoint1, Fixed& fixedPoint2) 
{
    return (fixedPoint1.getRawBits() > fixedPoint2.getRawBits()) ? fixedPoint1 : fixedPoint2;
}

const Fixed& Fixed::max(const Fixed& fixedPoint1, const Fixed& fixedPoint2) 
{
    return (fixedPoint1.getRawBits() > fixedPoint2.getRawBits()) ? fixedPoint1 : fixedPoint2;
}

//getter and setter

int Fixed::getRawBits(void) const 
{
    return this->_fixedPointVal;
}

void Fixed::setRawBits(int const raw) 
{
    this->_fixedPointVal = raw;
}

//to float and to int

float Fixed::toFloat(void) const 
{
    return static_cast<float>(this->_fixedPointVal) / (1 << _fractBitNum); // bits fixedpointvalue to float
}

int Fixed::toInt(void) const 
{
    return this->_fixedPointVal >> _fractBitNum; //bits fixedpointvalue to int
}

std::ostream & operator<<(std::ostream & stream, const Fixed& other) 
{
    stream << other.toFloat();
    return stream;
}