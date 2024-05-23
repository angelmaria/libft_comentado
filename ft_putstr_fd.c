/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angemart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:47:42 by angemart          #+#    #+#             */
/*   Updated: 2024/04/24 12:47:47 by angemart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd) // función que toma dos parámetros: un puntero a una cadena de caracteres 's' y un descriptor de archivo 'fd'.
{
	int	i;

	if (!s || fd < 0) // Comprueba si la cadena 's' es 'NULL' o si el descriptor de archivo 'fd' es negativo. Si alguna de estas condiciones es verdadera, la función termina inmediatamente con 'return;'.
		return ;
	i = 0; // inicializa la variable 'i' a 0.
	while (s[i]) // Un bucle while que continúa mientras el carácter en la posición 'i' de la cadena 's' no sea el carácter nulo \0.
		ft_putchar_fd(s[i++], fd); // Dentro del bucle, la función 'ft_putchar_fd' se llama con el carácter actual 's[i]' y el descriptor de archivo 'fd'. Después de la llamada, el índice 'i' se incrementa en 1. Esta fx escribe un solo carácter en el descriptor de archivo especificado. Si 'fd' es 1, entonces la salida es la salida estándar (la pantalla).
}
// Test
int main(void)
{
    // La cadena que queremos imprimir.
    char *str = "¡Hola, mundo!";

    // Llamamos a ft_putstr_fd con la cadena y el descriptor de archivo 1,
    // que corresponde a la salida estándar.
    ft_putstr_fd(str, 1);

    // Retornamos 0 para indicar que el programa terminó con éxito.
    return (0);
}