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
	size_t	substring; // declaración de variable para marcar el inicio de una nueva subcadena.

	count = 0;
	substring = 0;
	if (!s) // Si la cadena 's' es 'NULL', retorna 0, indicando que no hay subcadenas.
		return (0);
	while (*s != '\0') // Inicia un bucle que se ejecuta mientras no se alcance el final de la cadena (\0).
	{
		if (*s == c) // si el carácter actual (al que apunta '*s') es igual que el delimitador (el carácter buscado 'c'), reiniciamos 'flat' a 0. Esto indica el final de una subcadena (los límites de las subcadenas los determina c). 
			substring = 0;
		else if (substring == 0) // Si 'substring' es 0 y el carácter actual no es el delimitador, establece 'substring' a 1 e incrementa 'count'.
		{
			substring = 1;
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

char	**ft_split(const char *s, char c) // divide la cadena s en subcadenas utilizando el carácter 'c' como delimitador. Crea una matriz de punteros a caracteres para almacenar las subcadenas resultantes. 
{
	char	**matrix; // un puntero a un puntero a 'char' para almacenar la matriz de subcadenas.
	size_t	len; // de tipo size_t, para almacenar la cantidad de subcadenas.
	size_t	i; // de tipo size_t, para usar como índice en los bucles.
	size_t	sl; // de tipo size_t, para almacenar la longitud de la subcadena actual.

	i = 0;
	sl = 0;
	len = ft_count_substring(s, c); // calcula la cantidad de subcadenas que se crearán a partir de 's' utilizando 'c como delimitador. 
	matrix = (char **)malloc(sizeof(char *) * (len + 1)); // asigna memoria para la matriz 'matrix'. Se reserva espacio para 'len + 1' punteros a 'char', donde el +1 es para el puntero final 'NULL' que indica el final de la matriz.
	if (!matrix) // Si malloc falla y matrix es 'NULL', la función devuelve 'NULL' para indicar un error en la asignación de memoria.
		return (NULL);
	while (i < len) // Este bucle while se ejecutará mientras i sea menor que 'len', es decir, mientras haya subcadenas por procesar.
	{
		while (*s == c) // itera sobre 's' (avanza el puntero 's'), ignorando los delimitadores 'c' al principio de la cadena. 
			s++;
		sl = ft_numchar((const char *)s, c); // calcula la longitud de la subcadena actual en 's' hasta el próximo delimitador. 
		matrix[i] = (char *)malloc(sizeof(char) * sl + 1); // asigna memoria para la subcadena actual, resevando 'sl + 1' caracteres, donde el +1 es para el carácter nulo '\0' al final de la cadena.  
		if (!matrix[i]) // Si la asignación de memoria falla, se llama a 'ft_free_matrix' para liberar la memoria previamente asignada y se devuelve 'NULL'.
			return (ft_free_matrix((const char **)matrix, len));
		ft_strlcpy(matrix[i], s, sl + 1); // copia la subcadena desde 's' a matrix[i] utilizando ft_strlcpy.
		s = (ft_strchr(s, (int)c)); // avanza 's' (se actualiza el puntero) al siguiente delimitador 'c' en la cadena. 
		i++; // Se incrementa el índice i para procesar la siguiente subcadena.
	}
	matrix[i] = 0; // establece el último elemento de la matriz 'matrix' en NULL para indicar el final de la matriz de subcadenas.
	return (matrix); // Finalmente, la función devuelve la matriz matrix con las subcadenas resultantes.
}
// Test
int main(void)
{
    char **substrings;
    const char *string_to_split = "esto es una prueba";
    char delimiter = ' ';

    substrings = ft_split(string_to_split, delimiter);

    // Imprimir y liberar la memoria de las subcadenas
    if (substrings)
    {
        for (int i = 0; substrings[i] != NULL; i++)
        {
            printf("Subcadena %d: %s\n", i, substrings[i]);
            free(substrings[i]); // Liberar cada subcadena
        }
        free(substrings); // Liberar la matriz de subcadenas
    }

    return 0;
}