/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angemart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:46:43 by angemart          #+#    #+#             */
/*   Updated: 2024/04/24 12:46:49 by angemart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Esta fx escribe el carácter c en el descriptor de archivo fd.

void	ft_putchar_fd(char c, int fd) // toma dos parámetros: el carácter 'char c' que se va a escribir, y el descriptor de archivo 'int fd' donde se va a escribir iel carácter. Los descriptores de archivo estándar son 0 para la entrada estándar (stdin), 1 para la salida estándar (stdout), y 2 para el error estándar (stderr).
{
	write(fd, &c, 1); // Dentro del cuerpo de la función, se llama a la función de sistema write, que es parte de la biblioteca estándar de C POSIX. La función write toma tres argumentos: el descriptor de archivo 'fd' en el que se va a escribir, la dirección de memoria '&c' del carácter 'c', que 'write' usará para obtener el valor del carácter a escribir, y '1', el número de bytes a escribir, que en este caso es '1' porque un carácter tiene un tamaño de 1 byte.  
}
// La función 'ft_putchar_fd' es útil cuando necesitas escribir un carácter en un archivo o en un flujo de salida diferente al estándar, como podría ser un archivo de log, un socket de red, o cuando estás redirigiendo la salida a otro lugar que no sea la pantalla. 
// Test
int main() {
    // Vamos a escribir 'Hola Mundo!' en la salida estándar (pantalla)
    char *mensaje = "Hola Mundo!";
    int i = 0;

    // Mientras no lleguemos al final de la cadena de caracteres
    while (mensaje[i]) {
        ft_putchar_fd(mensaje[i], 1); // 1 es el descriptor de archivo para stdout
        i++;
    }

    return 0;
}