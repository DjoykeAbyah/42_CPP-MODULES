/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sed.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/04 20:01:06 by dreijans      #+#    #+#                 */
/*   Updated: 2024/06/06 22:31:14 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

#include <iostream>
#include <fstream>

class WordReplacer
{
    private:
        std::string _filename;
        std::string _word;
        std::string _replaceWord;

    public:
        WordReplacer(const std::string &filename, const std::string word, const std::string replaceWord);
        ~WordReplacer();
        
        bool validateInput() const;
        bool processFile() const;//why use const here?
};

#endif