/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:37:05 by pabeckha          #+#    #+#             */
/*   Updated: 2023/11/23 23:08:34 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size_number(int i);
static void	save_number(int i, int n, char *number, int value);
static char	*excpetion_number(int n);
static char	*normal_number(int n);

char	*ft_itoa(int n)
{
	char	*number;

	number = NULL;
	if (n == -2147483648)
		number = excpetion_number(n);
	else
		number = normal_number(n);
	if (!number)
		return (NULL);
	return (number);
}

static int	size_number(int i)
{
	int	count;

	count = 0;
	if (i < 0)
	{
		i = -i;
		count++;
	}
	while (i / 10 > 0)
	{
		i = i / 10;
		count++;
	}
	count++;
	return (count);
}

static void	save_number(int i, int n, char *number, int value)
{
	while (i > value)
	{
		number[i - 1] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
}

static char	*excpetion_number(int n)
{
	int		i;
	char	*number;

	number = (char *)malloc((size_number(n / 10) + 1 + 1) * sizeof(char));
	if (!number)
		return (NULL);
	i = size_number(n / 10) + 1;
	n = n / 10;
	number[i - 1] = '8';
	i--;
	number[0] = '-';
	n = -n;
	save_number(i, n, number, 1);
	number[i + 1] = '\0';
	return (number);
}

static char	*normal_number(int n)
{
	int		i;
	char	*number;

	number = (char *)malloc((size_number(n) + 1) * sizeof(char));
	if (!number)
		return (NULL);
	i = size_number(n);
	if (n < 0)
	{
		number[0] = '-';
		n = -n;
		save_number(i, n, number, 1);
	}
	else
		save_number(i, n, number, 0);
	number[i] = '\0';
	return (number);
}
