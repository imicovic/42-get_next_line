/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicovic <imicovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 11:58:38 by imicovic          #+#    #+#             */
/*   Updated: 2025/03/09 21:14:37 by imicovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	get_line(t_list *list, char *s);
void	*ft_calloc(int num, int n);
t_list	*rf(t_list *list, int fd);
char	*ft_strchr(const char *s, char c);

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*str;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	str = ft_calloc(21000, 1);
	if (!str)
		return (NULL);
	list = rf(list, fd);
	if (!list || list->data == '\0')
	{
		list_clear(&list);
		free(str);
		return (NULL);
	}
	get_line(list, str);
	list = list_free(&list);
	if (!str)
	{
		list_clear(&list);
		free(str);
		return (NULL);
	}
	return (str);
}

void	*ft_calloc(int num, int n)
{
	void	*ptr;
	char	*s;
	int		i;

	if (num * n > 2147483647)
		return (NULL);
	ptr = malloc(num * n * sizeof(char));
	i = -1;
	s = (char *) ptr;
	while (++i < num * n)
		s[i] = '\0';
	return (ptr);
}

t_list	*rf(t_list *list, int fd)
{
	int		br;
	int		i;
	char	*buff;

	buff = (char *) ft_calloc(sizeof(char) * (BUFFER_SIZE + 1), 1);
	if (!buff)
		return (NULL);
	br = 1;
	while (!ft_strchr(buff, '\n') && br != 0)
	{
		i = -1;
		br = read(fd, buff, BUFFER_SIZE);
		if (br == -1)
		{
			list_clear(&list);
			free(buff);
			return (NULL);
		}
		while (++i < br)
			add_back(&list, new_node(buff[i]));
	}
	free(buff);
	return (list);
}

void	get_line(t_list *list, char *s)
{
	t_list	*tmp;

	tmp = list;
	if (tmp->data == '\0')
	{
		s = NULL;
		return ;
	}
	while (tmp && tmp->data != '\0')
	{
		ft_append(s, tmp->data);
		if (tmp->data == '\n')
		{
			tmp = tmp->next;
			break ;
		}
		tmp = tmp->next;
	}
}

char	*ft_strchr(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}

int main(void)
{
	int		fd = 0;
	char	*filename = "file.txt";
	char	*line = NULL;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (1);
	do {
		line = get_next_line(fd);
		if (line)
		{
			printf("%s", line);
			free(line);
		}
	} while (line);
}
