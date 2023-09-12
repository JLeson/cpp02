/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:16:02 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/09/12 16:34:12 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void)
{
	this->_bits = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed &fixed)
{
	this->_bits = fixed._bits;
	std::cout << "Copy contructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

void	Fixed::operator=(const Fixed &fixed)
{
	if (this != &fixed)
		this->_bits = fixed._bits;
	std::cout << "Copy assignment operator called" << std::endl;
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
