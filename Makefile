NAME = push_swap
SRCS = ${wildcard ./srcs/*.c}
INCLUDES = ./includes
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJS = ${SRCS:.c=.o}
$(NAME) : $(OBJS) 
		$(CC) $(CFLAGS) -I $(INCLUDES) $(OBJS) -o $(NAME) 
RM = rm -f
%.o : %.c 
		$(CC) -g $(FLAGS) -I $(INCLUDES) -c $< -o $@
all : $(NAME)

clean :	
		${RM} ${OBJS}
		
fclean : clean
		${RM} ${NAME}

	