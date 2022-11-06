/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 00:44:24 by hhoummad          #+#    #+#             */
/*   Updated: 2019/10/28 15:49:43 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *j;

	j = (t_list*)malloc(sizeof(t_list));
	if (!j)
		return (NULL);
	j->content = content;
	j->next = NULL;
	return (j);
}
