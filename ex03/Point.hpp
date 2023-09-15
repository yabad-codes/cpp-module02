/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:10:21 by yabad             #+#    #+#             */
/*   Updated: 2023/09/15 17:12:05 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

class Point {
	private:
		const Fixed	x;
		const Fixed y;
	public:
		Point();
		Point(const float px, const float py);
		Point(const Point& other);
		~Point();
		Point&	operator=(const Point& other);
		const Fixed&	getX(void) const;
		const Fixed&	getY(void) const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);