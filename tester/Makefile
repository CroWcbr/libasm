.DEFAULT_GOAL := error

NAME		=	test
LIB			=	../libasm.a

CC			=	gcc
FLAGS		=	#-Wall -Wextra -Werror

TEST_FILE	=	main.c
TEST_FILE_B	=	main_bonus.c

RM_DIR		=	rm -rf
RM_FILE		=	rm -f

error:
	@echo "Please specify a target : make *****"

test		:	
				$(CC) $(FLAGS) $(TEST_FILE) $(LIB) -o $(NAME)

test_bonus	:
				$(CC) $(FLAGS) $(TEST_FILE_B) $(LIB) -o $(NAME)

test_start	:
				./$(NAME)

test_clean	:	
				$(RM_FILE) $(NAME)
				
