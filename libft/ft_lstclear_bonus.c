/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 09:25:17 by gconde-m          #+#    #+#             */
/*   Updated: 2019/12/27 09:25:22 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;
	t_list	*dir;

	aux = *lst;
	while (aux)
	{
		dir = aux->next;
		del(aux->content);
		free(aux);
		aux = dir;
	}
	*lst = NULL;
}
