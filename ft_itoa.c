/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angemart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:44:27 by angemart          #+#    #+#             */
/*   Updated: 2024/04/24 12:44:32 by angemart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	get_size(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len += 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		num;
	int		len;

	num = n; // inicializao variable num aquí -también está en línea 49- porque me daba un warning. Pero entonces supero las 25 línas. Que bien!
	len = get_size(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (num < 0)
	{
		str[0] = '-';
		num = -n;
	}
	else
		num = n;
	if (num == 0)
		str[0] = '0';
	str[len] = '\0';
	while (num != 0)
	{
		str[len - 1] = (num % 10) + '0';
		num = num / 10;
		len--;
	}
	return (str);
}
