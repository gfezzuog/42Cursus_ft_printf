# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 16:57:34 by dgioia            #+#    #+#              #
#    Updated: 2022/04/01 18:06:35 by dgioia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = src/ft_printf.c \
	   src/ft_printhex.c \
	   src/ft_put_ptr.c \
	   src/ft_putchar.c \
       src/ft_putnbr.c \
	   src/ft_putstr.c \
	   src/ft_write.c \
	   src/ft_putunbr.c \


OBJS = ${SRCS:.c=.o}
RM = rm -f
FLAGS = -Wall -Wextra -Werror
INCS = .
LIBC = ar -rcs

.c.o :
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I${INCS}
	
$(NAME) : ${OBJS}
	${LIBC} ${NAME} ${OBJS}
	
all: $(NAME)

fclean:  clean
	$(RM) $(NAME)
	
clean:
	$(RM) -f $(OBJS)
	
re: fclean all

.PHONY: all clean fclean re .c.o