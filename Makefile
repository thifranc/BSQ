# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thifranc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/04 19:24:34 by thifranc          #+#    #+#              #
#    Updated: 2016/02/16 17:35:16 by thifranc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = newline.c find_sqr.c wild_cases.c ft_bsq_opt.c bsq_opt.c laul.c

TEMP = newline.o find_sqr.o wild_cases.o ft_bsq_opt.o bsq_opt.o laul.o

INC = ft_all.h

NAME = bsq

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@gcc -c $(FLAGS) $(SRC) $(INC)
	@gcc $(TEMP) -o $(NAME)

clean :
	@/bin/rm -f $(TEMP)

fclean : clean
	@/bin/rm -f $(NAME)

re : fclean all
