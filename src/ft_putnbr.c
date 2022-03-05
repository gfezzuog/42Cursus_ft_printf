/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 18:12:42 by dgioia            #+#    #+#             */
/*   Updated: 2022/03/03 16:52:23 by gfezzuog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_write(char c) {
	write(1, &c, 1);
}

int	ft_putnbr(int nbr)
{
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = nbr * -1;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
		ft_write(nbr +48);
	return (0);
}

int ft_countnbr(int nbr)
{
	int count;
	int	n;
	count = 0;
	n = nbr;
	if (n < 0)
	{
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
	return(count);
}