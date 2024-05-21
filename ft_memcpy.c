/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angemart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:45:32 by angemart          #+#    #+#             */
/*   Updated: 2024/04/24 12:45:36 by angemart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	i = 0;
	d = (char *)dest;
	s = (char *)src;
	if (!src && !dest)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
// Alternativa usando aritmética de punteros
// void	*ft_memcpy(void *dest, const void *src, size_t n)
// {
// 	int	i;

// 	i = 0;
// 	if (!src && !dest)
// 		return (NULL);
// 	while (i < n)
// 	{
// 		*(char *)(dest + i) = *(char *)(src + i);
// 		i++;
// 	}
// 	return (dest);
// }