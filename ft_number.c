/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 11:54:23 by gconde-m          #+#    #+#             */
/*   Updated: 2019/12/30 09:23:46 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_number(t_struct *str)
{
	int			c;
	const char	*k;
	int			len;
	int			lenpre;

	c = (int)va_arg(str->ap, int);
	k = ft_itoa(c);
	len = ft_strlen(k);
	lenpre = str->pre;
	if (c < 0)
		str->pre = str->pre > len - 1 ? str->pre + 1 : len;
	if (c == 0 && str->pre == 0 && str->p == 1)
		len = 0;
	else
		str->pre = str->pre < len ? len : str->pre;
	if (str->w == 0 && str->flag == 0 && str->p == 0)
		ft_putstr_n((char *)k, 1, len);
	else if (str->flag == 1)
		numberminus(c, str, k, len);
	else if (str->flag == 2)
		numbercero(c, str, k, len);
	else if (str->p == 1 && str->w == 0)
		numberprec(c, str, k, lenpre);
	else
		numberprecwidth(c, str, k, len);
}

void	numberminus(long int c, t_struct *str, const char *k, int len)
{
	long int hotia;
	long int n;

	n = c < 0 ? c * -1 : c * 1;
	k = ft_itoa(n);
	hotia = ft_strlen(k);
	str->pre = c < 0 && str->pre == len ? str->pre - 1 : str->pre;
	if (c < 0)
		write(1, "-", 1);
	if (str->pre > hotia && str->p == 1)
		putminuscero(str->pre, len, "0");
	ft_putstr_n((char *)k, 1, str->pre);
	putminuscero(str->w = c < 0 ? str->w - 1 : str->w,
		str->pre = c < 0 && str->pre > len ? str->pre - 1 : str->pre, " ");
}

void	numbercero(long int c, t_struct *str, const char *k, int len)
{
	long int n;

	n = c < 0 ? c * -1 : c * 1;
	k = ft_itoa(n);
	if (str->p == 1)
	{
		putminuscero(str->w, str->pre, " ");
		if (c < 0)
			write(1, "-", 1);
	}
	else
	{
		if (c < 0)
			write(1, "-", 1);
	}
	putminuscero(str->pre = str->p != 1 ? str->w : str->pre, len, "0");
	ft_putstr_n((char *)k, 1, str->pre = str->w < len ? len : str->pre);
}

void	numberprec(long int c, t_struct *str, const char *k, int lenpre)
{
	long int	n;
	int			omg;

	n = c < 0 ? c * -1 : c * 1;
	k = ft_itoa(n);
	if (c < 0)
		write(1, "-", 1);
	omg = ft_strlen(k);
	if (lenpre >= omg)
	{
		putminuscero(lenpre, omg, "0");
		ft_putstr_n((char *)k, 1, str->pre);
	}
	else
		ft_putstr_n((char *)k, 1, lenpre + str->pre);
}

void	numberprecwidth(long int c, t_struct *str, const char *k, int len)
{
	int				hotia;
	long int		n;

	n = c < 0 ? c * -1 : c * 1;
	k = ft_itoa(n);
	hotia = str->pre == 0 && c == 0 ? 0 : ft_strlen(k);
	if (str->flag != 2)
		putminuscero(str->w, str->pre, " ");
	if (c < 0)
		write(1, "-", 1);
	if (str->pre > hotia && str->p == 1)
		putminuscero(str->pre, len, "0");
	ft_putstr_n((char *)k, 1, hotia);
}
