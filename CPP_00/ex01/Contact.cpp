/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 21:15:51 by dreijans      #+#    #+#                 */
/*   Updated: 2024/05/30 17:49:26 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "Utils.hpp"
#include "UI.hpp"

Contact::Contact(){};

Contact::~Contact(){};

/**
 * @brief   setter for FirstName
 *          uses nameCheck method 
*/
void Contact::setFirstName()
{
	nameCheck(_firstName, "Enter first name in alphabetic characters: ");
}

/**
 * @brief   setter for SetLastName
 *          uses nameCheck method 
*/
void Contact::setLastName()
{
	nameCheck(_lastName, "Enter last name in alphabetic characters: ");
}

/**
 * @brief   setter for setNickName
 *          uses nameCheck method 
*/
void Contact::setNickName()
{
	nameCheck(_nickName, "Enter nickname in alphabetic characters: ");
}

/**
 * @brief   setter for PhoneNumber
 *          uses PhoneNumberCheck method 
*/
void Contact::setPhoneNumber()
{
	phoneNumberCheck();
}

/**
 * @brief   setter for DarkestSecret
 *          checks if field is not empty
*/
void Contact::setDarkestSecret()
{
	bool isValidInput = false;

    while (!isValidInput)
    {
        std::cout << "Enter darkest secret: ";
        if (!safeGetLine(_darkestSecret))
            break ;
        if (_darkestSecret.empty())
            UI::tryAgain();
        else
            isValidInput = true;
    }
}

std::string Contact::getFirstName()
{
	return _firstName;
}

std::string Contact::getLastName()
{
	return _lastName;
}

std::string Contact::getNickName()
{
	return _nickName;
}
/**
 * @brief   getter for DarkestSecret
 * @return  _darkestSecret 
*/
std::string Contact::getPhoneNumber()
{
	return _phoneNumber;
}

std::string Contact::getDarkestSecret()
{
	return _darkestSecret;
}

/**
 * @brief   checks if input string is alphabetic
 * @return  true is alphabetic
 *          false if not alphabetic 
*/
bool Contact::isAlphabetic(const std::string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (!isalpha(str[i]))
			return false;
	}
	return true;
}

/**
 * @brief   checks if input for name is valid by checking if it's empty or alphabetic
 *          gives error message and if imput is empty or not alphabetic and reprompts user 
*/
void Contact::nameCheck(std::string& input, const std::string& prompt)
{
    bool isValidInput = false;

    while (!isValidInput)
    {
        std::cout << prompt;
        if (!safeGetLine(input))
            break ;
        if (input.empty())
            UI::tryAgain();
        else if (!isAlphabetic(input))
            UI::invalidInput();
        else
            isValidInput = true;
    }
}

/**
 * @brief   checks if input for phone number is valid by checking if it's empty or numeric
 *          gives error message and if imput is empty or not numeric and reprompts user  
*/
void Contact::phoneNumberCheck()
{
	bool isValidInput = false;

    while (!isValidInput)
    {
        std::cout << "Enter phone number: ";
        if (!safeGetLine(_phoneNumber))
            break ;
        if (_phoneNumber.empty())
            UI::tryAgain();
        else if (!digitCheck(_phoneNumber))
            UI::invalidInput();
        else
            isValidInput = true;
    }
}

/**
 * @brief   checks if input is numeric
 * @return  true if it's digit
 *          false if not a digit 
*/
bool Contact::digitCheck(std::string& input)
{
	for (int i = 0; i < input.size(); i++)
	{
		if (!std::isdigit(input[i]))
			return false;
	}
	return true;
}

/**
 * @brief   resets contact by clearing all the fields 
*/
void Contact::resetContact() 
{
    _firstName.clear();
    _lastName.clear();
    _nickName.clear();
    _phoneNumber.clear();
    _darkestSecret.clear();

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
