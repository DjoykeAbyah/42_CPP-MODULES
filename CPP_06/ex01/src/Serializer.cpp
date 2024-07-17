/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Serializer.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/17 11:09:32 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/17 11:47:23 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

//cast to an uintptr_t
uintptr_t Serializer::serialize(Data* ptr){
	return reinterpret_cast<uintptr_t>(ptr);
}

//cast to Data pointer
Data* Serializer::deserialize(uintptr_t raw){
	return reinterpret_cast<Data *>(raw);
}