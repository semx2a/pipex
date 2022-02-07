# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 19:14:12 by seozcan           #+#    #+#              #
#    Updated: 2022/02/07 13:51:16 by seozcan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------------------- #
# 	   TARGET            #
# -------------------------- #

NAME	= libft.a

# -------------------------- #
#          SOURCES           #
# -------------------------- #

SDIR	= srcs/

ODIR	= objs/

SRCS	= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c\
ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c\
ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strjoin.c\
ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c\
ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_split.c ft_itoa.c\
ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c\
ft_putnbr_base.c get_next_line.c ft_strcpy.c ft_strncpy.c ft_strcat.c\
ft_atoi_base.c ft_free_tab.c ft_print_tab.c ft_tabcpy.c ft_tablen.c

OBJS	= ${SRCS:%.c=%.o}

# -------------------------- #
#         COMPILERS          #
# -------------------------- #

CC	= gcc

WFLAGS	= -Wall -Wextra -Werror

AR	= ar

ARFLAGS	= rcs

# -------------------------- #
#          HEADERS           #
# -------------------------- #

IDIR	= inc/

INC	= libft.h

# -------------------------- #
#          SCRIPTS           #
# -------------------------- #

$(NAME):	%: o_dir
	${AR} ${ARFLAGS} ${NAME} $(addprefix $(ODIR), ${OBJS}) 

# -------------------------- #
#           RULES            #
# -------------------------- #

all:		${NAME}

o_dir:		o_comp
	@mkdir $(ODIR)
	@mv $(OBJS) $(ODIR)

o_comp:
	$(CC) $(WFLAGS) -I $(IDIR) -c $(addprefix $(SDIR), $(SRCS))

clean:
	@rm -rf $(ODIR)

fclean:		clean
	@rm ${NAME}

re:		fclean all

.PHONY:	all clean fclean re
