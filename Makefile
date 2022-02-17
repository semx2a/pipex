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

SRCS	= pipex.c utils.c cmds.c

OBJS	= ${SRCS:.c=.o}

# -------------------------- #
#         FUNCTIONS          #
# -------------------------- #

FDIR	= fcts/

FT_C	= ft_split.c ft_strjoin.c ft_strlen.c ft_strnstr.c ft_substr.c

F_OBJS	= ${FT_C:.c=.o}

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

#----------------------------#
#		  FT_PRINTF			 #
#----------------------------#

PFDIR	= ft_printf/

PFLIB	= libftprintf.a

# -------------------------- #
#          SCRIPTS           #
# -------------------------- #

$(NAME):	%: mk_pf o_dir
	$(CC) -o $(NAME) $(addprefix $(ODIR), $(OBJS)) $(addprefix $(ODIR), $(F_OBJS)) && make clean 

# -------------------------- #
#           RULES            #
# -------------------------- #

all:		${NAME}

mk_pf:
	@make -C $(PFDIR)

o_dir:		o_comp
	@mkdir $(ODIR)
	@mv $(OBJS) $(F_OBJS) $(ODIR)

o_comp:
	$(CC) $(WFLAGS) -I $(IDIR) -c $(addprefix $(SDIR), $(SRCS)) $(addprefix $(FDIR), $(FT_C)) -L $(addprefix $(PFDIR), $(PFLIB))

update:
	@git pull

git:
	@git add *
	@git commit -m 'update'
	@git push

clean:
	@rm -rf $(ODIR)	
	@make -C $(FT_PF) clean

fclean:
	@rm ${NAME}
	@make -C $(FT_PF) fclean

re:			fclean all

.PHONY:	all clean fclean re
