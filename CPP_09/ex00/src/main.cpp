/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/27 16:16:50 by dreijans      #+#    #+#                 */
/*   Updated: 2025/05/14 22:27:32 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"

int main() {
	BitcoinExchange bitcoinExchange;
	
	std::string filename = "data.csv";
	bitcoinExchange.parseCsv(filename);
	
	const std::map<std::string, float>& data = bitcoinExchange.getCsvData();

	for (const auto& pair : data) {
		std::cout << pair.first << "key: " << pair.second << "value: " << std::endl;
	}
}