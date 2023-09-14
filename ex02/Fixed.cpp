/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:34:39 by yabad             #+#    #+#             */
/*   Updated: 2023/09/14 19:13:35 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::FractionalBits = 8;

Fixed::Fixed() {
	this->FixedPointValue = 0;
}

Fixed::Fixed(const Fixed& other) {
	*this = other;
}

Fixed::Fixed(const int x) {
	this->FixedPointValue = x << this->FractionalBits;
}

Fixed::Fixed(const float x) {
	this->FixedPointValue = (int)roundf(x * (1 << this->FractionalBits));
}

Fixed::~Fixed() {
}

Fixed&	Fixed::operator=(const Fixed& other) {
	if (this != &other) {
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

bool	Fixed::operator>(const Fixed& other) const {
	return (this->FixedPointValue > other.getRawBits());
}

bool	Fixed::operator<(const Fixed& other) const {
	return (this->FixedPointValue < other.getRawBits());
}

bool	Fixed::operator>=(const Fixed& other) const {
	return (this->FixedPointValue >= other.getRawBits());
}

bool	Fixed::operator<=(const Fixed& other) const {
	return (this->FixedPointValue <= other.getRawBits());
}

bool	Fixed::operator==(const Fixed& other) const {
	return (this->FixedPointValue == other.getRawBits());
}

bool	Fixed::operator!=(const Fixed& other) const {
	return (this->FixedPointValue != other.getRawBits());
}

Fixed	Fixed::operator+(const Fixed& other) const {
	return (Fixed(this->FixedPointValue + other.getRawBits()));
}

Fixed	Fixed::operator-(const Fixed& other) const {
	return (Fixed(this->FixedPointValue - other.getRawBits()));
}

Fixed	Fixed::operator*(const Fixed& other) const {
	return (Fixed(this->FixedPointValue * other.getRawBits()));
}

Fixed	Fixed::operator/(const Fixed& other) const {
	return (Fixed(this->FixedPointValue / other.getRawBits()));
}

Fixed&	Fixed::operator++() {
	this->FixedPointValue++;
	return (*this);
}

Fixed&	Fixed::operator--() {
	this->FixedPointValue--;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	tmp(this->FixedPointValue);
	this->FixedPointValue++;
	return (tmp);
}

Fixed	Fixed::operator--(int) {
	Fixed	tmp(this->FixedPointValue);
	this->FixedPointValue--;
	return (tmp);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b) {
	return ((a < b) ? a : b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) {
	return ((a < b) ? a : b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b) {
	return ((a > b) ? a : b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) {
	return ((a > b) ? a : b);
}
