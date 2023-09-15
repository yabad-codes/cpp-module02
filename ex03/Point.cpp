/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:38:24 by yabad             #+#    #+#             */
/*   Updated: 2023/09/15 20:03:25 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {
	// std::cout << "Point Default constructor called" << std::endl;
}

Point::Point(float const px, float const py) : x(px), y(py) {
	// std::cout << "Point Float constructor called" << std::endl;
}

Point::Point(const Point& other) : x(other.getX()), y(other.getY()) {
	// std::cout << "Point Copy constructor called" << std::endl;
}

Point::~Point() {
	// std::cout << "Point Destructor called" << std::endl;
}

Point&	Point::operator=(const Point& other) {
	if (this == &other)
		return (*this);
	return (*this);
}

const Fixed&	Point::getX(void) const {
	return (this->x);
}

const Fixed&	Point::getY(void) const {
	return (this->y);
}
