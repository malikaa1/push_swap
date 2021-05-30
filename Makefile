NAME = push_swap
SRCS = ${wildcard ./srcs/*.c}
INCLUDES = ./includes
CC = gcc
LIBFT_FLAGS = -I./libft -L./libft -lft
LIBFT_DIR =./libft
SRCS_LIBFT = ${wildcard ./libft/*.c}
OBJS_LIBFT = ${SRCS_LIBFT:.c=.o}
CFLAGS = -Wall -Wextra -Werror  
OBJS = ${SRCS:.c=.o}
$(NAME) : $(OBJS) $(OBJS_LIBFT)
		@make -C $(LIBFT_DIR)
		$(CC) $(CFLAGS) -I $(INCLUDES) $(OBJS) $(OBJS_LIBFT) -o $(NAME) 
RM = rm -f
%.o : %.c 
		$(CC) -g $(FLAGS) -I $(INCLUDES) -c $< -o $@
all : $(NAME)

clean :	
		${RM} ${OBJS}
		
fclean : clean
		${RM} ${NAME}

	