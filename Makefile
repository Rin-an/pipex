NAME = pipex
INC = pipex.h
FLAGS = -Werror -Wextra -Wall
RM = rm -rf

SRCS = pipex.c delete.c childs.c \
	   ft_strjoin.c ft_split.c ft_strncmp.c ft_strlcpy.c

M_OBJS := $(SRCS:.c=.o)

$(NAME): $(M_OBJS)
	gcc $(M_OBJS) -o $(NAME)

%.o : %.c $(INC)
	gcc $(FLAGS) -c $< -o $@

all : $(NAME)

clean: 
	$(RM) $(M_OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re
