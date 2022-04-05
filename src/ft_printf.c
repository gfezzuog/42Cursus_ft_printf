/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfezzuog <gfezzuog@student.42rome.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:45:02 by dgioia            #+#    #+#             */
/*   Updated: 2022/04/05 16:23:02 by gfezzuog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

int	ft_char(char lett)
{
	write (1, &lett, 1);
	return (1);
}

int	ft_checkprintf(const char *string, int i, va_list args)
{
	int	count;
	
	count = 0;
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
	else if (string[i] == '%')
		count += ft_putstr("%");
	return(count);
}

int	ft_printf(const	char *string, ...)
{
	va_list	args;
	int		count;
	int			i;
	
	va_start (args, string);
	i = 0;
	count = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			i++;
			count += ft_checkprintf(string, i, args);
		}
		else
			count += ft_char(string[i]);
		i++;
	}
	return (count);
}


// int	main(){
// 	int ret = 0;
// 	int ret2 = 0;
// 	ret = ft_printf("D: %s\n", "ciao");
// 	ret2 = printf("D: %s\n", "ciao");
// 	printf("M: %d, V: %d",ret, ret2);
// }
