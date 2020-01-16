/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 09:08:55 by gconde-m          #+#    #+#             */
/*   Updated: 2019/12/30 09:14:12 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_clear(t_struct *str)
{
	str->i = 0;
	str->flag = 0;
	str->w = 0;
	str->pre = 0;
	str->p = 0;
	str->memflag = 0;
	str->len = 0;
}