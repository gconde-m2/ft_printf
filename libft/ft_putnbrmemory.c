/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrmemory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 09:12:01 by gconde-m          #+#    #+#             */
/*   Updated: 2019/12/30 09:08:01 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_putchare(char c, t_struct *str)
{
	write(1, &c, 1);
	str->len++;
}

void		ft_putnbrmemory(unsigned int nb, char c, t_struct *str)
{
	if (nb > 15)
	{
		ft_putnbrmemory(nb / 16, c, str);
	}
	if ((nb % 16) < 10)
		ft_putchare((nb % 16) + '0', str);
	if ((nb % 16) > 9)
		ft_putchare((nb % 16) + c, str);
}
