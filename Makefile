NAME = fractol
CC = cc 
CFLAGS = -Wall -Wextra -Werror
MLX = -lmlx -lXext -lX11

SOURCE = main.c tools.c tools1.c utils.c
SOURCEH = fractol.h

OBJ = ${SOURCE:.c=.o}

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o $@ 

${NAME}: ${OBJ}
		${CC} ${CFLAGS} ${OBJ} -o ${NAME} ${MLX}

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

re: fclean all 