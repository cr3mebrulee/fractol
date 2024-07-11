NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3
PFLAGS = -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o
RM = rm -f
AR = ar rcs
DIR_OBJ = obj
DIR_SRC = src
SOURCES = make_fractal.c \
          julia.c \
          key_hooks.c \
		  key_hooks_2.c \
		  fractal_initialisation.c \
		  main.c \
		  mandelbrot.c \
		  mouse_hook.c \
		  utilit_functions.c \
		  generate_double.c \
		  check_arguments.c
LIBFT = libft
MINLIBX = minilibx-linux
HEADER = include
SRCS = $(addprefix $(DIR_SRC)/,$(SOURCES))
OBJS = $(addprefix $(DIR_OBJ)/,$(SOURCES:.c=.o))

make: all

all: $(NAME)
$(NAME): $(OBJS)
	@echo "\033[33m----Creating libft.a ${@}----"
	make -C $(LIBFT)
	cp $(LIBFT)/libft.a .
	@echo "\033[33m----Creating libmlx_Linux.a ${@}----"
	make -C $(MINLIBX)
	cp $(MINLIBX)/libmlx_Linux.a .
	@echo "\033[33m----Creating $(NAME) \033[33m----"
	$(CC) $(OBJS) libft.a libmlx_Linux.a $(PFLAGS) $(NAME)
	@echo "\033[33m----$(NAME) created ----"

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c
	# @echo "Compiling $< into $@.\n"
	mkdir -p $(DIR_OBJ)
	$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@
	# @echo "\033[33m----Compiled.\033[33m----"

clean:
	clear
	@echo "\033[33m----Cleaning object files \033[33m----"
	$(RM) -r $(DIR_OBJ)/*.o
	@echo "\033[33m----$(NAME) object files cleaned \033[33m----"

fclean: clean
	@echo "\033[33m----Cleaning $(NAME) and libft \033[33m----"
	$(RM) $(NAME) libft.a libmlx_Linux.a
	make -C $(LIBFT) fclean
	make -C $(MINLIBX) clean
	clear
	@echo "\033[33m----Project $(NAME) cleaned \033[33m----"

re: fclean all make

.PHONY: all clean fclean re
.SILENT: clean fclean re $(NAME) $(OBJS) $(DIR_OBJ)/%.o $(DIR_SRC)/%.c
