/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teevee <teevee@students.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:46:14 by teevee            #+#    #+#             */
/*   Updated: 2021/05/25 14:46:47 by teevee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <vector>
# include <numeric>

class Span
{
	public:
		Span(unsigned int n);
		Span(Span const &ref);
		Span& operator=(Span const &ref);
		~Span();

		void				addNumber(int value);
		void				addNumber(int value, unsigned int start, unsigned end);
		unsigned int		shortestSpan();
		unsigned int		longestSpan();

		std::vector<int>	getVector();

		class NoSpanException : public std::exception
		{
			virtual const char* what() const throw();
		};
		class NoSpaceException : public std::exception
		{
			virtual const char* what() const throw();
		};

	private:
		Span();

		unsigned int		m_n;
		std::vector<int>	m_vec;
};

#endif