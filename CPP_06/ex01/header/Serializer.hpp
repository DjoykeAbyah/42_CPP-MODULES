/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Serializer.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/16 21:22:40 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/16 21:40:28 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Serializer{
	
	private:
		Serializer() = delete;
		Serializer(const Serializer &copy) = delete;
		Serializer& operator=(const Serializer &copy) = delete;
		~Serializer() = delete;
		
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
}