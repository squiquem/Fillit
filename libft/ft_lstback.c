/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstback.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 17:58:37 by qsebasti          #+#    #+#             */
/*   Updated: 2017/11/23 20:07:08 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstback(t_list **lst, void *data, unsigned int nb)
{
	if (!*lst)
		*lst = ft_lstcreate(data, nb);
	else if ((*lst)->next == NULL)
		(*lst)->next = ft_lstcreate(data, nb);
	else
		ft_lstback(&((*lst)->next), data, nb);
}
