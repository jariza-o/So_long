# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 15:06:08 by jariza-o          #+#    #+#              #
#    Updated: 2023/07/15 18:55:28 by jariza-o         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Libreries
LIBFT =		libft/libft.a

# Flags
CFLAGS =	-Wall -Werror -Wextra

# So_long
NAME =		so_long
SRC =		src/so_long.c src/map.c src/utils.c \
			src/errors/map_checker_utils.c src/errors/map_checker_utils2.c src/errors/map_errors.c \

OBJT =		$(SRC:.c=.o)

.c.o:
		gcc ${CFLAGS} -c $< -o ${<:.c=.o}

all:		$(NAME)

$(NAME): ${OBJT}
			make -C libft
			gcc ${CFLAGS} ${OBJT} ${LIBFT} -o ${NAME}

clean:
			rm -f ${OBJT}

fclean: 	clean
			rm -f ${NAME} 
			make fclean -s -C libft

re: 		fclean all

.PHONY: all bonus clean fclean re