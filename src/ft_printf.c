/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:45:02 by dgioia            #+#    #+#             */
/*   Updated: 2022/03/02 18:29:33 by dgioia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

int	ft_printf(const	char *string, ...)
{
	va_list args; //crea una variabile di lista
	int	count;
	int	i;
	
	va_start(args, string); //passiamo il nome della lista e l'ultimo argomento prima di un num indefinito di var

	count = 0;
	i = 0;
	//while(string[i] != '%')
	//	i++;
	
	while(string[i] != '\0')
	{
		if (string[i] == 'c' || string[i] == 's')
			count += ft_putstr(va_arg(args, char *));
		//else if (string[i] == 's')
		//else if (string[i] == 'p')
		else if (string[i] == 'd' || string[i] == 'i')
			count += ft_putnbr(va_arg(args, int));
			
		//else if (string[i] == 'i')
		//else if (string[i] == 'u')
		//else if (string[i] == 'x')
		//else if (string[i] == 'X')
		//else if (string[i] == '%')
		i++;
	}
	
	return (0);
}

int main(){
	//printf("%s", "ciao");
	ft_printf("%i", 1.1);
}
