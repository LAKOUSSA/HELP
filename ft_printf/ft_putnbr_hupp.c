/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hupp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 09:07:38 by gloukas           #+#    #+#             */
/*   Updated: 2023/02/27 18:10:18 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hupp(  int n)
{
	int	len;

	len = 0;
	if (n >= 0 && n <= 9)
		len += ft_putchar(n + 48);
	else if (n >= 10 && n < 16)
		len += ft_putchar(n + 55);
	else
	{
		len += ft_putnbr_hupp(n / 16);
		len += ft_putnbr_hupp(n % 16);
	}
	return (len);
}
