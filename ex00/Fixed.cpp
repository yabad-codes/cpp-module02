/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 23:33:42 by yabad             #+#    #+#             */
/*   Updated: 2023/09/13 23:48:49 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::FractionalBits = 8;

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->FixedPointValue = 0;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	this->FixedPointValue = other.FixedPointValue;
}

Fixed&	Fixed::operator=(const Fixed& other) {
	if (this != &other) {
		std::cout << "Copy assignment operator called" << std::endl;
		this->FixedPointValue = other.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->FixedPointValue);
}

void	Fixed::setRawBits(int const raw) {
	this->FixedPointValue = raw;
}
