ifndef SETTINGS_MK
	SETTINGS_MK := 1

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::TARGET::

NAME	=	pipex

ifeq ($(MAKECMDGOALS), bonus)
NAME	=	pipex_bonus
endif

UNAME	=	$(shell uname)

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::SOURCE::

SRC	= 	$Scmds.c \
		$Spipex.c \
		$Sutils.c

ifeq ($(MAKECMDGOALS), bonus)
	SRC = $Scmds_bonus.c \
	$Spipex_bonus.c \
	$Sutils_bonus.c
endif

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::COMPILERS::

CC		=	gcc

ifneq ($(UNAME), Darwin)
CC	=	clang
endif

CFLAGS	=	-Wall -Wextra -Werror

AR		=	ar

ARFLAGS	=	rcs

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::LIBRARY::

IS_LIB	= 	true

LIB		= 	$Llibft.a

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::FT_PRINTF::

IS_PTF	= 	false

PTF		= 	$Plibftprintf.a

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::MINILIBX::

IS_MLX	= 	false

MLX		= 	$Mlibmlx_$(UNAME).a

endif