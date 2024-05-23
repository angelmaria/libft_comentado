/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angemart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:45:06 by angemart          #+#    #+#             */
/*   Updated: 2024/04/24 12:45:10 by angemart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n) // toma 3 parámetros: un puntero al primer bloque de memoria, un puntero al segundo bloque de memoria y la cantidad de bytes a comparar. 
{
	char	*str1;
	char	*str2;
	size_t	i;

	i = 0; // se inicializa la variable 'i' en 0, que se usará como índice para recorrer los bloques de memoria. 
	str1 = (char *)s1; // se convierten los punteros 'void *' a punteros 'char *' para poder realizar operaciones de comparación byte a byte. 
	str2 = (char *)s2;
	while (i < n) // se inicia un bucle while que se ejecutará mientras 'i' sea menor que 'n', es decir, mientras no se haya alcanzado el número de bytes a comparar. 
	{
		if (str1[i] != str2[i]) // dentro del bucle, se compara cada byte de los dos bloques de memoria. 
			return ((unsigned char)str1[i] - (unsigned char)str2[i]); // si se encuentra una diferencia entre los bytes en la misma posición, la fx devuelve la diferencia entre los valores de los bytes como un entero. La conversión a 'unsigned char' es necesaria para garantizar un valor positivo si 'str1[i]' es mayor que 'str2[i]' y viceversa. 
		i++; // si los bytes son iguales, se incrementa 'i' para continuar la comparación con el siguiente byte. 
	}
	return (0); // si se termina el bucle y no se encontraron diferencias, la fx devuelve 0, indicando que los dos bloques de memoria son iguales en los primeros 'n' bytes. 
}
