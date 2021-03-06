# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/22 18:27:38 by lpilotto          #+#    #+#              #
#    Updated: 2016/03/04 12:03:24 by lpilotto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#OUT=LINUX
OUT=MAC
NAME=fractol
SRC=main.c \
	imghelper.c \
	mandelbrot.c \
	julia.c \
	burningship.c \
	key_hook.c \
	loop_hook.c \
	expose_hook.c \
	mouse_hook.c \
	mouse_moved.c
OBJ=$(subst .c,.o,$(SRC))
ifeq ($(OUT),MAC)
  LIBXFOLDER=./minilibx_macos
  LIBX=$(LIBXFOLDER)/libmlx.a
else
  LIBXFOLDER=./minilibx
  LIBX=$(LIBXFOLDER)/libmlx_Linux.a
endif
LIBFTFOLDER=./libft
LIBFT=$(LIBFTFOLDER)/libft.a
EFLAGS=-Wall -Werror -Wextra
IFLAGS=-I$(LIBFTFOLDER) -I./includes -I$(LIBXFOLDER)
ifeq ($(OUT),MAC)
  LFLAGS=-L$(LIBXFOLDER) -lmlx -framework OpenGL -framework AppKit -L$(LIBFTFOLDER) -lft
else
  LFLAGS=-L$(LIBXFOLDER) -lmlx_Linux -lXext -lX11 -L$(LIBFTFOLDER) -lft -lm
endif
CFLAGS=-D $(OUT)

.PHONY: all clean fclean re

$(NAME): $(LIBFT) $(LIBX) $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LFLAGS)

all: $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c $< $(EFLAGS) $(IFLAGS) -o $@

$(LIBX):
	make -C $(LIBXFOLDER) all

$(LIBFT):
	make -C $(LIBFTFOLDER) all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTFOLDER) fclean
	make -C $(LIBXFOLDER) clean

re: fclean all
