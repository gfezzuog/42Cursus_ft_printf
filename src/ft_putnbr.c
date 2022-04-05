/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 18:12:42 by dgioia            #+#    #+#             */
/*   Updated: 2022/04/05 16:55:06 by dgioia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
	{
		ft_putnbr(nbr / 10);
		ft_write('8');
	}
	else if (nbr < 0)
	{
		ft_write('-');
		ft_putnbr(-nbr);
	}
	else
	{
		if (nbr > 9)
		{
			ft_putnbr(nbr / 10);
		}
		ft_write(48 + nbr % 10);
	}
}

int	ft_countnbr(int nbr)
{
	int	count;
	int	n;

	count = 0;
	n = nbr;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			n = n / 10;
			count++;
		}
		n *= -1;
		count++;
	}
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	count++;
	ft_putnbr(nbr);
	return (count);
}
