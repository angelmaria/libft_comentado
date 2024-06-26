/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angemart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:34:06 by angemart          #+#    #+#             */
/*   Updated: 2024/05/16 13:34:08 by angemart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// La función ft_strlcpy copia una cadena de caracteres (src) en otra (dest), pero con una particularidad: siempre asegura que la cadena de destino esté terminada con el carácter nulo (\\0).

size_t	ft_strlcpy(char *dest, const char *src, size_t size) // El tercer parámetro, size, representa el tamaño del búfer de destino (dest). Si size es 0, la función simplemente cuenta la longitud de la cadena fuente (src) y devuelve ese valor.
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (i < size)
		dest[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}
// Test (borrar)
int main(void)
{
    char src[] = "Copilot es asombroso!";
    char dest[19];
    size_t copied;

    // Prueba la función ft_strlcpy con un tamaño de buffer suficiente
    copied = ft_strlcpy(dest, src, sizeof(dest));
    printf("Cadena copiada: '%s'\n", dest);
    printf("Longitud de la cadena original: %zu\n", copied);

    // Prueba la función ft_strlcpy con un tamaño de buffer más pequeño que la cadena de origen
    copied = ft_strlcpy(dest, src, 10);
    printf("Cadena copiada con buffer limitado: '%s'\n", dest);
    printf("Longitud de la cadena original: %zu\n", copied);

    return 0;
}
