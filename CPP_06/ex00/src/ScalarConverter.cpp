/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/10 19:39:35 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/15 17:24:38 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iomanip>

//cast to all other types beside the type thats input

void ScalarConverter::convert(std::string &literal){
	
	if (literal.empty()){
		std::cout << "input is empty" << std::endl;
		return ;
	}
	if (checkChar(literal) == true){
		convertChar(literal);
	}
	if (checkInt(literal) == true){
		convertInt(literal);
	}
	//check if float + convert to float
	//check if double + convert to double
	else
		std::cout << "Invalid input" << std::endl;
}

bool checkChar(std::string &literal){
	if (literal.size() == 3 && literal[0] == '\'' && literal[2] == '\''){
		return true;
	}
	return false;
}

bool checkInt(std::string &literal){
    try{
        std::stoi(literal);  // Attempt to convert the string to an integer
    } 
	catch (const std::invalid_argument&){
        // This exception is thrown if the string does not contain a valid integer
        return false;
    } 
	catch (const std::out_of_range&){
        // This exception is thrown if the converted value is out of the range of representable values for an int
        return false;
    }
    // If no exception is thrown, the string can be converted to an integer
    return true;
}

bool checkFloat(std::string &literal){
	try {
        size_t pos;
        float value = std::stof(literal, &pos);
        // Ensure the entire string was processed and ends with 'f'
        if (literal[pos] != 'f' || pos + 1 != literal.size())
            return false;
	}
	catch (const std::invalid_argument&){
		return false;
	}
	catch (const std::out_of_range&){
		return false;
	}
	return true;
}

bool checkDouble(std::string &literal){
	
}

void convertChar(std::string &literal){
	char c = literal[1];
	int i = static_cast<int>(literal[1]);
	
	if (i < 0 || i > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: \'" << c << "\'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}


void convertInt(std::string &literal){
	int num = std::stoi(literal);
	
    if (num < 0 || num > 127) {
        std::cout << "char: impossible" << std::endl;
    } 
	else if (!isprint(static_cast<char>(num))){
		std::cout << "char: non displayable" << std::endl;
    }
	else
        std::cout << "char: \'" << static_cast<char>(num) << "\'" << std::endl;
	std::cout << "int: " << num << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(num) << std::endl;
}

void convertFloat(std::string &literal){
	int num = std::stof(literal);
	
    if (num < 0 || num > 127) {
        std::cout << "char: impossible" << std::endl;
    } 
	else if (!isprint(static_cast<char>(num))){
		std::cout << "char: non displayable" << std::endl;
    }
	else
        std::cout << "char: \'" << static_cast<char>(num) << "\'" << std::endl;
	std::cout << "int: " << num << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(num) << std::endl;
}