/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   UI.hpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/28 20:17:22 by dreijans      #+#    #+#                 */
/*   Updated: 2024/05/28 20:32:44 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_HPP
#define UI_HPP

#include <iostream>
#include <string>

class UI {
public:
    static const char* const BOLD_TEXT;
    static const char* const RESET;
    static const char* const BLUE;
    static const char* const CYAN;
	static const char* const GREEN;
    static const char* const MAGENTA;
    static const char* const RED;
	static const char* const WHITE;
	static const char* const YELLOW;

    static void menuOptions();
    static void showChoice(const std::string& input);
    static void numericOptions();
    static void isEmpty();
    static void introduceOptions();
    static void tryAgain();
    static void invalidInput();
    static void deletionSuccess(const std::string& input);
    static void additionSuccess();
    static void overwriteWarning();
    static void showPrompt();
};

#endif
