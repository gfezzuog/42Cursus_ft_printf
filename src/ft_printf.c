/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:45:02 by dgioia            #+#    #+#             */
/*   Updated: 2022/04/01 18:42:11 by dgioia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

int	ft_char(char lett)
{
	write (1, &lett, 1);
	return (1);
}

int	ft_printf(const	char *string, ...)
{
	va_list	args;
	int		count;
	int		i;
	va_start(args, string);

	count = 0;
	i = 0;
	while (string[i] != '%')
		count += ft_char(string[i++]);
	while (string[i] != '%')
		i++;
	while (string[i] != '\0')
	{
		if (string[i] == 's')
			count += ft_putstr(va_arg(args, char *));
		else if (string[i] == 'c')
			count += ft_putchar(va_arg(args, char *));
		else if (string[i] == 'p')
			count += ft_print_ptr(va_arg(args, unsigned long long));
		else if (string[i] == 'i' || string[i] == 'd')
			count += ft_countnbr(va_arg(args, int));
		else if (string[i] == 'u')
			count += ft_countunbr(va_arg(args, unsigned int));
		else if (string[i] == 'x' || string[i] == 'X')
			count += ft_printhex(va_arg(args, unsigned int), string[i]);
		else if (string[i] == '%' && string[i + 1] == '%')
		{
			count += ft_putstr("%");
			i++;
		}
		else if (string[i] != '%')
		{
			write (1, &string[i], 1);
			count++;
		}	
		i++;
	}
	return (count);
}


// int	main(){
// 	ft_printf(" %d", -2147483648);
// 	int d = printf("%d",printf(" %d", -2147483648));
// }
