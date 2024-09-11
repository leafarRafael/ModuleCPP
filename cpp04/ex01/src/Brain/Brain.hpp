/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:09:26 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/10 10:44:20 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

#define BRAIN "Brain"
#define NBR_IDEAS 100

class Brain
{
	private:
		std::string	_ideas[NBR_IDEAS];

	public:
		~Brain();
		Brain();
		Brain(const Brain &ori);
		Brain&operator=(const Brain &ori);
		void setIdeas(int i, std::string newIdea);
		std::string getIdeas(int i) const;
};

#endif