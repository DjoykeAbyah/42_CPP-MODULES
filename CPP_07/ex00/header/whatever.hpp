/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   whatever.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/22 19:07:52 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/22 19:15:30 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template<typename T>
void swap(T &a, T &b) {
	std::swap(a, b);
}

template<typename T>
T const & min(T const &a, T const &b) {
	return (a <= b ? a : b);
}

template<typename T>
T const & max(T const &a, T const &b) {
	return (a >= b ? a : b);
}