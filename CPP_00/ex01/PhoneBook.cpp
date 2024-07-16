/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/12 21:01:05 by dreijans      #+#    #+#                 */
/*   Updated: 2024/05/30 18:16:52 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Utils.hpp"
#include "UI.hpp"

PhoneBook::PhoneBook():contactIndex(0){};

PhoneBook::~PhoneBook(){};


int PhoneBook::getContactIndex() const
{
    return contactIndex;
}

/**
 * @brief   checks input for corresponding enums
 * @return  enum linked to input, if no link to enum found
 *          returns INVALID
*/
UserChoice getChoice(const std::string& input) 
{
    if (input == "ADD") 
		return ADD;
    if (input == "SEARCH") 
		return SEARCH;
    if (input == "EXIT") 
		return EXIT;
    return INVALID;
}

/**
 * @brief   checks if input is numeric
 * @return  false is not digits and number is not
 *          between 0 and 9 
*/
bool PhoneBook::isNumeric(std::string& pageNum)
{
    for (int i = 0; i < pageNum.size(); i++)
    {
        if (i > 1)
            return false;
        if (!std::isdigit(pageNum[i]))
            return false;
        else
        {
            int number = std::stoi(pageNum);
            if (number < 0 && number > 9)
                return false;
        }
    }
    return true;
}

/**
 * @brief   check's if phoneBook is empty
 * @return  false if at least one contact is not empty
 *          false if all contacts are empty
 */ 
bool PhoneBook::isEmpty()
{
    for (int i = 0; i < 8; ++i)
    {
        if (!contacts[i].getFirstName().empty())
            return false;
    }
    return true;
}

/**
 * @brief   check's input index is a valid index
 * @return  index is it's between 1 and 8
 */ 
bool PhoneBook::isValidPageIndex(int index)
{
    return index >= 1 && index <= 8;
}

/**
 * @brief   prints contact if not an empty entry
 * @param   int index
 * @return  false if entry is empty
 *          true is entry exists
 */ 
bool PhoneBook::printContactIfNotEmpty(int index)
{
    int arrayIndex = index - 1;

    if (contacts[arrayIndex].getFirstName().empty())
    {
        std::cout << UI::RED << "\nEntry is empty\n\n" << UI::RESET << std::endl;
        return false;
    }
    printContact(index);
    return true;
}

/**
 * @brief   searches a contact based on the index number of the phonebook
 *          gives error message if user input is not index 1 till 8.
 *          checks if contact is empty or not and shows prompt again if input is faulty
 */ 
void PhoneBook::searchContact()
{
    std::string pageNum;
    
    printPhoneBook();
    if (isEmpty())
    {
        UI::isEmpty();
        return ;
    }
    std::cout << "\nWhich page do you want to see?";
    while (true)
    {
        UI::numericOptions();
        std::cin >> pageNum;
        UI::showChoice(pageNum); 
        if (isNumeric(pageNum))
        {
            int number = std::stoi(pageNum);
            if (isValidPageIndex(number))
            {
                if (printContactIfNotEmpty(number))
                    break ;
            }
            else
                UI::introduceOptions();
        }
    }
}

/**
 * @brief   adds contact to phonebook
 *          if phonebook alrady has 8 contacts gives overwriting warning
 *          if user's choice is to overwrite. oldest contact is replaced by new contact
*/
void PhoneBook::addContact()
{
    std::string answer;
    bool isValidInput = false;
    
    if (contactIndex == 8 || repeat == true)
    {
        UI::overwriteWarning();
        while (!isValidInput)
        {
            std::cout << "type yes or no in lowercase: ";
            if (!safeGetLine(answer))
                return ;
            UI::showChoice(answer);
            std::cout << std::endl;
            if (answer == "no")
                return ;
            if (answer == "yes")
            {
                isValidInput = true;
                if (contactIndex == 8)
                    contactIndex = 0;
                repeat = true;   
            }
        }
    }
    contacts[contactIndex].setFirstName();
    contacts[contactIndex].setLastName();
    contacts[contactIndex].setNickName();
    contacts[contactIndex].setPhoneNumber();
    contacts[contactIndex].setDarkestSecret();
    contactIndex++;
    UI::additionSuccess();
}


/**
 * @brief   truncates the text if it's longer than 10 characters 
 *          and replaces the last displayable character with a dot
*/
std::string PhoneBook::truncateInput(const std::string& input)
{
    const int columnWidth = 10;
    if (input.length() > columnWidth)
        return input.substr(0, columnWidth - 1) + ".";
    else
        return input;
}

/**
 * @brief   displays contactinfo of one contact
*/
void PhoneBook::printContact(int page)
{
    page -= 1;
    {
        std::cout << UI::BOLD_TEXT << "\nContact information:\n\n" << UI::RESET
              << "First Name: " << UI::YELLOW << contacts[page].getFirstName() << UI::RESET << "\n"
              << "Last Name: " << UI::YELLOW << contacts[page].getLastName() << UI::RESET << "\n"
              << "Nickname: " << UI::YELLOW << contacts[page].getNickName() << UI::RESET << "\n"
              << "Phone Number: " << UI::YELLOW << contacts[page].getPhoneNumber() << UI::RESET << "\n"
              << "Darkest Secret: " << UI::YELLOW << contacts[page].getDarkestSecret() << UI::RESET << "\n";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\n\n\n" << std::endl;
}

/**
 * @brief   displays all contacts truncated if contact fields > 10
*/
void PhoneBook::printPhoneBook()
{
    int pageIndex = 1; // Starting page index

    for (int index = 0; index < 8; index++)
    {
        std::cout << std::setw(5) << std::right << UI::YELLOW << pageIndex++ << UI::RESET << " | "
                  << std::setw(10) << std::right << truncateInput(contacts[index].getFirstName()) << " | "
                  << std::setw(10) << std::right << truncateInput(contacts[index].getLastName()) << " | " 
                  << std::setw(10) << std::right << truncateInput(contacts[index].getPhoneNumber()) << " | "
                  << std::setw(10) << std::right << truncateInput(contacts[index].getDarkestSecret()) << std::endl;
    }
}
