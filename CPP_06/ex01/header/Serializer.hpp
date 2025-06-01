/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Serializer.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/16 21:22:40 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/17 12:01:23 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdint>
#include "Data.hpp"

class Serializer {
	
	private:
		Serializer() = delete;
		Serializer(const Serializer &copy) = delete;
		Serializer& operator=(const Serializer &copy) = delete;
		~Serializer() = delete;
		
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};