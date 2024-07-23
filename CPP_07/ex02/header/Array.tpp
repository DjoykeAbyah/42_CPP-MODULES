/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.tpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/23 19:34:17 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/23 20:38:49 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>
Array<T>::Array() : _data(nullptr) {}


template<typename T>
Array<T>::Array(const unsigned int n) {
	_data = new T[n](); //default initializes each element
}
