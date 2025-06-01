/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   harl.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: djoyke <djoyke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/06 23:04:10 by djoyke        #+#    #+#                 */
/*   Updated: 2024/06/07 23:41:28 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "harl.hpp"

Harl::Harl()
{
    std::cout << CYAN << "sigh...right on time as always Harl" << RESET << std::endl;
}

Harl::~Harl()
{
    std::cout << CYAN << "always happy to see him leave" << RESET << std::endl;
}

void Harl::debug(void)
{
    std::cout << BOLD_TEXT << GREEN << "[DEBUG]" << RESET << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << BOLD_TEXT << MAGENTA << "[INFO]" << RESET << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. ";
    std::cout << "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << BOLD_TEXT << YELLOW << "[WARNING]" << RESET << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free."; 
    std::cout << "I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << BOLD_TEXT << RED << "[ERROR]" << RESET << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

int Harl::getLevel(const std::string& level) 
{
    if (level == "DEBUG") 
		return 0;
    if (level == "INFO") 
		return 1;
    if (level == "WARNING") 
		return 2;
    if (level == "ERROR") 
		return 3;
    return -1;
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

    int index = getLevel(level);

    switch (index)
    {
        case 0:
            (this->*functionArray[0])(); 
        case 1:
            (this->*functionArray[1])();
        case 2:
            (this->*functionArray[2])();
        case 3:
            (this->*functionArray[3])();
            break ;
        default:
            std::cout << BLUE << "coworker: I can't understand his blabbering sometimes but ignorance is bliss" << RESET << std::endl;
            break;
    }
}