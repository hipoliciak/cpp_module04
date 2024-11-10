/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 23:32:35 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/11/10 23:50:01 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << "WrongAnimal constructor called!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) : _type(copy._type)
{
	std::cout << "WrongAnimal copy constructor called!" << std::endl;
}

WrongAnimal::WrongAnimal(const char* type) : _type(type)
{
	std::cout << "WrongAnimal type constructor called!" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy)
{
	std::cout << "WrongAnimal assignation operator called!" << std::endl;
	_type = copy._type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called!" << std::endl;
}

std::string WrongAnimal::getType() const
{
	std::cout << "WrongAnimal type getter called!" << std::endl;
	return _type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Generic WrongAnimal sound!" << std::endl;
}
