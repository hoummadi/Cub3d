/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:07:09 by hhoummad          #+#    #+#             */
/*   Updated: 2019/11/20 18:18:20 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_nchr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\n')
	{
		if (s[i] == '\0')
			return (-1);
		i++;
	}
	return (i);
}

static void		my_free(char **s)
{
	if (*s)
	{
		free(*s);
		*s = NULL;
	}
}

static char		*ft_substr_hh(char *s, int start, int index)
{
	char	*p;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < (size_t)start)
		return (ft_strdup2(""));
	if (index == 1)
		len = ft_strlen(s + start);
	else if (index == 0 && (len = start) >= 0)
		start = 0;
	if (!(p = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s[i + start] && len--)
	{
		p[i] = s[i + start];
		i++;
	}
	p[i] = '\0';
	return (p);
}

static int		trait(char **line, int j, char *p, char **save)
{
	char	*tmp;

	tmp = *line;
	my_free(save);
	if ((j = ft_nchr(p)) > -1)
	{
		if (!(*line = ft_strjoin2(*line, ft_substr_hh(p, j, 0))))
			return (-1);
		if (!(*save = ft_substr_hh(p, j + 1, 1)))
			return (-1);
		my_free(&p);
		return (1);
	}
	else
	{
		*save = NULL;
		if ((*line = ft_strjoin2(*line, p)))
			return (0);
		free(tmp);
		free(p);
		return (-1);
	}
}

int				get_next_line(int fd, char **line)
{
	int			j;
	char		*p;
	static char	*save[1024];

	j = 0;
	if (line && fd >= 0 && BUFFER_SIZE > 0 && (*line = ft_strdup2("")))
		while (1 && (p = ft_strdup2(save[fd])))
		{
			if (save[fd] == NULL)
			{
				my_free(&p);
				if (!(p = malloc((BUFFER_SIZE + 1) * sizeof(char))))
					return (-1);
				if (!(j = read(fd, p, BUFFER_SIZE)) || j == -1)
				{
					my_free(&p);
					return (j);
				}
				p[j] = '\0';
			}
			if ((j = trait(line, j, p, &save[fd])) && (j == 1 || j == -1))
				return (j);
		}
	return (-1);
}
