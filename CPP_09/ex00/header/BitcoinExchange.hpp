/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/27 16:15:36 by dreijans      #+#    #+#                 */
/*   Updated: 2025/06/06 11:15:31 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <map>
#include <fstream>
#include <exception>
#include <sstream>
#include <regex>

class BitcoinExchange {
	
	private:
		std::map<std::string, float> _csvdata; //stores date-value pairs

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange& operator=(const BitcoinExchange &copy);
		~BitcoinExchange();

		//getter
		const std::map<std::string, float>& getCsvData() const;
		
		void	parseCsv(std::string &filename);
		void	readTxt(std::string &filename);
		bool	isValidDate(const std::string& date) const;

	class OpenFileException : public std::exception {
		virtual const char* what() const throw() {
			return "Failed to open file";
		}
	};
};