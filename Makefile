# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/24 10:16:09 by lorobert          #+#    #+#              #
#    Updated: 2023/05/24 14:54:49 by lorobert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	cub3D

LIBS	:=	ft
LIBS_TARGET	:=	libs/libft/libft.a

INCS		:=	includes \
				libs/libft

SRC_DIR		:=	sources

SRCS		:=	main.c \
				init.c \
				file_parser.c \
				error.c \
				clean.c

SRCS		:=	$(SRCS:%=$(SRC_DIR)/%)

BUILD_DIR	:=	.build
OBJS		:=	$(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:=	$(OBJS:.o=.d)

CC			:=	gcc
CFLAGS		:=	-Wall -Wextra -Werror -g -fsanitize=address
CPPFLAGS	:=	$(addprefix -I,$(INCS)) -MMD -MP
LDFLAGS		:=	$(addprefix -L,$(dir $(LIBS_TARGET))) -fsanitize=address
LDLIBS		:=	$(addprefix -l,$(LIBS))

RM			:=	rm -f
MAKEFLAGS	+=	--no-print-directory
DIR_DUP		=	mkdir -p $(@D)

all: $(NAME)

$(NAME): $(LIBS_TARGET) $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)

$(LIBS_TARGET):
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
.SILENT:
