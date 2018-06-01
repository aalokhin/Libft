##all:
#	gcc -Wall -Wextra -Werror decimal.c step1.c printf.c main.c help_func.c liba.c pre.c

#uns.c hex_small.c hexic.c octic.c charik.c str.c


CC = @gcc

NAME = libftprintf.a

SRC =  locate_flags.c var_itoa.c spc_char_b.c spc_str_l.c spc_dec.c ucode.c fill_wid_pre.c printf.c help_func.c liba.c locate_spc.c spc_uns.c spc_hex_s.c spc_hex.c spc_o.c spc_char.c spc_str.c

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
