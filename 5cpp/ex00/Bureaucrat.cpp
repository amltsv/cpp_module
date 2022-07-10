/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teevee <teevee@students.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 10:09:26 by teevee            #+#    #+#             */
/*   Updated: 2021/05/21 10:10:28 by teevee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade):
	m_name(name),
	m_grade(grade)
{
	if (m_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (m_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &ref):
	m_name(ref.getName()),
	m_grade(ref.getGrade())
{
	if (m_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (m_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &ref)
{
	if (this == &ref)
		return (*this);
	m_grade = ref.getGrade();
	if (m_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (m_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

void			Bureaucrat::increaseGrade()
{
	if (m_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	m_grade--;
}

void			Bureaucrat::decreaseGrade()
{
	if (m_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	m_grade++;
}

std::string		Bureaucrat::getName() const
{
	return (m_name);
}

int				Bureaucrat::getGrade() const
{
	return (m_grade);
}

const char* 	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("BureaucratClassException: Grade too High");
}

const char* 	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("BureaucratClassException: Grade too Low");
}

std::ostream& operator<<(std::ostream &out, Bureaucrat const &ref)
{
	out << ref.getName() << ", bureaucrat grade "
		<< ref.getGrade() << std::endl;
	return (out);
}