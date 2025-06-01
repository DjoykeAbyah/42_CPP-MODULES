/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: djoyke <djoyke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/13 23:13:19 by djoyke        #+#    #+#                 */
/*   Updated: 2024/05/28 20:46:12 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <cctype>
# include <limits>

class Contact
{
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNumber;
		std::string _darkestSecret;

		bool isAlphabetic(const std::string str);
		void nameCheck(std::string& input, const std::string& prompt);
		void phoneNumberCheck();
		bool digitCheck(std::string& input);
		
	public:
		Contact();//constructor
		~Contact();//deconstructor
		
		void setFirstName();
		void setLastName();
		void setNickName();
		void setPhoneNumber();
		void setDarkestSecret();
		
		std::string getFirstName();
		std::string getLastName();
		std::string getNickName();
		std::string getPhoneNumber();
		std::string getDarkestSecret();
		
	void resetContact();
};

#endif