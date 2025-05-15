/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/27 16:17:04 by dreijans      #+#    #+#                 */
/*   Updated: 2025/05/15 21:50:50 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//don't need to add data?
BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) : _csvdata(copy._csvdata) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &copy) {
	if (this != &copy) {
		_csvdata = copy._csvdata;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

const std::map<std::string, float> &BitcoinExchange::getCsvData() const {
	return _csvdata;
} 

void BitcoinExchange::parseCsv(std::string &filename) {
	std::fstream file(filename);
	if (!file.is_open())
		throw OpenFileException();
	
	//read from file to multimap
	std::string line;
	std::getline(file, line); //skips first line header

	while (std::getline(file, line)) {
		std::stringstream stringStream(line);			//turn the line into a stream
		std::string date;
		std::string valueString;
		float value;

		if (std::getline(stringStream, date, ',') && std::getline(stringStream, valueString)){
			std::stringstream(valueString) >> value; 	//converts string into float, reads from stream into value using >>
			_csvdata[date] = value; //lookup and insertion if not exists
		}
	}
	file.close();
}

void BitcoinExchange::readTxt(std::string &filename) {
	std::fstream file(filename);
	if (!file.is_open())
		throw OpenFileException();
	
	std::string line;
	std::getline(file, line); //skips first line

	while (std::getline(file, line)) {
		std::stringstream stringStream(line);			//turn the line into a stream
		std::string date;
		std::string valueString;
		
		if (!std::getline(stringStream, date, '|') || !std::getline(stringStream, valueString)) {
			std::cerr << "Bad input : " << line << std::endl; 
			continue; // TODO should I continue?
		}

		//Trim whitespace
		date.erase(0, date.find_first_not_of(" \t"));
		date.erase(date.find_last_not_of(" \t") + 1); // TODO is +1 neccesary?
		valueString.erase(0, valueString.find_first_not_of("\t"));
		valueString.erase(valueString.find_last_not_of(" \t") + 1);
		
		//convert value to float
		float value;
		try {
			value = std::stof(valueString); //convert string to float
		}
		catch (...) { //catch all exceptions
			std::cerr << "bad value : " << valueString << std::endl;
			continue;
		}
		
		//check range
		if (value < 0) {
			std::cerr << "not a positive number" << std::endl;
			continue;
		}
		else if (value > 1000) {
			std::cerr << "number too large" << std::endl;
			continue;
		}

		//lookup exchange rate in csv data
		std::map<std::string, float>::iterator it = _csvdata.lower_bound(date);
		if (it == _csvdata.end() || it->first != date) {
			if (it != _csvdata.begin())
				--it;
			else {
				std::cerr << "no exchange rate available for " << date << std::endl;
				continue;
			}
		}

		float exchangeRate = it->second;
		float result = value * exchangeRate;

		std::cout << date << " : " << value << " = " << result << std::endl;
	}
	file.close();
}