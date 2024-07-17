/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Base.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/17 12:18:19 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/17 13:45:03 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Base {
	
	public:
		virtual ~Base();
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

