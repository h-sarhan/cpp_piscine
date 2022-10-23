/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:34:43 by hsarhan           #+#    #+#             */
/*   Updated: 2022/10/23 14:35:15 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE
#define SERIALIZE

#include "Data.hpp"
#include <stdint.h>

uintptr_t serialize(Data *ptr);
Data *deserialize(uintptr_t raw);
#endif