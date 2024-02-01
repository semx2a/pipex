# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 19:14:12 by seozcan           #+#    #+#              #
#    Updated: 2024/02/01 18:13:09 by seozcan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include settings.mk

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::DIRECTORIES::

ifeq ($(MAKECMDGOALS),)
	S = src/
else ifeq ($(MAKECMDGOALS), all)
	S = src/
else ifeq ($(MAKECMDGOALS), bonus)
	S = bonus/
endif

O		=	obj/
I 		=	inc/
D 		=	dep/
L 		=	Libft/
P 		=	ft_printf/
M 		=	minilibx-linux/


# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::CUSTOM FLAGS::

CFLAGS	+=	-I$I

ifeq ($(IS_LIB), true)
	CFLAGS	+=	-I$L$I
	LIBS += $(LIB)
endif

ifeq ($(IS_PTF), true)
	CFLAGS	+=	-I$P$I
	LIBS += $(PTF)
endif

ifeq ($(IS_MLX), true)
	CFLAGS	+=	-I$M
	LIBS += $(MLX)
endif

CLFAGS	+=	-Wconversion

CFLAGS	+=	-g3 -fsanitize=address

ifeq ($(IS_MLX), true)
	MLXFLAGS	=	-lXext -lX11 -lm
endif

RM		=	/bin/rm -rf

SPACE 	= 	awk -F ':' '{ printf "%-61s %s\n", $$1 ":", $$2 }'


# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::OBJECTS::

OBJ		=	$(SRC:$S%=$O%.o)

DEP		=	$(SRC:$S%=$D%.d)

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::RULES::

all: header lib h2 message $(NAME)

bonus: all

$O:
	@mkdir -p $@
	@echo "$(HIGREEN)creating $O folder:[OK]$(RESET)" | $(SPACE)

$(OBJ): | $O

$(OBJ): $O%.o: $S%
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(HIGREEN)compiling $<:[OK]$(RESET)" | $(SPACE)

$D:
	@mkdir -p $@
	@echo "$(HIGREEN)creating $D folder:[OK]$(RESET)" | $(SPACE)

$(DEP): | $D

$(DEP): $D%.d: $S%
	@$(CC) $(CFLAGS) -MM -MF $@ -MT "$O$*.o $@" $<
	@echo "$(HIGREEN)compiling $<:[OK]$(RESET)" | $(SPACE)


$(NAME): $(OBJ) $(DEP)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)
	@echo "$(HIGREEN)compiling $(NAME):[OK]$(RESET)" | $(SPACE)

lib:
ifeq ($(IS_LIB),true)
	@make -C $L --quiet
endif
ifeq ($(IS_PTF),true)
	@make -C $P --quiet
endif
ifeq ($(IS_MLX),true)
	@make -C $M --quiet 
endif

cleanobj:
	@$(RM) $(O)
	@echo "$(HIORANGE)removing $O folder:[RM]$(RESET)" | $(SPACE)

cleandep:
	@$(RM) $(D)
	@echo "$(HIORANGE)removing $D folder:[RM]$(RESET)" | $(SPACE)

clean: header h2 cleanobj cleandep

fcleanlib: header
ifeq ($(IS_LIB),true)
	@make -C $L --quiet fclean
endif
ifeq ($(IS_PTF),true)
	@make -C $P --quiet fclean
endif
ifeq ($(IS_MLX),true)
	@make -C $M --quiet clean
endif

fclean: header fcleanlib h2 clean
	@$(RM) $(NAME)
	@echo "$(HIORANGE)removing $(NAME):[RM]$(RESET)" | $(SPACE)
	
re:	header fclean all

include colors.mk output.mk header.mk

.PHONY:	all clean fclean re