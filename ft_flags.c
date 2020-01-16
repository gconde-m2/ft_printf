/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 08:54:32 by gconde-m          #+#    #+#             */
/*   Updated: 2019/12/27 09:00:07 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flags(t_struct *str)
{
	while (*str->print == '0' || *str->print == '-')
	{
		if (*str->print == '-')
		{
			str->flag = 1;
			str->print++;
		}
		if (*str->print == '0')
		{
			str->flag = str->flag == 1 ? 1 : 2;
			str->print++;
		}
	}
}
