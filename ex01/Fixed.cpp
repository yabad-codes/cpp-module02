/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:34:39 by yabad             #+#    #+#             */
/*   Updated: 2023/09/15 21:38:55 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::FractionalBits = 8;

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->FixedPointValue = 0;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	this->FixedPointValue = other.getRawBits();
}

Fixed::Fixed(const int x) {
	std::cout << "Int constructor called" << std::endl;
	this->FixedPointValue = x << this->FractionalBits;
}

Fixed::Fixed(const float x) {
	std::cout << "Float constructor called" << std::endl;
	this->FixedPointValue = (int)roundf(x * (1 << this->FractionalBits));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& other) {
	if (this != &other) {
		std::cout << "Copy assignment operator called" << std::endl;
		this->FixedPointValue = other.getRawBits();
	}
	return (*this);
}

int		Fixed::getRawBits(void) const {
	return (this->FixedPointValue);
}

void	Fixed::setRawBits(int const raw) {
	this->FixedPointValue = raw;
}

float	Fixed::toFloat(void) const {
	return ((float)this->FixedPointValue / (float)(1 << this->FractionalBits));
}

int		Fixed::toInt(void) const {
	return (this->FixedPointValue >> this->FractionalBits);
}

std::ostream&	operator<<(std::ostream& COUT, const Fixed& fixed) {
	COUT << fixed.toFloat();
	return (COUT);
}