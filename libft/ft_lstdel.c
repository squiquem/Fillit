/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:01:41 by qsebasti          #+#    #+#             */
/*   Updated: 2017/11/14 22:05:42 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;

	if (*alst && del)
	{
		while ((*alst)->next)
		{
			tmp = *alst;
			ft_lstdelone(&tmp, (*del));
			*alst = (*alst)->next;
		}
		ft_lstdelone(alst, (*del));
	}
}
