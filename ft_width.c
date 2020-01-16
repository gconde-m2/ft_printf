/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 07:45:29 by gconde-m          #+#    #+#             */
/*   Updated: 2019/12/27 08:22:02 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	width2(t_struct *str)
{
	char	*paco;
	int		k;
	int		p;

	k = 0;
	p = 0;
	while (str->print[k] > '0' && str->print[k] < '9')
		k++;
	if (!(paco = malloc(sizeof(char) * k + 1)))
		return ;
	paco[k] = '\0';
	k = 0;
	while (*str->print >= '0' && *str->print <= '9')
	{
		paco[k] = *str->print;
		k++;
		str->print++;
	}
	str->w = ft_atoi(paco);
	free(paco);
}

void		ft_width(t_struct *str)
{
	if (*str->print == '*')
	{
		str->w = va_arg(str->ap, int);
		str->print++;
		if (str->w < 0)
		{
			str->flag = 1;
			str->w *= -1;
		}
	}
	else
		width2(str);
}
