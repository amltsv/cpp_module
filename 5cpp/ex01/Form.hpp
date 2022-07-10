/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teevee <teevee@students.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 10:11:33 by teevee            #+#    #+#             */
/*   Updated: 2021/05/21 10:12:43 by teevee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		// Canonical Form
		Form(std::string name, int signGrade, int executeGrade); // Constructor Overloading (생성자 오버로딩)
		Form(Form const &ref); // Copy constructor (복사생성자)
		Form& operator=(Form const &ref); // Assignation operator (할당연산자)
		~Form(); // Destructor (가상소멸자)
		// Canonical Form

		void				beSigned(Bureaucrat & ref);

		std::string			getName() const;
		bool				getSigned() const;
		int					getSignGrade() const;
		int					getExecuteGrade() const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		// Canonical Form
		Form();// Default constructor (기본생성자)
		// Canonical Form

		const std::string	m_name;
		bool				m_signed;
		const int			m_signGrade;
		const int			m_executeGrade;
};

std::ostream& operator<<(std::ostream &out, Form const &ref);

#endif