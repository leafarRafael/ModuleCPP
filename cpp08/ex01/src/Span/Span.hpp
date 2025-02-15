/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:02:28 by rbutzke           #+#    #+#             */
/*   Updated: 2024/10/20 16:27:19 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <list>
typedef unsigned int uint;

class Span{
	private:
		std::list <int>	_list;
		uint			_n;
		Span();

	public:
		~Span();
		Span(uint n);
		Span(const Span & orin);
		Span&operator=(const Span & orin);
		void	addNumber(int addnbr);
		int		shortestSpan();
		int		longestSpan();

		
		void	fillSpan(uint amount);
		void	fillSpan(int begin, int end);

};

#endif