/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angemart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:46:21 by angemart          #+#    #+#             */
/*   Updated: 2024/04/24 12:46:29 by angemart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len) // La función devuelve un puntero 'void*', lo que significa que puede devolver un puntero a cualquier tipo de dato. Toma tres parámetros: un puntero 'void *b', que es el bloque de memoria que se va a llenar; un 'int c', que es el valor con el que se va a llenar el bloque de memoria; y un size_t len, que es el número de bytes que se van a llenar.
{
	size_t	i; // Se declara una variable i de tipo size_t, que se utilizará como contador en el bucle que sigue.

	if (!b) // Esta es una comprobación de seguridad. Si el puntero 'b' es 'NULL', la función devuelve 'NULL' inmediatamente, ya que no se puede llenar un bloque de memoria que no existe.
		return (NULL);
	i = 0;
	while (i < len) // Este es el comienzo de un bucle 'while' que se ejecutará mientras 'i' sea menor que 'len', es decir, hasta que se haya procesado la cantidad de bytes especificada por 'len'.


	{
		*(unsigned char *)(b + i) = (unsigned char)c; // Dentro del bucle, se convierte el puntero 'b' a un puntero a 'unsigned char' y se le suma 'i' para acceder a la posición actual del bloque de memoria que se va a llenar. Luego, se asigna el valor de 'c' (también convertido a 'unsigned char') a esa posición de memoria.
		i++; // Se incrementa el contador i para pasar al siguiente byte en el siguiente ciclo del bucle.
	}
	return (b); // Una vez completado el bucle y llenado el bloque de memoria, la función devuelve el puntero 'b', que ahora apunta al bloque de memoria llenado con el valor 'c'.
}
// 'ft_memset' es una implementación de la función estándar 'memset' que llena un bloque de memoria con un valor específico byte a byte. Es útil para inicializar bloques de memoria o establecer todos los bytes de un buffer a un valor particular.
// Test
int main() {
    char buffer[50]; // Declaramos un buffer de 50 caracteres.

    // Inicializamos el buffer con puntos para visualizar mejor el cambio.
    ft_memset(buffer, '.', sizeof(buffer) - 1);

    // Establecemos el último carácter del buffer a '\0' para terminar la cadena.
    buffer[sizeof(buffer) - 1] = '\0';

    printf("Buffer antes de ft_memset: %s\n", buffer);

    // Llamamos a ft_memset para llenar los primeros 10 caracteres con 'A'.
    ft_memset(buffer, 'A', 10);

    printf("Buffer después de ft_memset: %s\n", buffer);

    return 0;
}