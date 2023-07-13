# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 15:06:08 by jariza-o          #+#    #+#              #
#    Updated: 2023/07/13 21:19:15 by jariza-o         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Libreries
LIBFT =		libft/libft.a
# MLX42 =		MLX42/libmlx.a

# Flags
CFLAGS =	-Wall -Werror -Wextra

# So_long
NAME =		so_long
SRC =		so_long.c map.c \
			errors/map_checker_utils.c errors/map_checker_utils2.c errors/map_errors.c \
OBJT =		$(SRC:.c=.o)

# So_long Bonus
# BONUS =		
# SRC_BONUS =	
# OBJT_BONUS =	$(SRC_BONUS:.c=.o)

.c.o:
		gcc ${CFLAGS} -c $< -o ${<:.c=.o}

all:		$(NAME)

$(NAME): ${OBJT}
			make -C libft
# make -C MLX42
# gcc ${CFLAGS} ${OBJT} ${LIBFT} ${MLX42} -o ${NAME}
			gcc ${CFLAGS} ${OBJT} ${LIBFT} -o ${NAME}

# $(BONUS): ${BONUS_OBJT}
# 			make -C libft
# 			gcc ${CFLAGS} ${BONUS_OBJT} ${LIBFT} -o ${BONUS}

# bonus: $(BONUS)

clean:
			rm -f ${OBJT}
# rm -f ${BONUS_OBJT}

fclean: 	clean
			rm -f ${NAME} 
# ${BONUS}
			make fclean -s -C libft
# make clean -s -C MLX42
re: 		fclean all

.PHONY: all bonus clean fclean re