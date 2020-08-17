# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fernando <fernando@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/09 18:07:21 by fernando          #+#    #+#              #
#    Updated: 2020/05/16 17:49:48 by fernando         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D

SRCCUB =	ft_cub3d.c \
		ft_read_map.c \
		ft_parse_info.c \
		ft_parse_info_2.c \
		ft_parse_map.c \
		ft_get_info.c \
		ft_error.c \
		ft_init.c \
		ft_utils.c \
		ft_utils2.c \
		ft_strdup_map.c \
		ft_fill_map.c \
		ft_keys.c \
		ft_move_player.c \
		ft_exit.c \
		ft_raycasting.c \
		ft_texture.c \
		ft_texture_wall.c \
		ft_save.c \
		ft_sprite.c \
		ft_init_storage.c \

OBJS = $(SRCCUB:.c=.o)

SRCGNL = gnl/get_next_line.c gnl/get_next_line_utils.c
GNL_OBJS = $(SRCGNL:.c=.o)

LIBFT = libft/libft.a

LIBS    = -L./mlx -lmlx -lXext -lX11 -lm
MLX		= mlx/libmlx.a

CC = gcc -Wall -Wextra -Werror 

RM = rm -rf
	
all:  $(LIBFT)  $(NAME)

$(NAME): $(OBJS) $(GNL_OBJS) $(MLX)
	@make -C libft/
	@make -C mlx/
	$(CC) ${SRCCUB} $(LIBFT) $(SRCGNL) ${LIBS} $(MLX) -o ${NAME}
	@echo =======DONE=======

$(MLX):
	$(MAKE) -C mlx

%.o : %.c
	gcc -Imlx -o $@ -c $<

clean:
	$(RM) $(OBJS) $(GNL_OBJS) ${NAME}
	make -C mlx/ clean
	make -C libft/ clean

fclean: clean

re : fclean all
