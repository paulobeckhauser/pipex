/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x_flag.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:43:45 by pabeckha          #+#    #+#             */
/*   Updated: 2024/01/08 18:26:36 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_hex_len(unsigned int nb)
{
	int	count;

	count = 0;
	while (nb > 0)
	{
		nb = nb / 16;
		count++;
	}
	return (count);
}

void	ft_putchar_hex(unsigned int nb, const char format)
{
	if (nb >= 16)
	{
		ft_putchar_hex(nb / 16, format);
		ft_putchar_hex(nb % 16, format);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd((nb + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((nb - 10 + 'a'), 1);
			else if (format == 'X')
				ft_putchar_fd((nb - 10 + 'A'), 1);
		}
	}
}

int	ft_printf_x_flag(unsigned int nb, const char format)
{
	if (nb == 0)
		return (write(1, "0", 1));
	else
		ft_putchar_hex(nb, format);
	return (ft_hex_len(nb));
}
