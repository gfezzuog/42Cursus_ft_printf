/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:29:51 by gfezzuog          #+#    #+#             */
/*   Updated: 2022/03/14 14:29:51 by gfezzuog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int ft_counthex(unsigned int nbr)
{
    int count;

    count = 0;
    while (nbr != 0)
    {
        count++;
        nbr = nbr / 16;
    }
    return (count);
}

void    ft_puthex(unsigned int nbr, const char str)
{
    if (nbr >= 16)
    {
        ft_puthex(nbr / 16, str);
        ft_puthex(nbr % 16, str);
    }
    else
    {
        if(nbr <= 9)
            ft_write((nbr + '0'));
        else
        {
            if(str == 'x')
                ft_write((nbr - 10 + 'a'));
            if(str == 'X')
                ft_write((nbr - 10 + 'A'));
        }
    }
}

int	ft_printhex(unsigned int nbr, const char str)
{
	if (nbr == 0)
		return (write(1, "0", 1));
	else
		ft_puthex(nbr, str);
	return (ft_counthex(nbr));
}
