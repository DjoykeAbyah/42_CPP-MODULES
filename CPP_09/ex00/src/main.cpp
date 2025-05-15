/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/27 16:16:50 by dreijans      #+#    #+#                 */
/*   Updated: 2025/05/15 21:50:05 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "could not open file" << std::endl;
		return 1;
	}
	
	BitcoinExchange bitcoinExchange;
	
	std::string csvFilename = "data.csv";
	std::string inputName = argv[1];
	
	try {
		bitcoinExchange.parseCsv(csvFilename);
		bitcoinExchange.readTxt(inputName);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}