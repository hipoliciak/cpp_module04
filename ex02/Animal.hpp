/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 23:29:05 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/11/26 18:41:39 by dmodrzej         ###   ########.fr       */
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

		virtual void makeSound() const = 0;
		std::string getType() const;
	
	protected:
		std::string _type;
};

#endif