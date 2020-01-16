/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 08:35:58 by gconde-m          #+#    #+#             */
/*   Updated: 2019/12/27 08:10:04 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	helppre(int k, t_struct *str)
{
	char *paco;

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
	str->pre = ft_atoi(paco);
	free(paco);
}

void		ft_precision(t_struct *str)
{
	int	k;

	k = 0;
	if (*str->print == '.')
	{
		str->print++;
		str->p = 1;
	}
	if (*str->print == '*')
		ft_precisionstar(str);
	else
		helppre(k, str);
}

void		ft_precisionstar(t_struct *str)
{
	str->pre = (int)va_arg(str->ap, int);
	str->p = 1;
	if (str->pre < 0)
	{
		str->p = 0;
		str->pre = 0;
	}
	str->print++;
}
