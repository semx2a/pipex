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
#	 	   			  TARGET #
# -------------------------- #

NAME	= pipex

# -------------------------- #
#          			 SOURCES #
# -------------------------- #

SDIR	= srcs/

ODIR	= objs/

SRCS	= pipex.c utils.c cmds.c

OBJS	= ${SRCS:.c=.o}

# -------------------------- #
#        		   FUNCTIONS #
# -------------------------- #

FDIR	= fcts/

FSRCS	= ft_split.c ft_strjoin.c ft_strnstr.c ft_substr.c ft_strlen.c

FOBJS	= ${FSRCS:.c=.o}

# -------------------------- #
#					   BONUS #
# -------------------------- #

BDIR	= bonus/

BSRCS	= pipex_bonus.c utils_bonus.c cmds_bonus.c

BOBJS	= ${BSRCS:.c=.o}

# -------------------------- #
#			 	   COMPILERS #
# -------------------------- #

CC		= gcc

WFLAGS	= -Wall -Wextra -Werror

AR		= ar

ARFLAGS	= rcs

# -------------------------- #
#          			 HEADERS #
# -------------------------- #

IDIR	= inc/

INC		= pipex.h

# -------------------------- #
#         			 LIBRARY #
# -------------------------- #											

LDIR 	= libft/

LIB		= libft.a
# -------------------------- #
#					  COLORS #
# ---------------------------#

BLUE		=	\033[1;34m
CYAN		=	\033[0;36m
GREEN		=	\033[0;32m
ORANGE  	=	\033[0;33m
NO_COLOR	=	\033[m
PURPLE		=	\033[0;35m

# -------------------------- #
#           		   RULES #
# -------------------------- #

all:		header s_comp
	@$(CC) -o $(NAME) $(wildcard $(ODIR)*.o)
	@echo "$(GREEN)mandatory exe:						[OK]$(NO_COLOR)"

header:
	@echo -n "$(PURPLE)"
	@echo "      __________________  ________     ____  _______   ___________"
	@echo "     /                /  /      |     /    //     /   /         /"
	@echo "    /    /|     /    /  /       |    /    //    /    /   ______/"
	@echo "   /    / |  / /    /  /   /|   |   /         /     /   ___/__"
	@echo "  /    /  |/  /    /  /   __    |  /    /|    |    /         /"
	@echo " /____/      /____/  /___/  |___| /____/ |____|   /_________/"
	@echo "$(CYAN)"
	@echo "                                                     SEOZCAN "
	@echo "$(NO_COLOR)"

bonus:		b_comp
	@$(CC) -o $(NAME) $(wildcard $(ODIR)*.o)
	@echo "$(GREEN)bonus exe:							[OK]$(NO_COLOR)"

s_comp:		o_dir
	@$(CC) $(WFLAGS) -I $(IDIR) -c $(addprefix $(SDIR), $(SRCS)) $(addprefix $(FDIR), $(FSRCS)) 
	@echo "$(GREEN)compilation:				 	 	[OK]$(NO_COLOR)"
	@mv *.o $(ODIR)

b_comp:		o_dir
	@$(CC) $(WFLAGS) -I $(IDIR) -c $(addprefix $(BDIR), $(BSRCS)) $(addprefix $(FDIR), $(FSRCS))
	@echo "$(GREEN)bonus compilation:							[OK]$(NO_COLOR)"
	@mv *.o $(ODIR)

o_dir:
ifneq ($(wildcard $(ODIR)),)
	@echo "$(GREEN)objs folder:						[OK]$(NO_COLOR)"
else
	@mkdir $(ODIR)
	@echo "$(GREEN)objs folder:						[OK]$(NO_COLOR)"
endif

update:
	@git pull

git:
	@echo "n"
	@git add *
	@git commit -m 'update'
	@git push

clean:
ifneq ($(wildcard ./$(ODIR)),)
	@rm -rf $(ODIR)
	@echo "$(GREEN)objs folder:					[RM]$(NO_COLOR)"
else
	@rm $(wildcard *.o)
	@echo "$(GREEN)obj files:				[RM]$(NO_COLOR)"
endif

fclean:	clean
	@rm ${NAME}
	@echo "$(GREEN)$(NAME) executable:				[RM]$(NO_COLOR)"

re:		header fclean all

.PHONY:	all clean fclean re
