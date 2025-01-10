/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:08:06 by mafzal            #+#    #+#             */
/*   Updated: 2025/01/10 19:49:24 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		char_count;
	char	chr;
	char	*s;
	int		num;
	int		len;

	i = 0;
	char_count = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] == 'c')
		{
			chr = va_arg(args, int);
			write(1, &chr, 1);
			char_count++;
			i++;
		}
		else if (str[i] == '%' && str[i + 1] == 's')
		{
			s = va_arg(args, char *);
			if (s)
			{
				for (int j = 0; s[j] != '\0'; j++)
				{
					write(1, &s[j], 1);
					char_count++;
				}
			}
			i++;
		}
		else if (str[i] == '%' && str[i + 1] == 'd')
		{
			num = va_arg(args, int);
			char buf[12]; // To store integer as string
			len = snprintf(buf, sizeof(buf), "%d", num);
			write(1, buf, len);
			char_count += len;
			i++;
		}
		else if (str[i] == '%' && str[i + 1] == '%')
		{
			write(1, "%", 1);
			char_count++;
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			char_count++;
		}
		i++;
	}
	va_end(args);
	return (char_count);
}

int	main(void)
{
	int	output;

	output = ft_printf("String: %s -- Number: %d -- Character: %c -- \
			%% -- String: %s\n",
						"My Name is Afzal",
						123456789,
						'C',
						"Small");
	output = ft_printf("My Name is afzal");
	printf("\nTotal characters printed: %d\n", output);
	return (0);
}
