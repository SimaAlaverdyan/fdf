NAME			=	fdf

src				=	fdf.c \
					get_next_line.c \
					read_file.c \
					
HEAD			=	include/fdf.h

LIBFT			=	libft/libft.a

OBJS			=	${addprefix src/,${src:.c=.o}}

MLX_FLAGS		=	-lmlx -framework OpenGL -framework AppKit -lm

CC				=	gcc

CFLAGS			=	-Wall -Werror -Wextra -g -I $(HEAD)

.c.o			:
					${CC} ${CFLAGS}  -c $< -o ${<:.c=.o}

$(NAME)			:	${OBJS} ${LIBFT} ${HEAD}
					make -C mlx
					${CC} ${CFLAGS} ${LD_FLAGS} ${MLX_FLAGS} ${OBJS} -o ${NAME} $(LIBFT) 

$(LIBFT)		:
					make -C ./libft

all				:	${NAME}

clean			:	make fclean -C mlx
					make fclean -C libft
					@rm -rf ${OBJS}

fclean			:	clean
					@rm -rf ${NAME}

re				:	fclean all

.PHONY			:	all clean fclean re