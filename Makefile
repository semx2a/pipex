# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 19:14:12 by seozcan           #+#    #+#              #
#    Updated: 2022/02/22 20:53:09 by seozcan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::TARGET::

NAME	= pipex

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::SOURCES::

SDIR	= srcs/

ODIR	= objs/

SRCS	= pipex.c utils.c cmds.c

OBJS	= ${SRCS:.c=.o}

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::FUNCTIONS::

FDIR	= fcts/

FSRCS	= ft_split.c ft_strjoin.c ft_strnstr.c ft_substr.c ft_strlen.c\
ft_strdup.c

FOBJS	= ${FSRCS:.c=.o}

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::BONUS::

BDIR	= bonus/

BSRCS	= pipex_bonus.c utils_bonus.c cmds_bonus.c

BOBJS	= ${BSRCS:.c=.o}

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::COMPILERS::

CC		= gcc

WFLAGS	= -Wall -Wextra -Werror

GLAG	= -g3

SANFLAG	= -fsanitize=address

AR		= ar

ARFLAGS	= rcs

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::HEADERS::

IDIR	= inc/

INC		= pipex.h

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::LIBRARY::

LDIR 	= libft/

LIB		= libft.a

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::COLORS::

BLUE		=	\033[1;34m
CYAN		=	\033[0;36m
GREEN		=	\033[0;92m
ORANGE  	=	\033[0;33m
NO_COLOR	=	\033[m
PURPLE		=	\033[0;35m
BPURPLE		=	\033[1;35m
BGREEN		=	\033[1;92m
BCYAN		=	\033[1;36m
SCYAN		=	\033[3;36m

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::RULES::

all:		header clean $(NAME)
	@$(CC) -o $(NAME) $(wildcard $(ODIR)*.o)
	@echo "$(GREEN)mandatory exe:\t\t\t\t\t\t[OK]$(NO_COLOR)"

bonus:		header clean o_dir
	@$(CC) $(WFLAGS) -I $(IDIR) -c $(addprefix $(BDIR), $(BSRCS)) \
$(addprefix $(FDIR), $(FSRCS))
	@echo "$(GREEN)bonus compilation:\t\t\t\t\t[OK]$(NO_COLOR)"
	@mv *.o $(ODIR)
	@$(CC) -o $(NAME) $(ODIR)*.o
	@echo "$(GREEN)bonus exe:\t\t\t\t\t\t[OK]$(NO_COLOR)"

$(NAME):	o_dir	
	@$(CC) $(WFLAGS) -I $(IDIR) -c $(addprefix $(SDIR), $(SRCS)) \
$(addprefix $(FDIR), $(FSRCS)) 
	@echo "$(GREEN)mandatory compilation:\t\t\t\t\t[OK]$(NO_COLOR)"
	@mv $(OBJS) $(FOBJS) $(ODIR)

header:
	@echo -n "$(BPURPLE)"
	@echo "   ______________________________________________________"
	@echo "  /\     __________    ________    ___   ___    _______  \ "
	@echo " /  \   /\         \  /\   __  \  /\  \ /\  \  /\  ____\  \ "
	@echo "/    \  \ \  \ _/\  \ \ \   __  \ \ \  \ /_ /_ \ \  _\_/_  \ "
	@echo "\     \  \ \__\_/ \__\ \ \__\-\__\ \ \__\  \__\ \ \______\  \ "
	@echo " \     \  \/__/  \/__/  \/__/ /__/  \/__/ \/__/  \/______/   \ "
	@echo "  \     \_________ ___________________________________________\ "
	@echo "   \    /                                                     / "
	@echo "    \  /                   $(SCYAN) S E O Z C A N \
$(NO_COLOR)$(BPURPLE)            ____   / "
	@echo "     \/______________________________________________/\   \_/ "
	@echo "                                                     \ \___\ "
	@echo "                                                      \/___/ "
	@echo "$(NO_COLOR)"

o_dir:
	@mkdir -p $(ODIR)
	@echo "$(GREEN)objs folder:\t\t\t\t\t\t[OK]$(NO_COLOR)"

update: header fclean
	@git pull

push:	header fclean
	@echo -n "$(GREEN)"
	@git add .
	@git commit --quiet -m 'update'
	@git push --quiet
	@echo "$(GREEN)git push:\t\t\t\t\t\t[OK]$(NO_COLOR)"

debug: header
	@$(CC) $(WFLAGS) $(GFLAG) -I $(IDIR) $(addprefix $(FDIR), $(FSRCS)) \
	$(addprefix $(SDIR), $(SRCS))
	@echo "$(GREEN)debug executable:\t\t\t\t\t[OK]$(NO_COLOR)"

clean:	header
ifneq ($(wildcard ./$(ODIR)),)
	@rm -rf $(ODIR)
	@echo "$(GREEN)objs folder:\t\t\t\t\t\t[RM]$(NO_COLOR)"
else
	@rm -f $(wildcard *.o)
	@echo "$(GREEN)obj files:\t\t\t\t\t\t[RM]$(NO_COLOR)"
endif

fclean:	header clean
	@rm -f $(NAME)
	@echo "$(GREEN)$(NAME) executable:\t\t\t\t\t[OK]$(NO_COLOR)"
	
re:		header fclean all 

.PHONY:	all bonus clean fclean re push update o_dir debug
