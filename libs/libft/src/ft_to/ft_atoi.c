/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:52:15 by pabeckha          #+#    #+#             */
/*   Updated: 2023/12/01 14:14:21 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	nb_definition(const char *str, int i, int nb);

int	ft_atoi(const char *str)
{
	int	nb;
	int	i;
	int	parity;

	nb = 0;
	i = 0;
	parity = 1;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1] >= '0'
		&& str[i + 1] <= '9')
	{
		if (str[i] == '-')
			parity = -1;
		i++;
		nb = nb_definition(str, i, nb);
		return (nb * parity);
	}
	else if (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb_definition(str, i, nb);
		return (nb);
	}
	else
		return (0);
}

static int	nb_definition(const char *str, int i, int nb)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb);
}
