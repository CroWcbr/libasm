#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#include "libasm.h"

#define COUNT	10000
#define RESET	"\x1B[0m"
#define RED		"\x1B[31m"
#define GREEN	"\x1B[32m"

void	test_result(int result)
{
	if (result)
		printf(GREEN "OK" RESET "\n");
	else
		printf(RED "FAILED" RESET "\n");
}

void	clear_lst(t_list **head)
{
	if (!head || !(*head))
		return;

	t_list *tmp;
	while (*head)
	{
		tmp = (*head)->next;
		free((*head)->content);
		free(*head);
		*head = tmp;
	}
}

t_list	*ft_create_elem_C(void *content)
{
	t_list	*tmp;

	if ((tmp = (t_list *)malloc(sizeof(t_list))) == ((void *)0))
		return ((void *)0);
	tmp->content = content;
	tmp->next = ((void *)0);
	return (tmp);
}

void	ft_list_push_front_C(t_list **head, void *content)
{
	t_list	*list;

	if (*head)
	{
		list = ft_create_elem_C(content);
		list->next = *head;
		*head = list;
	}
	else
		*head = ft_create_elem_C(content);
}

int		check_list(t_list *test, t_list *test_C)
{
	while (test && test_C)
	{
		if (strcmp(test->content, test_C->content))
			return 1;
		test = test->next;
		test_C = test_C->next;
	}
	if (test || test_C)
		return 1;
	return 0;
}

void	test_list_size()
{
	int flag = 1;
	for (int i = 0; i < COUNT; ++i)
	{
		int size = rand() % COUNT;
		t_list	*test = NULL;
		t_list	*tmp;
		for (int j = 0; j < size; ++j)
		{
			t_list	*new_list = (t_list*)malloc(sizeof(t_list));
			if (!new_list)
			{
				perror("Wrong malloc in test_lst_size");
				flag = 0;
				break;
			}
			new_list->content = NULL;
			new_list->next = NULL;
			if (!test)
			{
				test = new_list;
				tmp = test;
			}
			else
			{
				tmp->next = new_list;
				tmp = tmp->next;
			}
		}
		if (!flag)
			break;
		if (ft_list_size(test) != size)
		{
			clear_lst(&test);
			flag = 0;
			break ;
		}
		clear_lst(&test);
	}
	test_result(flag);
}

void	test_list_push_front()
{
	int flag = 1;
	t_list	*test = NULL;
	t_list	*test_C = NULL;
	for (int i = 0; i < COUNT; ++i)
	{
		int size = rand() % 10;
		char *str = malloc(size + 1);
		char *str_C = malloc(size + 1);
		if (!str || !str_C)
		{
			perror("Wrong malloc in test_list_push_front");
			flag = 0;
			break;
		}
		for (int j = 0; j < size; ++j)
		{
			str[j] = rand() % 127 + 1;
			str_C[j] = str[j];
		}
		str[size] = '\0';
		str_C[size] = '\0';

		ft_list_push_front(&test, str);
		ft_list_push_front_C(&test_C, str_C);
		if (!test || !test_C)
		{
			perror("Wrong malloc in test_list_push_front");
			flag = 0;
			break;
		}
		if (check_list(test, test_C) || ft_list_size(test) != ft_list_size(test_C))
		{
			clear_lst(&test);
			clear_lst(&test_C);
			flag = 0;
			break ;
		}
	}
	clear_lst(&test);
	clear_lst(&test_C);
	test_result(flag);
}

int main()
{
	srand(time(NULL));
	printf("LiST_SIZE\t");
	test_list_size();

	printf("LiST_PUSH_FRONT\t");
	test_list_push_front();

	return 0;
}
