/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicovic <imicovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 11:15:21 by imicovic          #+#    #+#             */
/*   Updated: 2025/03/09 21:08:07 by imicovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_list
{
	char			data;
	struct s_list	*next;
}	t_list;

t_list	*new_node(char data);
t_list	*list_free(t_list **list);
void	add_back(t_list **list, t_list *node);
void	ft_append(char *s, char c);
void	list_clear(t_list **list);
char	*get_next_line(int fd);

#endif
