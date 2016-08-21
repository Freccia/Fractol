#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile_MacOsX                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfabbro <lfabbro@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/16 12:25:58 by lfabbro           #+#    #+#              #
#    Updated: 2016/08/16 13:47:58 by lfabbro          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./include ./libftprintf ./minilibx_macos
LIB_PATH = ./libftprintf/ ./minilibx_macos/

FRAMEWORK = -framework OpenGL -framework Appkit

SRC_NAME = main.c fractol.c \
		   mandelbrot.c julia.c burnship.c bird_of_prey.c celtic.c druid.c \
		   buffalo.c cubic.c \
		   new.c draw.c zoom.c set.c colors.c free_data.c \
		   hook.c hook2.c mouse.c color_hook.c

OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAME = -lftprintf -lmlx -lm
NAME = fractol

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
LIB = $(addprefix -L,$(LIB_PATH))

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Ofast

all: lib
	@echo "\033[35;44m Make $(NAME) \033[0m"
	@make $(NAME)

$(NAME): $(OBJ)
	$(CC) $(INC) $^ -o $@ $(LIB) $(LIB_NAME) $(FRAMEWORK)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

.PHONY: all lib clean fclean re

lib:
	@make -C ./libftprintf/
	@echo "\033[35;44m Make minilibx \033[0m"
	@make -C ./minilibx_macos/

clean:
	rm -rf $(OBJ) $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)
	@make -C ./libftprintf/ fclean
	@make -C ./minilibx_macos/ clean

re: fclean
	@$(MAKE) all
