/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 23:29:05 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/11/10 23:46:30 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	public:
		Animal();
		Animal(const Animal& copy);
		Animal(const char* type);
		Animal& operator=(const Animal& copy);
		virtual ~Animal();

		virtual void makeSound() const;
		std::string getType() const;
	
	protected:
		std::string _type;
};

#endif