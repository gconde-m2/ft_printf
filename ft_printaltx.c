/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printaltx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 08:37:27 by gconde-m          #+#    #+#             */
/*   Updated: 2019/12/27 08:37:36 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printaltx(t_struct *str)
{
	unsigned int	c;
	char			*p;
	int				len;
	int				lenpre;
	char			k;

	lenpre = str->pre;
	k = '7';
	c = va_arg(str->ap, unsigned int);
	p = ft_itoa_base(c, 16, 'A');
	len = ft_strlen(p);
	if (c == 0 && str->pre == 0 && str->p == 1)
		str->pre = 0;
	else
		str->pre = str->pre < len ? len : str->pre;
	if (str->w == 0 && str->flag == 0 && str->p == 0)
		ft_putnbrmemory(c, k, str);
	else if (str->flag == 1)
		numberminusx(c, str, k, len);
	else if (str->flag == 2)
		numbercerox(c, str, k, len);
	else if (str->p == 1 && str->w == 0)
		numberprecx(c, str, k, lenpre);
	else
		numberprecwidthx(c, str, k, len);
}

void	numberminusx(unsigned int c, t_struct *str, char k, int len)
{
	int		hotia;
	char	*p;

	p = ft_itoa_base(c, 16, 'A');
	hotia = ft_strlen(p);
	str->pre = c < 0 && str->pre == len ? str->pre - 1 : str->pre;
	if (str->pre > hotia && str->p == 1)
		putminuscero(str->pre, hotia, "0");
	if (!(c == 0 && str->pre == 0 && str->p == 1))
		ft_putnbrmemory(c, k, str);
	if (str->flag != 2)
		putminuscero(str->w = c < 0 ? str->w - 1 : str->w, str->pre, " ");
}

void	numbercerox(unsigned int c, t_struct *str, char k, int len)
{
	char *p;

	p = ft_itoa_base(c, 16, 'A');
	str->pre = c < 0 && str->pre == len ? str->pre - 1 : str->pre;
	if (str->p == 1)
		putminuscero(str->w, str->pre = c < 0 ? str->pre + 1 : str->pre, " ");
	putminuscero(str->pre = str->p == 1 ? str->pre : str->w, len, "0");
	if (!(c == 0 && str->pre == 0 && str->p == 1))
		ft_putnbrmemory(c, k, str);
}

void	numberprecx(unsigned int c, t_struct *str, char k, int lenpre)
{
	int		omg;
	char	*p;

	p = ft_itoa_base(c, 16, 'A');
	omg = ft_strlen(p);
	if (lenpre >= omg)
	{
		putminuscero(lenpre, omg, "0");
		if (!(c == 0 && str->pre == 0 && str->p == 1))
			ft_putnbrmemory(c, k, str);
	}
	else
	{
		if (!(c == 0 && str->pre == 0 && str->p == 1))
			ft_putnbrmemory(c, k, str);
	}
}

void	numberprecwidthx(unsigned int c, t_struct *str, char k, int len)
{
	char	*p;
	int		hotia;

	p = ft_itoa_base(c, 16, 'A');
	hotia = str->pre == 0 && c == 0 ? 0 : ft_strlen(p);
	str->pre = c < 0 && str->pre == len ? str->pre - 1 : str->pre;
	if (str->flag != 2)
		putminuscero(str->w, str->pre, " ");
	if (str->pre > hotia && str->p == 1)
		putminuscero(str->pre, hotia, "0");
	if (str->pre == 0 && c == 0 && str->p != 1)
		write(1, "0", 1);
	else
	{
		if (!(c == 0 && str->pre == 0 && str->p == 1))
			ft_putnbrmemory(c, k, str);
	}
}
