/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/08 18:45:52 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/17 12:16:41 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main() {
	
    Data myData;
    uintptr_t serialized = Serializer::serialize(&myData);
    Data* deserialized = Serializer::deserialize(serialized);
	serialized = Serializer::serialize(deserialized);
	deserialized = Serializer::deserialize(serialized);

    std::cout << "Original address: " << &myData << std::endl;
    std::cout << "Serialized address: " << serialized << std::endl;
    std::cout << "Deserialized address: " << deserialized << std::endl;
	std::cout << "Serialized after deserialized address: " << serialized << std::endl;
    std::cout << "Deserialized after serialized address: " << deserialized << std::endl;
	return 0;
}