/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicovic <imicovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 11:53:23 by imicovic          #+#    #+#             */
/*   Updated: 2024/06/23 16:39:57 by imicovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*new_node(char data)
{
	t_list	*node;

	node = (t_list *) malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

void	list_clear(t_list **list)
{
	t_list	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free(*list);
		*list = tmp;
	}
}

void	add_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_list	*list_free(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp)
	{
		if ((*list)->data == '\n')
		{
			*list = (*list)->next;
			free(tmp);
			break ;
		}
		*list = (*list)->next;
		free(tmp);
		tmp = *list;
	}
	return (*list);
}

void	ft_append(char *s, char c)
{
	int	len;

	len = 0;
	if (s[0] != '\0')
		while (s[len] != '\0')
			len++;
	s[len] = c;
}
