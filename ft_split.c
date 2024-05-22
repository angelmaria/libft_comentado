/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angemart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:48:07 by angemart          #+#    #+#             */
/*   Updated: 2024/04/24 12:48:10 by angemart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numstring(const char *s, char c) // cuenta cuantas veces aparece el carácter c en la cadena s. También cuenta el número total de subcadenas separadas por c (es el mismo número)
{
	size_t	count;
	size_t	flag;

	count = 0;
	flag = 0;
	if (!s)
		return (0);
	while (*s != '\0')
	{
		if (*s == c) // si el caracter al que apunta *s es igual que el caracter buscado c, resetamos flat a 0. Esto indica el final de una subcadena (los límites de las subcadenas los determina c). 
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static size_t	ft_numchar(const char *s, char c) // calcula la longitud de una subcadena en s hasta que se encuetra con el carácter c o el final de la cadena -si no encuentra a "c".
{
	size_t	count;

	count = 0;
	while (s[count] != c && s[count] != '\0')
		count++;
	return (count);
}

static char	**ft_free_matrix(const char **matrix, size_t len_matrix) // esta función libera la memoria asignada a una matriz de cadenas (punteros a caracteres). Recorre la matriz y libera cada subcadena individual antes de liberar la matriz en sí. 
{
	while (len_matrix--)
		free((void *)matrix[len_matrix]);
	free(matrix);
	return (NULL);
}

char	**ft_split(const char *s, char c) // divide la cadena s en subcadenas utilizando el carácter c como delimitador. Crea una matriz de punteros a caracteres para almacenar las subcadenas resultantes. 
{
	char	**matrix;
	size_t	len;
	size_t	i;
	size_t	sl;

	i = 0;
	sl = 0;
	len = ft_numstring(s, c); // calcula la cantidad de subcadenas necesarias
	matrix = (char **)malloc(sizeof(char *) * (len + 1)); // asigna memoria para la matriz
	if (!matrix)
		return (NULL);
	while (i < len)
	{
		while (*s == c) // itera sobre s, ignora los caracteres "c" al principio
			s++;
		sl = ft_numchar((const char *)s, c); // calcula la longitud de la subcadena actual
		matrix[i] = (char *)malloc(sizeof(char) * sl + 1); // asigna memoria para la subcadena 
		if (!matrix[i])
			return (ft_free_matrix((const char **)matrix, len));
		ft_strlcpy(matrix[i], s, sl + 1); // copia la subcadena desde s
		s = (ft_strchr(s, (int)c)); // avanza "s" al siguiente delimitador
		i++;
	}
	matrix[i] = 0; // establece el último elemento de la matriz en NULL.
	return (matrix);
}
// Test (borrar)
int main(void)
{
    char *frase = "Explorando el mundo de la programación en C";
    char delimitador = ' '; // Suponiendo que queremos dividir la frase por espacios
    char **palabras;

    palabras = ft_split(frase, delimitador);
    if (!palabras)
    {
        printf("Error: No se pudo dividir la frase.\n");
        return (1);
    }

    for (size_t i = 0; palabras[i] != NULL; i++)
    {
        printf("Palabra %zu: '%s'\n", i, palabras[i]);
        free(palabras[i]); // Liberamos cada palabra individualmente
    }
    free(palabras); // Liberamos el arreglo de palabras

    return (0);
}