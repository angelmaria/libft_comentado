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
// implementación personalizada de la fx estándar de C memcpy. Su propósito es copiar 'n' bytes de memoria del área apuntada por 'src' al área apuntada por 'dest'.

void	*ft_memcpy(void *dest, const void *src, size_t n) // toma 3 argumentos: un puntero al área de memoria donde se copiarán los datos. Un puntero al área de memoria de donde se copiarán los datos. El número de bytes a copiar. 
{
	size_t	i; // se declara un contador para el bucle.
	char	*d; // un puntero a 'char' para acceder a la memoria de destino.
	char	*s; // un puntero a 'char' para acceder a la memoria fuente.

	i = 0; // se inicializa el contador en 0.
	d = (char *)dest; // se convierten los punteros 'void *' a punteros 'char *' para poder copiar los datos byte a byte. 
	s = (char *)src;
	if (!src && !dest) // antes de comenzar a copiar, se verifica si alguno de los punteros 'src' o 'dst' es NULL. Si es así, la fx termina y devuelve NULL, ya que no se puede copiar desde o hacia una dirección nula. 
		return (NULL);
	while (i < n) // Se inicia un bucle while que se ejecutará mientras i sea menor que n.
	{
		d[i] = s[i]; // Dentro del bucle, se copia cada byte de la fuente s al destino d.
		i++; // Después de cada copia, se incrementa i para pasar al siguiente byte.
	}
	return (dest); // Una vez que se han copiado todos los bytes, la función devuelve un puntero al área de memoria de destino, dest.
	// Este código es una implementación típica de la función memcpy, con la adición de una comprobación de punteros nulos al principio.
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
// Test
int main(void)
{
	char src[] = "Hello, world!";
	char dest[20]; // Asegúrate de que el tamaño del destino sea suficiente para copiar la cadena

	// Llamada a ft_memcpy
	ft_memcpy(dest, src, strlen(src) + 1); // +1 para copiar el carácter nulo al final

	printf("Cadena copiada: %s\n", dest);

	return 0;
}