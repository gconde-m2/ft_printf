/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numberu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 12:52:06 by gconde-m          #+#    #+#             */
/*   Updated: 2019/12/30 08:45:11 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_numberu(t_struct *str)
{
	unsigned int	c;
	const char		*k;
	int				len;
	int				lenpre;

	c = va_arg(str->ap, unsigned int);
	k = ft_itoa(c);
	len = ft_strlen(k);
	lenpre = str->pre;
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
