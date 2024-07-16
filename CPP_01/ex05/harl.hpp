/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   harl.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: djoyke <djoyke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/06 23:02:39 by djoyke        #+#    #+#                 */
/*   Updated: 2024/06/07 23:33:15 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H

#include <iostream>

class Harl
{
    private:
        void debug();
        void info();
        void warning();
        void error();
    
    public:
        Harl();
        ~Harl();
        void complain(std::string level);
};

#endif