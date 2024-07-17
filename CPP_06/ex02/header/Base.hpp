/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Base.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/17 12:18:19 by dreijans      #+#    #+#                 */
/*   Updated: 2024/07/17 15:44:33 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <random>

class Base {
	
	public:
		virtual ~Base() = default; // Ensuring Base is polymorphic with a virtual destructor
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base* generate(void);
void identify(Base *p);
void identify(Base &p);