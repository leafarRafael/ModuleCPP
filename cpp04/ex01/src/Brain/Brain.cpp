/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:09:31 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/10 13:41:36 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Color.hpp"
#include "Brain.hpp"

static void msg(std::string msg);

Brain::~Brain(){
	msg("Destructor ");
}

Brain::Brain(){
	msg("Constructor ");
	for (int i = 0; i < NBR_IDEAS; i++)
		this->_ideas[i] = "";
}

Brain::Brain(const Brain &ori){
	msg("Copy Constructor ");
	for (int i = 0; i < NBR_IDEAS; i++)
		this->_ideas[i] = ori._ideas[i];
}

Brain &Brain::operator=(const Brain &ori){
	msg("Copy assignment operator ");
	for (int i = 0; i < NBR_IDEAS; i++)
		this->_ideas[i] = ori._ideas[i];
	return (*this);
}

void Brain::setIdeas(int i, std::string newIdea){
	if (i < 0 && i > 99)
		i = 0;
	this->_ideas[i] = newIdea;
}

std::string Brain::getIdeas(int i) const {
	if (i < 0 && i > 99)
		i = 0;
	return (this->_ideas[i]);		
}

static void msg(std::string msg)
{
	std::cout
	<< BLUE << msg << RESET
	<< BRAIN
	<< BLUE << " is called" << RESET
	<< std::endl;
}