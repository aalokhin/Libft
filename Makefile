##all:
#	gcc -Wall -Wextra -Werror decimal.c step1.c printf.c main.c help_func.c liba.c pre.c

#uns.c hex_small.c hexic.c octic.c charik.c str.c


CC = @gcc

NAME = libftprintf.a

SRC =  var_itoa.c charbig.c str_long.c decimal.c  unicode.c step1.c printf.c help_func.c liba.c pre.c uns.c hex_small.c hexic.c octic.c charik.c str.c

OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	@gcc -c -Wall -Werror -Wextra $(SRC)
	@ar rc $(NAME) $(OBJ)
	@echo -e "\033[0;32mlib done"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY:  fclean all clean
#%.o : %.c
#	gcc  $(FLAGS) -c $< -I /bin/
