/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 23:29:41 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/11/26 18:27:22 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog constructor called!" << std::endl;
	_brain = new Brain();
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
	std::cout << "Dog copy constructor called!" << std::endl;
	_brain = new Brain(*copy._brain);
}

Dog& Dog::operator=(const Dog& copy)
{
	std::cout << "Dog assignation operator called!" << std::endl;
	if (this != &copy)
	{
		Animal::operator=(copy);
		if (_brain)
			delete _brain;
		_brain = new Brain(*copy._brain);
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called!" << std::endl;
	delete _brain;
}

void Dog::makeSound() const
{
	std::cout << "Woof woof!" << std::endl;
}

Brain* Dog::getBrain()
{
	return _brain;
}

const Brain* Dog::getBrain() const
{
	return _brain;
}

void Dog::printBrain() const
{
	if (!_brain)
	{
		std::cerr << "Error: Dog's brain is not initialized!" << std::endl;
		return;
	}

	std::cout << "Dog's brain ideas:" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		std::string idea = _brain->getIdea(i);
		if (!idea.empty())
		{
			std::cout << "Idea " << i << ": " << idea << std::endl;
		}
	}
}
