/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_direct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 08:45:24 by gconde-m          #+#    #+#             */
/*   Updated: 2019/12/27 08:48:39 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	direct2(t_struct *str, int nb, char *arr)
{
	putminuscero(str->w, str->pre, " ");
	write(1, "0x", 2);
	if (nb == 0 && str->p == 1 && str->pre == 2)
		nb = 0;
	else
		ft_putstr_n(arr, 1, str->pre);
}

void		ft_direc(t_struct *str)
{
	unsigned long int	nb;
	char				*arr;

	nb = va_arg(str->ap, unsigned long int);
	arr = ft_itoa_base(nb, 16, 'a');
	if (nb == 0 && str->p == 1 && str->pre == 0)
		str->pre = 2;
	else
		str->pre = ft_strlen(arr) + 2;
	str->w = str->w > str->pre ? str->w : str->pre;
	if (str->flag == 1)
	{
		write(1, "0x", 2);
		if (nb == 0 && str->p == 1 && str->pre == 2)
			nb = 0;
		else
			ft_putstr_n(arr, 1, str->pre);
		putminuscero(str->w, str->pre, " ");
	}
	else
		direct2(str, nb, arr);
}
