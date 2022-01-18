# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 19:14:12 by seozcan           #+#    #+#              #
#    Updated: 2022/01/18 19:43:56 by seozcan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

											   	# -------------------------- #
												#          TARGET            #
												# -------------------------- #

NAME	= pipex

												# -------------------------- #
												#          SOURCES           #
												# -------------------------- #
SDIR	= srcs/

ODIR	= objs/

SRCS	= $(addprefix $(SDIR), pipex.c pipex_main.c pipex_utils.c)

OBJS	= $(notdir ${SRCS:.c=.o})

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

INC		= $(addprefix $(IDIR), pipex.h)
												
												# -------------------------- #
                    							#          SCRIPTS           #
												# -------------------------- #

$(NAME):	$(OBJS) $(ODIR)
	$(CC) -o $(NAME) $(addprefix $(ODIR), $(OBJS)) 

$(ODIR):
	@mkdir $(ODIR)
	@mv $(OBJS) $(ODIR)

$(OBJS):	$(SRCS)
	$(CC) $(WFLAGS) -I $(INC) -c $(SRCS)

all:		${NAME}

clean:
	@rm -rf $(ODIR)

fclean:	clean
	@rm ${NAME}

re:		fclean all

.PHONY:	all clean fclean re
