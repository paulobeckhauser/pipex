/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:52:15 by pabeckha          #+#    #+#             */
/*   Updated: 2024/01/08 18:26:38 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static int	ft_cases(va_list ap, const char charact)
{
	int	return_lenght;

	return_lenght = 0;
	if (charact == 'c')
		return_lenght += ft_printf_c(va_arg(ap, int));
	else if (charact == 's')
		return_lenght += ft_printf_s(va_arg(ap, char *));
	else if (charact == 'p')
		return_lenght += ft_printf_p(va_arg(ap, unsigned long long));
	else if (charact == 'd' || charact == 'i')
		return_lenght += ft_printf_d_i_flag(va_arg(ap, int));
	else if (charact == 'u')
		return_lenght += ft_printf_u_flag(va_arg(ap, unsigned int));
	else if (charact == 'x' || charact == 'X')
		return_lenght += ft_printf_x_flag(va_arg(ap, int), charact);
	else if (charact == '%')
		return_lenght += ft_printf_percent();
	return (return_lenght);
}

int	ft_printf(const char *format, ...)
{
	int		return_lenght;
	int		i;
	va_list	ap;

	if (!format)
		return (-1);
	i = 0;
	return_lenght = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			return_lenght += ft_cases(ap, format[i + 1]);
			i++;
		}
		else
			return_lenght += ft_printf_c(format[i]);
		i++;
	}
	va_end(ap);
	return (return_lenght);
}
