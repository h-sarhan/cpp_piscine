/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:36:18 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/13 17:21:23 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED
#define FIXED

#include <iostream>

class Fixed
{
public:
	Fixed(void);
	Fixed(const Fixed &old);
	Fixed &operator=(const Fixed &old);
	~Fixed(void);

	int getRawBits(void) const;
	void setRawBits(const int raw);

private:
	int _rawBits;
	static const int _fracBits;
};
#endif