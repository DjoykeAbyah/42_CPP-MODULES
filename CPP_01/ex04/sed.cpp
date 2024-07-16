/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sed.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/04 20:01:39 by dreijans      #+#    #+#                 */
/*   Updated: 2024/06/06 22:49:05 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

WordReplacer::WordReplacer(const std::string &filename, const std::string word, const std::string replaceWord) 
    : _filename(filename), _word(word), _replaceWord(replaceWord)
{
    std::cout << "constructor called" << std::endl;
}

WordReplacer::~WordReplacer()
{
    std::cout << "deconstructor called" << std::endl;
}

bool WordReplacer::validateInput() const
{
	if (_word == _replaceWord)
	{
		std::cerr << "a bit useless don't you think?" << std::endl;
		return false;
	}
	if (_word.empty() || _replaceWord.empty())
	{
		std::cerr << "words must not be empty" << std::endl;
		return false;
	}
    return true;
}

bool WordReplacer::processFile() const
{
    std::ifstream inFile(_filename);
	if (!inFile)
	{
		std::cerr << "cant open this infile" << _filename << std::endl;
		return false;
	}
	std::cout << "infile opened sucessfully" << std::endl;
	
	std::ofstream outFile("output.txt");
	if (!outFile)
	{
		std::cerr << "unable to open outfile" << std::endl;
		return false;
	}
	std::cout << "outfile opened sucessfully" << std::endl;
    
    std::string readLine;
	while (std::getline(inFile, readLine))
	{
		size_t position = readLine.find(_word);
		while (position != std::string::npos)
		{
			readLine = readLine.std::string::substr(0, position) + _replaceWord + readLine.std::string::substr(position + _word.length());
			position = readLine.find(_word, position + _replaceWord.length());
		}
		outFile << readLine << std::endl;
	}

    if (inFile.eof()) 
        inFile.clear(); // Clear EOF flag before closing not to cause close error

    inFile.close();
    if (inFile.fail()) 
    {
        std::cerr << "Error occurred while closing infile: " << _filename << std::endl;
        return false;
    }
    
    outFile.close();
    if (outFile.fail()) 
    {
        std::cerr << "Error occurred while closing outfile" << std::endl;
        return false;
    }
    return true;
}
