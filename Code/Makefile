# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 15:06:08 by jariza-o          #+#    #+#              #
#    Updated: 2023/02/28 12:18:28 by jariza-o         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Libreries
LIBFT =		libft/libft.a
MLX42 =		MLX42/libmlx42.a

# Flags
CFLAGS =	-Wall -Werror -Wextra

# So_long
NAME =		so_long
SRC =		src/so_long.c \
			src/map/map.c \
			src/game/render.c src/game/keys.c src/game/keys_2.c \
			src/errors/map_checker_utils.c src/errors/map_checker_utils2.c src/errors/map_errors.c \
			src/utils/help.c src/utils/free.c src/utils/utils.c \

OBJT =		$(SRC:.c=.o)

# So_long Bonus
BONUS =		so_long_bonus
SRC_BONUS =	src_bonus/so_long.c \
			src_bonus/map/map.c \
			src_bonus/game/render.c src_bonus/game/keys.c src_bonus/game/keys_2.c src_bonus/game/keys_bonus.c \
			src_bonus/errors/map_checker_utils.c src_bonus/errors/map_checker_utils2.c src_bonus/errors/map_errors.c \
			src_bonus/utils/help.c src_bonus/utils/free.c src_bonus/utils/utils.c \
OBJT_BONUS =	$(SRC_BONUS:.c=.o)

.c.o:
		gcc ${CFLAGS} -c $< -o ${<:.c=.o}

all:		$(NAME)

$(NAME): ${OBJT}
			make -C libft
			make -C MLX42
			gcc ${CFLAGS} ${OBJT} ${LIBFT} $(MLX42) -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/jariza-o/.brew/opt/glfw/lib/" -o ${NAME}

bonus:		$(BONUS)

$(BONUS): ${BONUS_OBJT}
			make -C libft
			make -C MLX42
			gcc ${CFLAGS} ${OBJT_BONUS} ${LIBFT} $(MLX42) -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/jariza-o/.brew/opt/glfw/lib/" -o ${BONUS}

clean:
			rm -f ${OBJT}
			rm -f ${OBJT_BONUS}
			rm -rf $(LIBMLX)/build
			make clean -s -C libft
			make clean -s -C MLX42

fclean: 	clean
			rm -f ${NAME}
			rm -f ${BONUS}
			make fclean -s -C libft
			make fclean -s -C MLX42

re: 		fclean all

.PHONY: all bonus clean fclean re