# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/24 10:16:09 by lorobert          #+#    #+#              #
#    Updated: 2023/07/10 14:01:50 by lorobert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	cub3D

LIBS		:=	ft \
				mlx
LIBS_TARGET	:=	libs/libft/libft.a
MLX_TARGET	:=	libs/mlx/libmlx.a

INCS		:=	includes \
				libs/libft \
				libs/mlx

SRC_DIR		:=	sources

SRCS		:=	main.c \
				init.c \
				file_parser.c \
				color_parsing.c \
				texture_parsing.c \
				error.c \
				clean.c \
				check_map.c \
				check_map_invalid_char.c \
				check_map_is_closed.c \
				ft_strdup_tab_of_string.c \
				mlx_hooks.c \
				quit.c \
				raycasting.c \
				check_texture.c \
				ft_put_line.c \
				movements.c \
				rotations.c

SRCS		:=	$(SRCS:%=$(SRC_DIR)/%)

BUILD_DIR	:=	.build
OBJS		:=	$(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:=	$(OBJS:.o=.d)

CC			:=	gcc
CFLAGS		:=	-Wall -Wextra -Werror
CPPFLAGS	:=	$(addprefix -I,$(INCS)) -MMD -MP
LDFLAGS		:=	$(addprefix -L,$(dir $(LIBS_TARGET))) $(addprefix -L,$(dir $(MLX_TARGET)))
LDLIBS		:=	$(addprefix -l,$(LIBS))

RM			:=	rm -f
UNAME		:=	$(shell uname)
#MAKEFLAGS	+=	--no-print-directory
DIR_DUP		=	mkdir -p $(@D)

all: $(NAME)

$(NAME): $(LIBS_TARGET) $(MLX_TARGET) $(OBJS)
ifeq ($(UNAME),Linux)
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME) -lXext -lX11 -lm
else
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME) -framework OpenGL -framework Appkit -lm
endif

$(LIBS_TARGET):
	$(MAKE) -C $(@D)
$(MLX_TARGET):
	$(MAKE) -C $(@D)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

-include $(DEPS)

clean:
	for f in $(dir $(LIBS_TARGET)); do $(MAKE) -C $$f clean; done
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	for f in $(dir $(LIBS_TARGET)); do $(MAKE) -C $$f fclean; done
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
