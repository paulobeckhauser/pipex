/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 11:12:22 by pabeckha          #+#    #+#             */
/*   Updated: 2024/01/08 19:25:32 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <unistd.h>

int	ft_printf_c(char c);
int	ft_printf_s(char *string);
int	ft_printf_p(unsigned long long ptr);
int	ft_printf_d_i_flag(int nb);
int	ft_printf_u_flag(unsigned int nb);
int	ft_printf_x_flag(unsigned int nb, const char format);
int	ft_printf_percent(void);

int	ft_printf(const char *format, ...);

#endif