# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fjimenez <fjimenez@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/19 15:30:42 by fjimenez          #+#    #+#              #
#    Updated: 2020/08/19 19:26:49 by fjimenez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Linux)
	LIBS := -L./mlx -lmlx -lXext -lX11 -lm
	MLX = mlx/libmlx.a
	MINILIBX = mlx
else ifeq ($(UNAME_S), Darwin)
	LIBS := -L mlx_darwin -lmlx -framework OpenGL -framework Appkit -lm
	MLX = mlx_darwin/libmlx.a
	MINILIBX = mlx_darwin
endif

NAME = Cub3D

SRC = ft_cub3d \
 	ft_read_map \
  	ft_parse_info \
   	ft_parse_info_2 \
    ft_parse_map \
	ft_get_info \
	ft_error \
	ft_init \
	ft_utils \
	ft_utils2 \
	ft_strdup_map \
	ft_fill_map \
	ft_keys \
	ft_move_player \
	ft_exit \
	ft_raycasting \
	ft_texture \
	ft_texture_wall \
	ft_save \
	ft_sprite \
	ft_init_storage \

SRCCUB = $(addsuffix .c, $(SRC))
OBJS = $(SRCCUB:.c=.o)

SRCGNL = gnl/get_next_line.c gnl/get_next_line_utils.c
GNL_OBJS = $(SRCGNL:.c=.o)

LIBFT = libft/libft.a

CC = gcc -Wall -Wextra -Werror

PURPLE = \033[0;35m
RED = \033[1;31m
RESET = \033[0m

RM = rm -rf

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(GNL_OBJS) $(MLX)
	@cd libft && make re
	@$(CC) ${SRCCUB} $(LIBFT) $(SRCGNL) ${LIBS} $(MLX) -o ${NAME}
	@echo "$(PURPLE)==========DONE=========="


$(MLX):
	@make -C $(MINILIBX)

clean:
	@$(RM) $(OBJS) $(GNL_OBJS)
	@make -C $(MINILIBX)/ clean
	@make -C libft/ clean

fclean: clean
	@$(RM) ${NAME}
	@echo "$(RED)==========REMOVED==========$(RESET)"

re : fclean all

.PHONY: all clean fclean re