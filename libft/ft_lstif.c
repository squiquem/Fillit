/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 22:09:00 by qsebasti          #+#    #+#             */
/*   Updated: 2017/11/25 15:27:29 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstif(t_list *lst, size_t nb)
{
	while (lst)
	{
		if (lst->content_size == nb)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
