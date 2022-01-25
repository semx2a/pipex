# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 19:14:12 by seozcan           #+#    #+#              #
#    Updated: 2022/01/24 17:50:50 by seozcan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------------------- #
#	 	   TARGET            #
# -------------------------- #

NAME	= pipex

# -------------------------- #
#          SOURCES           #
# -------------------------- #

SDIR	= srcs/

ODIR	= objs/

SRCS	= pipex.c pipex_utils.c

OBJS	= ${SRCS:.c=.o}

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

INC		= pipex.h

# -------------------------- #
#          LIBRARY           #
# -------------------------- #											

LDIR 	= libft/

LIB		= libft.a

# -------------------------- #
#          SCRIPTS           #
# -------------------------- #

$(NAME):	%: m_lib 
	$(CC) -o $(NAME) $(addprefix $(ODIR), $(OBJS)) $(addprefix $(LDIR), $(LIB)) && make clean 

# -------------------------- #
#           RULES            #
# -------------------------- #

all:		${NAME}

m_lib:		o_dir
	@make -C $(LDIR)

o_dir:		o_comp
	@mkdir $(ODIR)
	@mv $(OBJS) $(ODIR)

o_comp:
	$(CC) $(WFLAGS) -I $(IDIR) -c $(addprefix $(SDIR), $(SRCS))

git:
	@git add *
	@git commit -m 'update'
	@git push

clean:
	@rm -rf $(ODIR)
	@make -C $(LDIR) clean

fclean:		clean
	@rm ${NAME}
	@make -C $(LDIR) fclean

re:			fclean all

.PHONY:	all clean fclean re
