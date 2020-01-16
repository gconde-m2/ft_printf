# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/15 09:31:09 by gconde-m          #+#    #+#              #
#    Updated: 2019/12/30 09:44:23 by gconde-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCS	=	ft_printf.c \
			ft_parse.c \
			ft_change.c \
			ft_flags.c \
			ft_clear.c \
			ft_width.c \
			ft_char.c \
			ft_string.c \
			ft_number.c \
			ft_direct.c \
			ft_printx.c \
			ft_numberu.c \
			ft_printaltx.c \
			ft_precision.c \
			libft/ft_itoa.c \
			libft/ft_itoa_base.c \
			libft/ft_strlen.c \
			libft/ft_putnbr.c \
		   	libft/ft_atoi.c \
			libft/ft_strnew.c \
			libft/ft_bzero.c \
			libft/ft_putstr_n.c	\
			putminuscero.c \
			libft/ft_putnbrmemory.c \
			ft_percent.c \

OBJS := $(SRCS:.c=.o)

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I.
RM		=	rm -f

all:		${NAME}
%.o:	%.c
	${CC} ${CFLAGS} -c $< -o $@ 
%.o:	libft/%.c
	${CC} ${CFLAGS} -c $< -o $@ 

${NAME}:	${OBJS}
			ar rcs ${NAME} libft/*.o ${OBJS}

debug:
	$(CC) $(CFLAGS) -g $(SRCS) libft/ft_*.c -I libft 

clean:
			${RM} ${OBJS}
fclean:		clean
	$(MAKE) -C libft fclean
	${RM} ${NAME} libft/*.o *.o

re:			fclean all
.PHONY:		all ${NAME} clean fclean re
