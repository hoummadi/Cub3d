/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 11:50:11 by hhoummad          #+#    #+#             */
/*   Updated: 2019/11/05 17:21:18 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_dprt(char *s1, char *set)
{
	int i;
	int j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			else
				j++;
		}
		if (s1[i] != set[j])
			break ;
		i++;
	}
	return (i);
}

static int		ft_fint(char *s1, char *set)
{
	int i;
	int j;
	int k;

	i = 0;
	while (s1[i])
		i++;
	k = i;
	while (i >= 0)
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			else
				j++;
		}
		if (s1[i] != set[j])
			break ;
		i--;
	}
	i = k - i - 1;
	return (i);
}

static char		*ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	int		i;
	int		k;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	i = ft_dprt((char *)s1, (char *)set);
	k = (ft_strlen(s1) - i) - ft_fint((char *)s1, (char *)set);
	if (k < 0)
		k = 0;
	if (!(s = malloc(sizeof(char) * (k + 1))))
		return (NULL);
	ft_strncpy(s, (char *)s1 + i, k);
	return (s);
}
