# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/04 00:48:08 by hsarhan           #+#    #+#              #
#    Updated: 2022/09/28 14:57:09 by hsarhan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Wno-shadow -Wshadow

NAME = scavtrap

SRC = main.cpp ClapTrap.cpp ScavTrap.cpp

OBJ := $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all re fclean clean