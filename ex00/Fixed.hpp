/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:07:42 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/09/12 15:53:21 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
class Fixed
{
private:
	int 				_bits;
	static const int	_fractional_bits = 8;
public:
	Fixed(void);
	Fixed(Fixed &fixed);
	~Fixed();
	void	operator=(const Fixed &fixed);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};
