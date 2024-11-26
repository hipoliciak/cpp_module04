/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 23:29:36 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/11/26 18:27:41 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat constructor called!" << std::endl;
	_brain = new Brain();
}

Cat::Cat(const Cat& copy) : Animal(copy)
{
	std::cout << "Cat copy constructor called!" << std::endl;
	_brain = new Brain(*copy._brain);
}

Cat& Cat::operator=(const Cat& copy)
{
	std::cout << "Cat assignation operator called!" << std::endl;
	if (this != &copy)
	{
		Animal::operator=(copy);
		if (_brain)
			delete _brain;
		_brain = new Brain(*copy._brain);
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called!" << std::endl;
	delete _brain;
}

void Cat::makeSound() const
{
	std::cout << "Meow meow!" << std::endl;
}

Brain* Cat::getBrain()
{
	return _brain;
}

const Brain* Cat::getBrain() const
{
	return _brain;
}

void Cat::printBrain() const
{
	if (!_brain)
	{
		std::cerr << "Error: Cat's brain is not initialized!" << std::endl;
		return;
	}

	std::cout << "Cat's brain ideas:" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		std::string idea = _brain->getIdea(i);
		if (!idea.empty())
		{
			std::cout << "Idea " << i << ": " << idea << std::endl;
		}
	}
}
