/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: djoyke <djoyke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/06 23:02:43 by djoyke        #+#    #+#                 */
/*   Updated: 2024/06/07 23:30:13 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "harl.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "This is not gonna work pall" << std::endl;
        std::cout << "You have a few options DEBUG, INFO, WARNING or ERROR" << std::endl;
        std::cout << "please input: ./harlFilter with one of the options" << std::endl;
        return 1;
    }
    
    Harl harl;
    harl.complain(argv[1]);
    
    return 0;
}