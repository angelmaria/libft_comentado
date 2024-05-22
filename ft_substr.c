/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angemart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:48:44 by angemart          #+#    #+#             */
/*   Updated: 2024/04/24 12:48:49 by angemart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len) // toma tres argumentos: "s": un puntero a una cadena de caracteres -la cadena de la que queremos extraer una subcadena-. "start": la posición inicial desde la cual extraer la subcadena. "len": la longitud deseada de la subcadena. La fx devuelve un puntero a la subacadena extraída. 
{
	size_t	i; // variable para usar como índice. 
	size_t	s_len; // variable para almacenar la longitud de la cadena "s"
	char	*substr; // puntero "substr" para almacenar la subcadena extraída. 

	if (!s) // verifica si "s" es un puntero nulo (no apunta a ninguna dirección de memoria válida). Si es así devuelve NULL:
		return (NULL);
	s_len = ft_strlen(s); // calcula la longitud exacta de la cadena "s" utilizando la fx ft_strlen. 
	if (start > s_len || *s == '\0') // comprueba si "start" está fuera de los límites de la cadena o si "s" es una cadena vacía. Si es cierto, devuelve una cadena duplicada vacía. 
		return (ft_strdup(""));
	if (len > s_len - start) // ajusta la longitud "len" si es mayor que la cantidad de caracteres disponibles desde "start" hasta el final de la cadena. 
		len = s_len - start;
	substr = (char *)malloc(sizeof(char) * (len + 1)); // asigna memoria dinámica par ala subcadena utilizando "malloc". La longitud es "len + 1" para incluir el carácter n ulo al final. 
	if (!substr) // verifica si la asignación de memoria fue exitosa. Si no, devuelve NULL. 
		return (NULL);
	i = 0;
	while (i < len && s[start + i]) // bucle que se ejecuta mientras "i" sea menor que "len" y el carácter en la posición "start + i" de "s" no sea nulo. 
	{
		substr[i] = s[start + i]; // copia el carácter actual de "s" a la posición correspondiente en "substr".
		i++;
	}
	substr[i] = 0;
	return (substr); // devuelve el puntero a la subcadena extraída. 
}
// En resumen, esta fx extrae una subcadena "s" comenzando desde la posición "start" y con una longitud máxima de "len". Si "s" es nula o si "start" está fuera de los límites, devuelve una cadena vacía. 
// Test (borrar)
int main() {
    const char *source_string = "Hello, world!";
    unsigned int start_index = 7; // Start at index 7 (after the comma)
    size_t length = 5; // Extract 5 characters

    char *sub_string = ft_substr(source_string, start_index, length);

    if (sub_string == NULL) {
        printf("Error: ft_substr failed to allocate memory.\n");
    } else {
        printf("Substring: %s\n", sub_string);
        free(sub_string); // Remember to free the allocated memory
    }

    return 0;
}
