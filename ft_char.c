/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 11:28:07 by gconde-m          #+#    #+#             */
/*   Updated: 2019/12/26 12:49:06 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char(t_struct *str)
{
	char c;

	c = (char)va_arg(str->ap, int);
	if (str->w == 0 && str->flag == 0)
		write(1, &c, 1);
	else
	{
		if (str->flag == 1)
			charminus(c, str);
		else
		{
			if (str->w >= 1)
			{
				while (str->w - 1 > 0)
				{
					write(1, " ", 1);
					str->len++;
					str->w--;
				}
				write(1, &c, 1);
			}
			str->len++;
		}
	}
}

void	charminus(char c, t_struct *str)
{
	write(1, &c, 1);
	if (str->w > 1)
	{
		while (str->w - 1 > 0)
		{
			write(1, " ", 1);
			str->len++;
			str->w--;
		}
	}
}
