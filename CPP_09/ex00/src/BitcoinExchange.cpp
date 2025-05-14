/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/27 16:17:04 by dreijans      #+#    #+#                 */
/*   Updated: 2025/05/14 19:53:37 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//don't need to add data?
BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) : csvdata(copy.csvdata) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &copy) {
	if (this != &copy) {
		csvdata = copy.csvdata;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::parseCsv(std::string &filename) {
	std::fstream file(filename);
	if (!file.is_open())
		throw OpenFileException();
	
	//read from file to multimap
	std::string line;
	std::getline(file, line);

	while (std::getline(file, line)) {
		std::stringstream stringStream(line);			//turn the line into a stream
		std::string date;
		std::string valueString;
		float value;

		if (std::getline(stringStream, date, ',') && std::getline(stringStream, valueString)){
			std::stringstream(valueString) >> value; 	//converts string into float, reads from stream into value using >>
			csvdata[date] = value;
		}
	}

	file.close();
}

void BitcoinExchange::readTxt(std::string &filename) {
	
}