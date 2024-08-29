/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/27 16:17:04 by dreijans      #+#    #+#                 */
/*   Updated: 2024/08/29 17:46:30 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//don't need to add data?
BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) : csvdata(copy.csvdata), txtdata(copy.txtdata) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &copy) {
	if (this != &copy) {
		csvdata = copy.csvdata;
		txtdata = copy.txtdata;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::readCsv(std::string &filename) {
	std::fstream file(filename);
	if (!file.is_open())
		throw OpenFileException();
	
	//read from file to multimap

	file.close();
}

void BitcoinExchange::readTxt(std::string &filename) {
	
}