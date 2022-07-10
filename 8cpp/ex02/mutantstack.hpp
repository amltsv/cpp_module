/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teevee <teevee@students.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:48:55 by teevee            #+#    #+#             */
/*   Updated: 2021/05/25 14:48:58 by teevee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <stack>
# include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack():
			std::stack<T>() {}
		MutantStack(MutantStack<T> const &ref):
			std::stack<T>(ref) {}
		MutantStack<T> &operator=(MutantStack<T> const &ref)
		{
			if (this != &ref)
				this->c = ref.c;
			return (*this);
		}
		virtual ~MutantStack() {}

		//typename define
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator					begin()
		{
			return (this->c.begin());
		}
		iterator					end()
		{
			return (this->c.end());
		}
		const_iterator				begin() const
		{
			return (this->c.begin());
		}
		const_iterator				end() const
		{
			return (this->c.end());
		}
		reverse_iterator			rbegin()
		{
			return (this->c.rbegin());
		}
		reverse_iterator			rend()
		{
			return (this->c.rend());
		}
		const_reverse_iterator		rbegin() const
		{
			return (this->c.rbegin());
		}
		const_reverse_iterator		rend() const
		{
			return (this->c.rend());
		}
};

#endif