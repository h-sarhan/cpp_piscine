/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 08:19:45 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/15 08:33:21 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Calling default Brain constructor" << std::endl;
	srand(time(0));
	for (size_t i = 0; i < 100; i++)
	{
		ideas[i] = ideaList[rand() % 15];
	}
}

Brain::Brain(const Brain &old)
{
	std::cout << "Calling Brain copy constructor" << std::endl;
	for (size_t i = 0; i < 100; i++)
	{
		ideas[i] = old.ideas[i];
	}
}

Brain &Brain::operator=(const Brain &rhs)
{
	std::cout << "Calling Brain copy assignment constructor" << std::endl;
	if (&rhs == this)
	{
		return (*this);
	}
	for (size_t i = 0; i < 100; i++)
	{
		ideas[i] = rhs.ideas[i];
	}
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Calling Brain destructor" << std::endl;
}

const std::string Brain::ideaList[] = {
	"Animals generate 30 times more waste than humans which is 1.4 billion tons every year.",
	"Ants never sleep. Also they dont have lungs.",
	"A group of owls is called a parliament.",
	"A woodpecker can peck 20 times per second.",
	"Reindeer milk has more fat than cow milk.",
	"An elephant can smell water up to 3 miles away.",
	"A whale's heart beats only nine times a minute.",
	"At birth, a panda is smaller than a mouse and weighs about four ounces.",
	"Taurophobia is the fear of bulls.",
	"One million stray dogs and 500,000 stray cats live in New York City metropolitan area.",
	"Hippo's sweat is pink.",
	"Flamingos are pink because shrimp is one of their main sources of food.",
	"Cats can hear ultrasound.",
	"More than 45 million turkeys are cooked and eaten in the US at Thanksgiving.",
	"Cat owners are 30% less likely to suffer a heart attack."};