# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 15:06:08 by jariza-o          #+#    #+#              #
#    Updated: 2023/07/10 16:04:04 by jariza-o         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		so_long

// BONUS =		

SRC =		so_long.c

OBJT =		$(SRC:.c=.o)

// SRCBONUS =	

// BONUS_OBJ =	

CFLAGS =	-Wall -Werror -Wextra

LIBTF =		libft/libft.a

.c.o:
		gcc ${CFLAGS} -c $< -o ${<:.c=.o}

all:		$(NAME)

$(NAME): ${OBJT}
			make -C libft
			gcc ${CFLAGS} ${OBJT} ${LIBFT} -o ${NAME}

// $(BONUS): ${BONUS_OBJT}
// 			make -C libft
// 			gcc ${CFLAGS} ${BONUS_OBJT} ${LIBFT} -o ${BONUS}

// bonus: $(BONUS)

clean:
			rm -f ${OBJT}
			// rm -f ${BONUS_OBJT}

fclean: 	clean
			rm -f ${NAME} ${BONUS}
			make fclean -s -C libft

re: 		fclean all

.PHONY: all bonus clean fclean re py