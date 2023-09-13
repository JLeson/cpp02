/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:58:28 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/09/13 14:08:54 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void)
{
	this->_bits = 0;
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	this->_bits = fixed._bits;
	// std::cout << "Copy contructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	this->_bits = value << this->_fractional_bits;
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
{
	this->_bits = roundf(value * (1 << this->_fractional_bits));
	// std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" << std::endl;
}

void	Fixed::operator=(const Fixed &fixed)
{
	if (this != &fixed)
		this->_bits = fixed._bits;
	// std::cout << "Copy assignment operator called" << std::endl;
}

Fixed	Fixed::operator+(const Fixed &fixed) const
{
	return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &fixed) const
{
	return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &fixed) const
{
	return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &fixed) const
{
	return (Fixed(this->toFloat() / fixed.toFloat()));
}

Fixed	&Fixed::operator++(void)
{
	++this->_bits;
	return *this;
}

Fixed   Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->_bits++;
	return tmp;
}


Fixed	&Fixed::operator--(void)
{
	--this->_bits;
	return *this;
}

Fixed   Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->_bits--;
	return tmp;
}

bool	Fixed::operator<(const Fixed &fixed) const
{
	return (this->_bits < fixed._bits);
}

bool	Fixed::operator>(const Fixed &fixed) const
{
	return (this->_bits > fixed._bits);
}

bool	Fixed::operator<=(const Fixed &fixed) const
{
	return (this->_bits <= fixed._bits);
}

bool	Fixed::operator>=(const Fixed &fixed) const
{
	return (this->_bits >= fixed._bits);
}

bool	Fixed::operator==(const Fixed &fixed) const
{
	return (this->_bits == fixed._bits);
}

bool	Fixed::operator!=(const Fixed &fixed) const
{
	return (this->_bits != fixed._bits);
}

std::ostream	&operator<<(std::ostream &out, Fixed const &in) 
{
    out << in.toFloat();
    return out;
}

int	Fixed::toInt() const
{
	return this->_bits >> this->_fractional_bits;
}

float	Fixed::toFloat() const
{
	return ((float)this->_bits / (1 << this->_fractional_bits));
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_bits;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_bits = raw;
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{	
	if (a < b)
		return (a);
	return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{	
	if (a > b)
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}
