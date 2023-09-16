/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:14:48 by yabad             #+#    #+#             */
/*   Updated: 2023/09/16 11:30:35 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#define GUESS 100

float my_sqrt(float x) {
    if (x < 0)
        return -1.0;
    float guess = x / 2.0;
    for (int i = 0; i < GUESS; i++) {
        guess = (guess + x / guess) / 2.0; //Newton-Raphson method for approximation
    }
    return (guess);
}

Fixed	getSide(Point const a, Point const b) {
	float	distance;

	distance = my_sqrt((b.getX().toFloat() - a.getX().toFloat()) * (b.getX().toFloat() - a.getX().toFloat()) + (b.getY().toFloat() - a.getY().toFloat()) * (b.getY().toFloat() - a.getY().toFloat()));
	return (Fixed(distance));
}

Fixed	getArea(Point const a, Point const b, Point const c) {
	Fixed	p((getSide(a, b) + getSide(a, c) + getSide(b, c)) / 2);
	Fixed	area(my_sqrt(Fixed(p * (p - getSide(a, b)) * (p - getSide(b, c)) * (p - getSide(a, c))).toFloat()));
	return (area);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed	triangleArea(getArea(a, b, c));
	Fixed	areaSurface1(getArea(a, b, point));
	Fixed	areaSurface2(getArea(point, b, c));
	Fixed	areaSurface3(getArea(point, a, c));

	std::cout << "main triangle : " << roundf(triangleArea.toFloat()) << std::endl; 
	std::cout << "area surface 1 : " << roundf(areaSurface1.toFloat()) << std::endl; 
	std::cout << "area surface 2 : " << roundf(areaSurface2.toFloat()) << std::endl; 
	std::cout << "area surface 3 : " << roundf(areaSurface3.toFloat()) << std::endl; 
	if (!areaSurface1.toFloat() || !areaSurface2.toFloat() || !areaSurface3.toFloat())
		return (false);
	if (roundf(areaSurface1.toFloat() + areaSurface2.toFloat() + areaSurface3.toFloat()) == roundf(triangleArea.toFloat()))
		return (true);
	return (false);
}
