/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 08:42:22 by gconde-m          #+#    #+#             */
/*   Updated: 2019/12/27 08:42:28 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printx(t_struct *str)
{
	unsigned int	c;
	char			*p;
	int				len;
	int				lenpre;
	char			k;

	k = 'W';
	lenpre = str->pre;
	c = (unsigned int)va_arg(str->ap, unsigned int);
	p = ft_itoa_base(c, 16, 'a');
	len = ft_strlen(p);
	if (c == 0 && str->pre == 0 && str->p == 1)
		str->pre = 0;
	else
		str->pre = str->pre < len ? len : str->pre;
	if (str->w == 0 && str->flag == 0 && str->p == 0)
		ft_putstr_n((char *)p, 1, len);
	else if (str->flag == 1)
		numberminusx(c, str, k, len);
	else if (str->flag == 2)
		numbercerox(c, str, k, len);
	else if (str->p == 1 && str->w == 0)
		numberprecx(c, str, k, lenpre);
	else
		numberprecwidthx(c, str, k, len);
}
