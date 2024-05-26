/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angemart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:42:39 by angemart          #+#    #+#             */
/*   Updated: 2024/04/24 12:42:53 by angemart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}
int main(void)
{
    int c = 'A'; // Cambia el valor de 'c' según el carácter que desees probar
    int result = ft_isalnum(c);

    printf("ft_isalnum('%c') = %d\n", c, result);

    return 0;
}
/*
Código con los 2 parámetros clásicos que se pasan al main, argc y argv
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Uso: %s <caracter>\n", argv[0]);
        return 1;
    }

    char c = argv[1][0];
    int result = ft_isalnum(c);

    printf("ft_isalnum('%c') = %d\n", c, result);

    return 0;
}
*/
