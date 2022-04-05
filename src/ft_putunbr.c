/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 18:12:42 by dgioia            #+#    #+#             */
/*   Updated: 2022/04/05 16:55:50 by dgioia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putunbr(unsigned int nbr)
{
	if (nbr > 9)
	{
		ft_putunbr(nbr / 10);
		ft_putunbr(nbr % 10);
	}
	if (nbr <= 9)
		ft_write(48 + nbr);
}

int	ft_countunbr(unsigned int nbr)
{
	int				count;
	unsigned int	n;

	count = 0;
	n = nbr;
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	count++;
	ft_putunbr(nbr);
	return (count);
}
