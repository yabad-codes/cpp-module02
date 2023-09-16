/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:38:24 by yabad             #+#    #+#             */
/*   Updated: 2023/09/16 10:19:35 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(float const px, float const py) : x(px), y(py) {}

Point::Point(const Point& other) : x(other.getX()), y(other.getY()) {}

Point::~Point() {}

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
