/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u_flag.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:36:09 by pabeckha          #+#    #+#             */
/*   Updated: 2024/01/08 18:26:33 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_printf_u_flag(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb < 10)
		count += ft_printf_c(nb + '0');
	else
	{
		count += ft_printf_u_flag(nb / 10);
		count += ft_printf_u_flag(nb % 10);
	}
	return (count);
}
