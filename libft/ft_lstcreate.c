/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcreate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 20:03:41 by qsebasti          #+#    #+#             */
/*   Updated: 2017/11/23 20:05:09 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstcreate(void const *content, size_t content_size)
{
	t_list	*tmp;

	if (!(tmp = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	tmp->content_size = 0;
	if (!content)
		tmp->content = NULL;
	else
	{
		if (!(tmp->content = ft_strdup((char *)content)))
			return (NULL);
		tmp->content_size = content_size;
	}
	tmp->next = NULL;
	return (tmp);
}
