NAME		= cub3d

SRC 		= main.c parsing1.c put_text_struct.c parsing2.c parsing_map_elements.c check_config_elements.c get_next_line.c get_next_line_utils.c

CC 			= cc 

OBJ_DIR		= obj

OBJ 		= $(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))

RM			= rm -rf

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	clang -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

all	: $(NAME)

$(NAME): $(OBJ)
				@make -C mlx_linux
				$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)


clean:
				make -C mlx_linux clean
				$(RM) $(OBJ)
				$(RM) $(OBJ_DIR)

fclean:			clean
					make -C mlx_linux clean
					$(RM) $(NAME)
					$(RM) $(OBJ_DIR)

re:				fclean all

.PHONY:			all clean fclean re 
