SRCS		= ft_printf.c\
			  ft_printf_utils.c\
			  ft_printf_unsigned.c\
			  ft_printf_ptr.c\
			  ft_printf_hexU.c\
			  ft_itoa.c\

OBJS        = ${SRCS:.c=.o}

NAME        = libftprintf.a

HEADER        = ft_printf.h

CC            = gcc

RM            = rm -f

CFLAGS        = -Wall -Wextra -Werror

.c.o:        
			${CC} ${CFLAGS} -c $< -o $@  -include ${HEADER}

all:        ${NAME}

${NAME}:    ${OBJS}
			ar -rcs ${NAME} ${OBJS}

clean:        
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
