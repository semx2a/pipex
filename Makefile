# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 19:14:12 by seozcan           #+#    #+#              #
#    Updated: 2022/01/18 19:31:48 by seozcan          ###   ########.fr        #
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

CFLAG 	= -c

OFLAG	= -o

IFLAG	= -I

AR		= ar

ARFLAGS	= rcs

												# -------------------------- #
                    							#          HEADERS           #
												# -------------------------- #
IDIR	= inc/

INC		= $(addprefix $(IDIR), pipex.h)

												# -------------------------- #
												#          TOOLBOX           #
												# -------------------------- #

RM		= rm -f

MV		= mv

												# -------------------------- #
                    							#          SCRIPTS           #
												# -------------------------- #

$(NAME):	$(OBJS) $(MV)
	$(CC) $(OFLAG) $(NAME) $(addprefix $(ODIR), $(OBJS)) 

$(MV):		$(OBJS)
	$(MV) $(OBJS) $(ODIR)

$(OBJS):	$(SRCS)
	$(CC) $(WFLAGS) $(IFLAG) $(INC) $(CFLAG) $(SRCS)

all:		${NAME}

clean:
	${RM} $(addprefix $(ODIR), $(OBJS))

fclean:	clean
	${RM} ${NAME}

re:		fclean all

.PHONY:	all clean fclean re
