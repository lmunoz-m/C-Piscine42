SRCS = aux_functions.c aux_main.c bsq.c check_map.c check.c create_array.c free_memory.c input_map.c main.c print.c transform.c 

OBJS = ${SRCS:.c=.o}

NAME = bsq

CC = gcc
RM	= rm -f

CFLAGS	= -Wall -Werror -Wextra

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY:	all clean fclean re
