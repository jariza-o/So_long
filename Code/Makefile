# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 15:06:08 by jariza-o          #+#    #+#              #
#    Updated: 2023/08/15 16:01:55 by jariza-o         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Libreries
LIBFT =		libft/libft.a
MLX42 =		MLX42/libmlx42.a

# Flags
CFLAGS =	-Wall -Werror -Wextra -g

# So_long
NAME =		so_long
SRC =		src/so_long.c \
			src/map/map.c \
			src/game/render.c src/game/keys.c src/game/keys_2.c \
			src/errors/map_checker_utils.c src/errors/map_checker_utils2.c src/errors/map_errors.c \
			src/utils/help.c src/utils/free.c src/utils/utils.c \

OBJT =		$(SRC:.c=.o)

.c.o:
		gcc ${CFLAGS} -c $< -o ${<:.c=.o}

all:		$(NAME)

$(NAME): ${OBJT}
			@make -C libft
			@make -C MLX42
			@gcc ${CFLAGS} ${OBJT} ${LIBFT} $(MLX42) -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/jariza-o/.brew/opt/glfw/lib/" -o ${NAME}

clean:
			@rm -f ${OBJT}
			@rm -rf $(LIBMLX)/build
			@make clean -s -C libft
			@make clean -s -C MLX42

fclean: 	clean
			@rm -f ${NAME}
			@make fclean -s -C libft
			@make fclean -s -C MLX42

re: 		fclean all

.PHONY: all clean fclean re