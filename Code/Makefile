# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 15:06:08 by jariza-o          #+#    #+#              #
#    Updated: 2023/07/13 17:10:01 by jariza-o         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		so_long

# BONUS =		

SRC =		so_long.c

OBJT =		$(SRC:.c=.o)

# SRC_BONUS =	

# OBJT_BONUS =	$(SRC_BONUS:.c=.o)

CFLAGS =	-Wall -Werror -Wextra

LIBTF =		libft/libft.a
MLX42 =		MLX42/libmlx.a

.c.o:
		gcc ${CFLAGS} -c $< -o ${<:.c=.o}

all:		$(NAME)

$(NAME): ${OBJT}
			make -C libft
			MAKE -C MLX42
			gcc ${CFLAGS} ${OBJT} ${LIBFT} ${MLX42} -o ${NAME}

# $(BONUS): ${BONUS_OBJT}
# 			make -C libft
# 			gcc ${CFLAGS} ${BONUS_OBJT} ${LIBFT} -o ${BONUS}

# bonus: $(BONUS)

clean:
			rm -f ${OBJT}
			# rm -f ${BONUS_OBJT}

fclean: 	clean
			rm -f ${NAME} ${BONUS}
			make fclean -s -C libft

re: 		fclean all

.PHONY: all bonus clean fclean re py