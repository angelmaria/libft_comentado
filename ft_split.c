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

static size_t	ft_count_substring(const char *s, char c) // cuenta cuantas veces aparece el carácter 'c' en la cadena 's', o lo que es lo mismo: el número total de subcadenas separadas por 'c'.
{
	size_t	count; // declaración de variable para contar subcadenas.
	size_t	flag; // declaración de variable para marcar el inicio de una nueva subcadena.

	count = 0;
	flag = 0;
	if (!s) // Si la cadena 's' es 'NULL', retorna 0, indicando que no hay subcadenas.
		return (0);
	while (*s != '\0') // Inicia un bucle que se ejecuta mientras no se alcance el final de la cadena (\0).
	{
		if (*s == c) // si el carácter actual (al que apunta '*s') es igual que el delimitador (el carácter buscado 'c'), reiniciamos 'flat' a 0. Esto indica el final de una subcadena (los límites de las subcadenas los determina c). 
			flag = 0;
		else if (flag == 0) // Si 'flag' es 0 y el carácter actual no es el delimitador, establece 'flag' a 1 e incrementa 'count'.
		{
			flag = 1;
			count++;
		}
		s++; // Avanza al siguiente carácter de la cadena.
	}
	return (count); // Retorna el número total de subcadenas encontradas.
}

static size_t	ft_numchar(const char *s, char c) // Fx estática cuyo alcance está limitado al archivo de código fuente en el que se define. Devuelve un size_t -tipo de dato entero sin signo usado para representar tamaños-, y toma dos parámetros: un puntero a 'char' que apunta a una cadena 's', y un 'char c' que representa el delimitador. Esta fx cuenta los caracteres hasta el próximo delimitador (la longitud de una subcadena en 's' hasta toparse con 'c') o el final de la cadena (si no encuentra el delimitador), lo que ocurra primero. 
{
	size_t	count; // Se declara una variable count de tipo size_t que se utilizará para contar los caracteres.

	count = 0; // Inicializamos count en 0. Este será el contador que incrementaremos hasta encontrar el delimitador o el final de la cadena.
	while (s[count] != c && s[count] != '\0') // Este bucle 'while' continúa mientras el carácter actual en la posición 'count' de la cadena 's' no sea el delimitador 'c' y tampoco sea el carácter nulo '\0', que indica el final de la cadena. En cada iteración, incrementamos 'count'.
		count++;
	return (count); // Finalmente, la función devuelve el valor de 'count', que es la cantidad de caracteres hasta el delimitador o el final de la cadena.
}

static char	**ft_free_matrix(const char **matrix, size_t len_matrix) // También es una función estática. Devuelve un puntero a un puntero a 'char', que es cómo se representa una matriz de cadenas en C. Toma dos parámetros: un puntero a un puntero a 'char' que apunta a matrix, una matriz de cadenas, y un 'size_t' 'len_matrix' que representa la longitud de la matriz. Esta función libera la memoria asignada a una matriz de cadenas (punteros a caracteres). Recorre la matriz y libera cada subcadena individual antes de liberar la matriz en sí. 
{
	while (len_matrix--) // Este bucle while se ejecuta mientras 'len_matrix' sea mayor que 0. En cada iteración, decrementa 'len_matrix' y luego libera la subcadena en la posición 'len_matrix' de la matriz.
		free((void *)matrix[len_matrix]);
	free(matrix); // Después de liberar todas las subcadenas, esta línea libera la memoria asignada a la matriz misma.
	return (NULL); // La función devuelve NULL después de liberar la memoria, lo que es útil para evitar que se acceda a la memoria ya liberada.
}

char	**ft_split(const char *s, char c) // divide la cadena s en subcadenas utilizando el carácter c como delimitador. Crea una matriz de punteros a caracteres para almacenar las subcadenas resultantes. 
{
	char	**matrix;
	size_t	len;
	size_t	i;
	size_t	sl;

	i = 0;
	sl = 0;
	len = ft_count_substring(s, c); // calcula la cantidad de subcadenas necesarias
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