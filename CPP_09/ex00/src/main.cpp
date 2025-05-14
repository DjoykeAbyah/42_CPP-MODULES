/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/27 16:16:50 by dreijans      #+#    #+#                 */
/*   Updated: 2025/05/14 22:18:48 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"

int main() {
	BitcoinExchange BitcoinExchange;
	
	std::string filename = "data.csv";
	BitcoinExchange.parseCsv(filename);
	
	try {
		
	}
}