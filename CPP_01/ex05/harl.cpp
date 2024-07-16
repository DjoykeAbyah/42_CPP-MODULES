/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   harl.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: djoyke <djoyke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/06 23:04:10 by djoyke        #+#    #+#                 */
/*   Updated: 2024/06/08 15:36:32 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "harl.hpp"

Harl::Harl()
{
    std::cout << "sigh...right on time as always, Harl" << std::endl;
}

Harl::~Harl()
{
    std::cout << "always happy to see him leave" << std::endl;
}

void Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. ";
    std::cout << "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free."; 
    std::cout << "I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

/**
 * public member function that calls the four member functions above
 */
void Harl::complain(std::string level)
{
    void (Harl::*functionArray[4])() =
    {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    std::string options[4] = 
    {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };

    for (int i = 0; i < 4; i++)
    {
        if (options[i] == level)
        {
            (this->*functionArray[i])();
            return ;
        }  
    }
    std::cout << "no valid option" << std::endl;
}