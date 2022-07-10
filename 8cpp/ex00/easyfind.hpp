/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teevee <teevee@students.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:45:31 by teevee            #+#    #+#             */
/*   Updated: 2021/05/25 14:45:32 by teevee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <iterator>
# include <vector>

class NotFoundException: public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return ("Error: Not found");
		};
};

template <typename T>
void	easyfind(T &container, int n)
{
	typename T::iterator it;

	it = find(container.begin(), container.end(), n);
	if (it == container.end())
		throw NotFoundException();
	std::cout << "Element " << n
		<< " at position " << distance(container.begin(), it) << std::endl;
}

#endif