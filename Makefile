NAME		=	libasm.a

AS			=	nasm
ASFLAGS		=	-f elf64
FLAGS 		=	-Wall -Werror

SRC_DIR		= 	./src
SRC			=	ft_strlen.s \
				ft_strcpy.s \
				ft_strcmp.s \
				ft_write.s

OBJ_DIR		=	./obj
OBJ			=	$(addprefix $(OBJ_DIR)/, $(SRC:.s=.o))

RM_DIR		=	rm -rf
RM_FILE		=	rm -f

all			:	$(NAME)

OBJ			=	$(SRC:%.s=$(OBJ_DIR)/%.o)
$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.s Makefile
				@mkdir -p $(@D)
				$(AS) $(ASFLAGS) $(FLAGS) -o $@ $<

$(NAME)		:	$(OBJ)
				ar rcs $(NAME) $(OBJ)

bonus		:	$(NAME)

clean		:
				$(RM_DIR) $(OBJ_DIR)

fclean		:	clean
				$(RM_FILE) $(NAME)

re			:	fclean all

PHONY		: all bonus clean fclean re

TEST_NAME	=	test

test		:	
				gcc -Wall -Werror -Wextra main.c $(NAME) -o $(TEST_NAME)

test_start	:
				./$(TEST_NAME)

test_clean	:	
				$(RM_FILE) $(TEST_NAME)
				
