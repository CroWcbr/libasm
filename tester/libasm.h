#ifndef LIBASM_H
# define LIBASM_H

#include <stddef.h>
#include <error.h>

size_t		ft_strlen(const char *s);
char		*ft_strcpy(char *dest, const char *src);
int			ft_strcmp(const char *s1, const char *s2);
ssize_t		ft_write(int fd, const void *buf, size_t count);
ssize_t		ft_read(int fd, void *buf, size_t count);
char		*ft_strdup(const char *s);

int 			ft_atoi_base(char *str, char *base);
// void			ft_list_push_front(t_list **head, void *data);
// unsigned int	ft_list_size(t_list *head);
// void			ft_list_sort(t_list **begin_list, int (*cmp)(void *, void *));
// void			ft_remove_if(t_list **head, void *data_ref, int (*cmp)(void *, void *), void (*free_fct)(void *));
// ft_atoi_base (like the one in the piscine)
// • ft_list_push_front (like the one in the piscine)
// • ft_list_size (like the one in the piscine)
// • ft_list_sort (like the one in the piscine)
// • ft_list_remove_if (like the one in the piscine)

typedef struct s_list
{
	void			*content;
	struct s_list	*next;	
}t_list;

size_t	ft_list_size(t_list *head);
void	ft_list_push_front(t_list **head, void *content);


#endif
