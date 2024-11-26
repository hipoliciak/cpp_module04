/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 23:28:57 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/11/10 23:49:39 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "Animal constructor called!" << std::endl;
}

Animal::Animal(const Animal& copy) : _type(copy._type)
{
	std::cout << "Animal copy constructor called!" << std::endl;
}

Animal::Animal(const char* type) : _type(type)
{
	std::cout << "Animal type constructor called!" << std::endl;
}

Animal& Animal::operator=(const Animal& copy)
{
	std::cout << "Animal assignation operator called!" << std::endl;
	_type = copy._type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called!" << std::endl;
}

std::string Animal::getType() const
{
	std::cout << "Animal type getter called!" << std::endl;
	return _type;
}

void Animal::makeSound() const
{
	std::cout << "Generic animal sound!" << std::endl;
}
