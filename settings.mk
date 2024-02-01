ifndef SETTINGS_MK
	SETTINGS_MK := 1

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::TARGET::

NAME	=	pipex

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::SOURCE::

ifeq ($(MAKECMDGOALS),)
	SRC	= $Scmds.c \
	$Spipex.c \
	$Sutils.c
else ifeq ($(MAKECMDGOALS), all)
	SRC	= $Scmds.c \
	$Spipex.c \
	$Sutils.c
else ifeq ($(MAKECMDGOALS), bonus)
	SRC = $Scmds_bonus.c \
	$Spipex_bonus.c \
	$Sutils_bonus.c
endif

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::COMPILERS::

CC		=	clang

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

MLX		= 	$Mlibmlx_Linux.a

endif