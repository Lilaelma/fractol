SRCS_DIR	= src/
SRC			= main.c \
			  color.c\
			  control.c\
			  utils.c\
			  mandelbrot.c\
			  julia.c\
			  manage.c

SRCS		= $(addprefix $(SRCS_DIR), $(SRC))

OBJS_DIR	= obj/
OBJ			= ${SRC:.c=.o}
OBJS		= $(addprefix $(OBJS_DIR), $(OBJ))

NAME		= fract-ol
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
MLX			= minilibx-linux/libmlx_Linux.a -L -I minilibx-linux/mlx.h -lXext -lX11 -lm

all:		${OBJS_DIR} ${NAME}

${OBJS_DIR}:
			mkdir ${OBJS_DIR}

${OBJS_DIR}%.o: ${SRCS_DIR}%.c
			${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
			${CC} ${FLAGS} ${OBJS} ${MLX} -o ${NAME}

clean:
			rm -rf ${OBJS_DIR}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re