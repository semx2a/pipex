# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 19:14:12 by seozcan           #+#    #+#              #
#    Updated: 2021/12/14 18:14:37 by seozcan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------------------- #
#	 	   TARGET            #
# -------------------------- #

NAME	= libftprintf.a

# -------------------------- #
#          SOURCES           #
# -------------------------- #

SDIR	= srcs/

ODIR	= objs/

SRCS	= ft_printf.c ft_numbers.c ft_strings.c 

OBJS	= ${SRCS:%.c=%.o}

# -------------------------- #
#         COMPILERS          #
# -------------------------- #

CC		= gcc

WFLAGS	= -Wall -Wextra -Werror

AR		= ar

ARFLAGS	= rcs

# -------------------------- #
#          HEADERS           #
# -------------------------- #

IDIR	= inc/

# -------------------------- #
#          SCRIPTS           #
# -------------------------- #

$(NAME):	%: o_dir 
	$(AR) $(ARFLAGS) $(NAME) $(addprefix $(ODIR), $(OBJS)) && make clean 

# -------------------------- #
#           RULES            #
# -------------------------- #

all:		${NAME}

o_dir:		o_comp
	@mkdir $(ODIR)
	@mv $(OBJS) $(ODIR)

o_comp:
	$(CC) $(WFLAGS) -I $(IDIR) -c $(addprefix $(SDIR), $(SRCS))

update:
	@git pull

git:
	@git add *
	@git commit -m 'update'
	@git push

clean:
	@rm -rf $(ODIR)

fclean:	
	@rm ${NAME}

re:			fclean all

.PHONY:	all clean fclean re
