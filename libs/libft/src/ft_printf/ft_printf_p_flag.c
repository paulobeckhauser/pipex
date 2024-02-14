/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p_flag.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:57:05 by pabeckha          #+#    #+#             */
/*   Updated: 2024/01/08 18:26:25 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static int	ft_len_ptr(unsigned long int i)
{
	int	count;

	count = 0;
	while (i != 0)
	{
		count++;
		i = i / 16;
	}
	return (count);
}

static void	ft_printf_hex(unsigned long long i)
{
	if (i == 0)
	{
		ft_putchar_fd('0', 1);
		return ;
	}
	if (i >= 16)
	{
		ft_printf_hex(i / 16);
		ft_printf_hex(i % 16);
	}
	else
	{
		if (i <= 9)
			ft_putchar_fd((i + '0'), 1);
		else
			ft_putchar_fd((i - 10 + 'a'), 1);
	}
}

int	ft_printf_p(unsigned long long ptr)
{
	int	count;

	count = 0;
	count += write(1, "0x", 2);
	if (ptr == 0)
	{
		ft_putchar_fd('0', 1);
		return (3);
	}
	else
	{
		ft_printf_hex(ptr);
		count += ft_len_ptr(ptr);
	}
	return (count);
}
