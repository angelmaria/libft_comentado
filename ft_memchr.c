/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angemart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:44:43 by angemart          #+#    #+#             */
/*   Updated: 2024/04/24 12:44:47 by angemart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n) // fx que devuelve un puntero genérico. 3 parámetros: un puntero 's' a una región de memoria (void) que queremos escanear, el valor del carácter 'c' que estamos buscando, y el número de bytes 'n' que queremos examinar en la región de memoria. 
{
	char	*str;
	size_t	i; // Se declara una variable local llamada i de tipo size_t (un tipo entero sin signo).

	i = 0;
	str = (char *)s; // Convierte el puntero 's' (que originalmente es un puntero a const void) a un puntero a char. Esto se hace para poder acceder a los bytes individuales de la región de memoria.
	while (i < n)
	{
		if ((unsigned char)str[i] == (unsigned char)c) // Dentro del bucle, verifica si el byte en la posición 'i' de la región de memoria (interpretado como unsigned char) es igual al valor de c (también interpretado como unsigned char). Si es cierto, significa que hemos encontrado el carácter buscado.
			return ((char *)s + i); // o también (&str[i]); Si encontramos el carácter, devolvemos un puntero a la posición en la región de memoria donde se encuentra. La expresión ((char *)s + i) calcula la dirección de memoria correcta sumando 'i' al puntero original s'.
		i++;
	}
	return (NULL); // Si no se encuentra el carácter en la región de memoria, la función devuelve NULL.
}
/*
En resumen, la función ft_memchr escanea una región de memoria (los primeros n bytes) en busca de una ocurrencia del carácter especificado. Si lo encuentra, devuelve un puntero a esa posición; de lo contrario, devuelve NULL. Es útil para buscar un carácter específico dentro de una cadena de bytes
*/
// Key Points:

// memchr is efficient for finding the first occurrence of a character within a memory block.
// It's important to consider the size of the memory block (n) to avoid exceeding valid memory boundaries.
// The return value is a pointer, so you might need to cast it back to the appropriate data type for further processing (e.g., cast to char* for string manipulation).
// Remember that memchr only searches for the first occurrence. If you need to find all occurrences, you'll need to implement a loop or use a different function like strchr (for null-terminated strings).
int main(void)
{
	const char *str = "Hello, world!";
	int search_char = 'o';
	size_t search_length = ft_strlen(str);

	// Llamada a ft_memchr
	const char *result = (const char *)ft_memchr(str, search_char, search_length);

	if (result)
	{
		printf("Carácter encontrado en la posición: %ld\n", result - str);
	}
	else
	{
		printf("Carácter no encontrado.\n");
	}

	return 0;
}
