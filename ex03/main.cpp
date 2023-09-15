/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:53:46 by yabad             #+#    #+#             */
/*   Updated: 2023/09/15 20:15:29 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main( void ) {
	Point	a(-2, 5);
	Point	b(-4, -1);
	Point	c(3, -3);
	Point	d(-3, 1.5);

	if (bsp(a, b, c, d) == true)
		std::cout << "The point is inside the triangle" << std::endl;
	else
		std::cout << "The point doesn't belong to the triangle" << std::endl;
	return (0);
}
