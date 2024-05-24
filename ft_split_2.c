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
		if (*s == c) // si el carácter actual (al que apunta '*s') es igual que el delimitador (el carácter buscado 'c'), reiniciamos 'substring' a 0. Esto indica el final de una subcadena (los límites de las subcadenas los determina c). 
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
	while (len_matrix--) // Este bucle 'while' se ejecuta mientras 'len_matrix' sea mayor que 0. En cada iteración, decrementa 'len_matrix' y luego libera la subcadena en la posición 'len_matrix' de la matriz.
		free((void *)matrix[len_matrix]);
	free(matrix); // Después de liberar todas las subcadenas, esta línea libera la memoria asignada a la matriz misma.
	return (NULL); // La función devuelve NULL después de liberar la memoria, lo que es útil para evitar que se acceda a la memoria ya liberada.
}
/*
The affect function is responsible for splitting the original string (s) based on the delimiter character (c) and storing the resulting substrings in the destination array (dst). Here's a breakdown of the function line by line:

1. Variable declarations:

int i; - This variable keeps track of the current index in the original string (s).
int j; - This variable keeps track of the index in the destination array (dst) to store the current substring.
int k; - This variable is used as a counter within each substring to store individual characters.
2. Initialization:

i = 0; - Set the starting index of the original string to the beginning (0).
j = 0; - Set the starting index for the destination array to the first element (0).
3. Loop through the original string:

while (s[i] != '\0' && j < l) - This loop continues as long as two conditions are met:
The current character in s is not the null terminator (\0), indicating there are more characters to process.
The index j in the dst array is less than the allocated length (l), ensuring we don't write beyond the allocated memory.
4. Skip delimiters:

while (s[i] == c) - This loop keeps incrementing i as long as the character at the current index in s is the delimiter (c). This effectively skips over any leading or consecutive delimiters.
5. Allocate memory for the current substring:

dst[j] = (char *)malloc(sizeof(char) * numchar(s, c, i) + 1);
This line allocates memory for the current substring in the dst array at index j.
numchar(s, c, i) is called to calculate the length of the substring starting from i (excluding delimiters).
sizeof(char) is multiplied by the length and 1 is added to account for the null terminator at the end of the string.
The result is cast to (char *) to match the expected pointer type for the dst array.
If the allocation fails (malloc returns NULL), the function jumps to the error handling section (return (free_matrix((char const **)dst, j));).
6. Error handling:

if (dst[j] == NULL) - This checks if the memory allocation for the substring failed.
If it fails, the function calls free_matrix((char const **)dst, j) to free any previously allocated memory in dst (up to index j) and returns NULL to indicate the error.
7. Copy characters to the current substring:

while (s[i] != '\0' && s[i] != c) - This loop copies characters from the original string (s) to the current substring in dst[j].
The loop continues as long as the character at the current index in s is not the null terminator or the delimiter.
dst[j][k++] = s[i++];
dst[j][k] assigns the character at the current index in s to the current position (k) within the substring in dst[j].
k++ increments the counter k to point to the next position in the substring.
i++ increments the index i to move to the next character in the original string.
8. Add null terminator:

dst[j][k] = '\0'; - This adds the null terminator character (\0) at the end of the current substring in dst[j] to mark the string's end.
9. Move to the next substring:

j++; - This increments the index j in the dst array to point to the next position where the next substring will be stored.
10. Terminate string in dst:

dst[j] = 0; - After processing all characters in the original string, this sets the last element in dst to 0 (null pointer) to mark the end of the array of substrings.
11. Return the destination array:

return (dst); - The function returns the pointer to the dst array containing the split substrings.
**In summary, the affect function iterates through the original string, skips delimiters, allocates memory for */

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