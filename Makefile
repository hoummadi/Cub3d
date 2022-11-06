# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/10 17:22:38 by hhoummad          #+#    #+#              #
#    Updated: 2021/01/20 18:39:48 by hhoummad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wextra -Werror -Wall

HEADER = cub3d.h

HEADERB = bonus/cub3d_bonus.h

SRC = ft_angles.c							\
	  ft_init.c								\
	  ft_player.c							\
	  ft_redirect1.c						\
	  ft_start.c							\
	  ft_bmp_save.c							\
	  ft_initial_3d.c						\
	  ft_ray.c								\
	  ft_redirect2.c						\
	  ft_update.c							\
	  ft_check_wall.c						\
	  ft_main.c								\
	  ft_ray_utils.c						\
	  ft_redirect_utils.c					\
	  ft_ck_map.c							\
	  ft_map_utils.c						\
	  ft_ray_utils2.c						\
	  ft_sprite.c							\
	  ft_draw.c								\
	  ft_map_utils2.c						\
	  ft_read.c								\
	  ft_sprite_utils.c						\
	  get_next_line/get_next_line.c			\
	  get_next_line/get_next_line_utils.c

SRCB = bonus/ft_angles_bonus.c				\
	   bonus/ft_init_bonus.c				\
	   bonus/ft_player_bonus.c				\
	   bonus/ft_redirect1_bonus.c			\
	   bonus/ft_start_bonus.c				\
	   bonus/ft_bmp_save_bonus.c			\
	   bonus/ft_initial_3d_bonus.c			\
	   bonus/ft_ray_bonus.c					\
	   bonus/ft_redirect2_bonus.c			\
	   bonus/ft_update_bonus.c				\
	   bonus/ft_check_wall_bonus.c			\
	   bonus/ft_main_bonus.c				\
	   bonus/ft_ray_utils_bonus.c			\
	   bonus/ft_redirect_utils_bonus.c		\
	   bonus/ft_ck_map_bonus.c				\
	   bonus/ft_map_utils_bonus.c			\
	   bonus/ft_ray_utils2_bonus.c			\
	   bonus/ft_sprite_bonus.c				\
	   bonus/ft_draw_bonus.c				\
	   bonus/ft_map_utils2_bonus.c			\
	   bonus/ft_read_bonus.c				\
	   bonus/ft_sprite_utils_bonus.c		\
	   bonus/ft_hud_vie_bonus.c				\
	   get_next_line/get_next_line.c		\
	   get_next_line/get_next_line_utils.c

NAME = cub3D

all: $(NAME)

$(NAME): $(SRC) $(HEADER)
	@cd libft && make
	@clang $(FLAG) -I /usr/local/include $(SRC) ./libft/libft.a -L /usr/local/lib -lmlx -framework OpenGl -framework Appkit -o $(NAME)
	@echo "make cub3D"

bonus: $(SRCB) $(HEADERB)
	@cd libft && make
	@clang $(FLAG) -I /usr/local/include $(SRCB) ./libft/libft.a -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "make cub3D bonus"

clean:
	@cd libft && make clean

fclean:
	@cd libft && make fclean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re bonus
