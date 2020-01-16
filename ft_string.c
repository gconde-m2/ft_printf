/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 10:47:29 by gconde-m          #+#    #+#             */
/*   Updated: 2019/12/26 12:48:22 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_string(t_struct *str)
{
	int			k;
	const char	*c;
	int			len;

	k = 0;
	c = (const char *)va_arg(str->ap, const char *);
	len = c == NULL ? 6 : (int)ft_strlen(c);
	str->pre = str->p == 1 && str->pre < len ? str->pre : len;
	stringwidth1(str, c);
}

void	stringwidth1(t_struct *str, const char *c)
{
	int k;

	k = 0;
	if (str->flag == 1)
	{
		ft_putstr_n(c == NULL ? "(null)" : (char*)c, 1, str->pre);
		while (str->w - str->pre > 0)
		{
			write(1, " ", 1);
			str->len++;
			str->w--;
		}
	}
	else
		stringwidth2(str, c);
}

void	stringwidth2(t_struct *str, const char *c)
{
	int k;

	k = 0;
	while (str->w - str->pre > 0)
	{
		write(1, " ", 1);
		str->len++;
		str->w--;
	}
	ft_putstr_n(c == NULL ? "(null)" : (char*)c, 1, str->pre);
}
