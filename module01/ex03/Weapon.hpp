/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 08:08:03 by hsarhan           #+#    #+#             */
/*   Updated: 2022/09/09 08:19:28 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON
#define WEAPON

#include <string>

class Weapon
{
public:
	Weapon(const std::string &type);
	const std::string &getType() const;
	void setType(const std::string &type);

private:
	std::string type;
};
#endif