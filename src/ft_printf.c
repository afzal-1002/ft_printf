/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:45:20 by mafzal            #+#    #+#             */
/*   Updated: 2025/02/18 17:30:03 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		num_char;
	va_list	args;

	va_start(args, format);
	i = 0;
	num_char = 0;
	while (format[i])
	{
		if (format[i] == '%')
			num_char += ft_specifiers(args, format[++i]);
		else
			num_char += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (num_char);
}
