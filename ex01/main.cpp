/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 23:29:15 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/11/26 18:39:04 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main(void)
{
    const int size = 6;
    const Animal* animals[size];

	// Create animals
	std::cout << "\n=== Creating Animals ===\n" << std::endl;

    for (int i = 0; i < size / 2; i++)
	{
        animals[i] = new Cat();
    }
    for (int i = size / 2; i < size; i++)
	{
        animals[i] = new Dog();
    }

    // Test Dog
    std::cout << "\n=== Testing Dog ===\n" << std::endl;

    // Create an original Dog and set an idea
    Dog originalDog;
    std::cout << "Setting idea in original Dog's brain..." << std::endl;
    originalDog.getBrain()->setIdea(0, "I want food!");

    // Create a deep copy of the Dog
    Dog copiedDog = originalDog;

    // Modify the copied Dog's idea
    std::cout << "Setting idea in copied Dog's brain..." << std::endl;
    copiedDog.getBrain()->setIdea(0, "I want to nap!");

    // Print ideas to verify deep copy
    std::cout << "Original Dog's idea 0: " 
              << originalDog.getBrain()->getIdea(0) << std::endl; // Should print "I want food!"
    std::cout << "Copied Dog's idea 0: " 
              << copiedDog.getBrain()->getIdea(0) << std::endl;   // Should print "I want to nap!"

    // Test Cat
    std::cout << "\n=== Testing Cat ===\n" << std::endl;

    // Create an original Cat and set an idea
    Cat originalCat;
    originalCat.makeSound(); // Should print "Meow meow!"
    std::cout << "Setting idea in original Cat's brain..." << std::endl;
    originalCat.getBrain()->setIdea(0, "I want food!");

    // Create a deep copy of the Cat
    std::cout << "Creating deep copy of Cat..." << std::endl;
    Cat copiedCat = originalCat;

    // Modify the copied Cat's idea
    std::cout << "Setting idea in copied Cat's brain..." << std::endl;
    copiedCat.getBrain()->setIdea(0, "I want to nap!");

    // Print ideas to verify deep copy
    std::cout << "Original Cat's idea 0: " 
              << originalCat.getBrain()->getIdea(0) << std::endl; // Should print "I want food!"
    std::cout << "Copied Cat's idea 0: " 
              << copiedCat.getBrain()->getIdea(0) << std::endl;   // Should print "I want to nap!"

    // Check uninitialized ideas
    std::cout << "\n=== Checking uninitialized ideas ===\n" << std::endl;
    for (int i = 1; i < 3; i++)
	{
        std::cout << "Idea " << i << " in original Dog: " 
                  << originalDog.getBrain()->getIdea(i) << std::endl; // Should print an empty string
        std::cout << "Idea " << i << " in copied Dog: " 
                  << copiedDog.getBrain()->getIdea(i) << std::endl;   // Should print an empty string
    }

	// Delete all animals
	std::cout << "\n=== Deleting Animals ===\n" << std::endl;

    for (int i = 0; i < size; i++)
	{
        delete animals[i];
    }

    return 0;
}
