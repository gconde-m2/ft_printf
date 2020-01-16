/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 12:54:38 by gconde-m          #+#    #+#             */
/*   Updated: 2019/12/27 11:12:15 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_percent(t_struct *str)
{
	char c;

	c = str->flag == 2 ? '0' : ' ';
	if (str->w == 0 && str->flag == 0)
		write(1, "%", 1);
	else
	{
		if (str->flag == 1)
			charminus('%', str);
		else
		{
			while (str->w - 1 > 0)
			{
				write(1, &c, 1);
				str->len++;
				str->w--;
			}
			write(1, "%", 1);
			str->len++;
		}
	}
}
