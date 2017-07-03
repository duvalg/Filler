NAME = gduval.filler

HEADER_PATH = ./libft/
HEADER_NAME = libft.a
HEADER = $(addprefix $(HEADER_PATH), $(HEADER_NAME))

SRC_PATH = ./
SRC_NAME = filler.c \
			init_struct.c \
			parse.c \
			get_piece.c \
			init_coordinates.c \
			coordinates_gestion.c \
			player_top.c \
			player_bottom.c \
			is_aggressive.c \
			go_top.c \
			go_bottom.c \
			point_is_viable.c \
			print_coord.c \
			ft_exit.c

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

LIBFT_SRC_NAME = ft_memset.c \
	  ft_bzero.c \
	  ft_memcpy.c \
	  ft_memccpy.c \
	  ft_memmove.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_strlen.c \
	  ft_strdup.c \
	  ft_strcpy.c \
	  ft_strncpy.c \
	  ft_strcat.c \
	  ft_strncat.c \
	  ft_strlcat.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strstr.c \
	  ft_strnstr.c \
	  ft_strcmp.c \
	  ft_strncmp.c \
	  ft_atoi.c \
	  ft_isalpha.c \
	  ft_isdigit.c \
	  ft_isalnum.c \
	  ft_isascii.c \
	  ft_isprint.c \
	  ft_toupper.c \
	  ft_tolower.c \
	  ft_memalloc.c \
	  ft_memdel.c \
	  ft_strnew.c \
	  ft_strdel.c \
	  ft_strclr.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_putnbr.c \
	  ft_strequ.c \
	  ft_strnequ.c \
	  ft_strsub.c \
	  ft_strjoin.c \
	  ft_strjoin_free.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putnbr_fd.c \
	  ft_putendl.c \
	  ft_putendl_fd.c \
	  ft_strtrim.c \
	  ft_strsplit.c \
	  ft_itoa.c \
	  ft_intlen.c \
	  ft_lstnew.c \
	  ft_lstdelone.c \
	  ft_lstdel.c \
	  ft_lstadd.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_isspace.c \
	  ft_isgraph.c \
	  ft_isupper.c \
	  ft_islower.c \
	  free_pointers.c \
	  get_next_line.c

LIBFT_SRC = $(addprefix $(HEADER_PATH), $(LIBFT_SRC_NAME))

LIBFT_OBJ = $(LIBFT_SRC:.c=.o)

OBJ = $(SRC:.c=.o)

FLAG = -Werror -Wextra -Wall

all : $(NAME)

$(NAME) :
	@make -C libft
	@gcc -c $(SRC_NAME)
	@gcc $(OBJ) $(LIBFT_OBJ) -o $(NAME)

clean :
	@make clean -C libft
	@rm -f $(OBJ)

build_project :
	@make fclean
	@make
	@make clean

fclean :
	@make fclean -C libft
	@rm -f $(OBJ) $(NAME)

re : fclean $(NAME)

.PHONY : all build_project clean fclean re
