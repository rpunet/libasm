NAME	= 	libasm.a
NA		=	 nasm
FLAGS	= 	-Wall -Wextra -Werror
NFLAGS	= 	-f elf64
DEBUG	=	-g -F dwarf
SRCS	=	ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
OBJS	=	$(SRCS:.s=.o)


# Colors #
GREEN	=	\033[1;32m
RED		=	\033[1;31m
BLUE	=	\033[0;34m
END		=	\033[0m

%.o: 		%.s
			$(NA) $(DEBUG) $(NFLAGS) $<

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $^
			@echo "$(GREEN) ---- libasm.a built! ---- $(END)"

clean:
			rm -rf $(OBJS)
			@echo "$(RED) ---- objects removed! ---- $(END)"

fclean:		clean
			rm -rf $(NAME)
			rm -rf exe
			@echo "$(RED) ---- all cleared! ---- $(END)"

re:			fclean all

exe:		$(NAME)
			gcc $(FLAGS) main.c $(NAME) -o exe
#flag -no-pie (position independent executable)
			@echo "$(BLUE) ---- executable ready! ---- $(END)"

exedebug:		$(NAME)
			gcc $(FLAGS) $(DEBUG) -fsanitize=address
			main.c $(NAME) -o exe
			@echo "$(BLUE) ---- debuggeable exe ready! ---- $(END)"

.PHONY:		all clean fclean re exe exedebug
