/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angemart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:45:46 by angemart          #+#    #+#             */
/*   Updated: 2024/04/24 12:45:55 by angemart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len) // Esta función intenta copiar 'len' bytes de la memoria apuntada por 'src' a la memoria apuntada por 'dst'. El tipo void* indica que los punteros pueden ser de cualquier tipo.
{
	int	i; // Se declara una variable i que se utilizará como contador en los bucles while.

	if (!dst || !src) // Chequeo de seguridad. Si dst (destino) o src (fuente) son nulos (es decir, no apuntan a ninguna dirección de memoria válida), la función retorna NULL.
		return (NULL);
	if (dst > src) // Esta condición comprueba si la dirección de memoria de dst es mayor que la de src. Esto es importante porque si se superponen, copiar de manera lineal podría sobrescribir datos en src que aún no han sido copiados. Aclaración: "mayor dirección de memoria" o "después" se refiere a la posición de los punteros en la memoria, no a su orden en una cadena de caracteres. En el contexto de la memoria del ordenador, "después" significa una dirección de memoria más alta, no la posición en una secuencia de caracteres. Esto es importante porque si estás copiando de un área de memoria a otra que se solapan, y 'dst' está después de 'src', debes copiar de atrás hacia adelante para evitar sobrescribir los datos en 'src' que aún no has copiado. 
	{
		i = (int)len -1; // Si dst está después de 'src', se inicializa 'i' al último índice del bloque de memoria que queremos copiar.
		while (i >= 0) // Este bucle while se ejecutará mientras i sea mayor o igual a 0, copiando los datos de atrás hacia adelante para evitar la sobreescritura mencionada.
		{
			*(char *)(dst + i) = *(char *)(src + i); // Dentro del bucle, se copia cada byte de src a dst utilizando un casting a (char *) para trabajar con los datos a nivel de bytes. Luego, se decrementa i para moverse al siguiente byte hacia atrás.
			i--;
		}
	}
	else // Si 'dst' no está después de 'src', entonces se copiará de manera lineal desde el principio.
	{
		i = 0; // Se inicializa 'i' a 0 para comenzar desde el primer byte.
		while (i < (int)len) // Este bucle while se ejecutará mientras 'i' sea menor que 'len', copiando los datos de adelante hacia atrás.
		{
			*(char *)(dst + i) = *(char *)(src + i); // Al igual que en el otro bucle, se copia cada byte de 'src' a 'dst' y luego se incrementa i para moverse al siguiente byte hacia adelante.
			i++;
		}
	}
	return (dst); // Finalmente, después de copiar todos los bytes, la función retorna el puntero al destino ('dst'), que ahora contiene los datos copiados de 'src'.
}
// Same with less code.
// void		*ft_memmove(void *dst, const void *src, size_t len)
// {
// 	char	*tmp;

// 	tmp = (char *)malloc(sizeof(char) * len);
// 	if (tmp == NULL)
// 		return (NULL);
// 	ft_memcpy(tmp, src, len);
// 	ft_memcpy(dst, tmp, len);
// 	free(tmp);
// 	return (dst);
// }

// ----------------------------------------------------------------

// Otra alternativa más legible ya que permite utilizar la notación de índice de array [i] en lugar de la artimética de punteros 
// y la desreferenciación explícita
// #include "libft.h"

// void	*ft_memmove(void *dst, const void *src, size_t len)
// {
// 	int	i;

// 	if (!dst || !src)
// 		return (NULL);

// 	// alternativa más legible
// 	char *dest;
// 	char *sourc;
// 	dest = (char *)dst;
// 	sourc = (char *)src;

// 	if (dest > sourc)
// 	{
// 		i = (int)len -1;
// 		while (i >= 0)
// 		{
// 			dest[i] = sourc[i];
// 			i--;
// 		}
// 	}
// 	else
// 	{
// 		i = 0;
// 		while (i < (int)len)
// 		{
// 			dest[i] = sourc[i];
// 			i++;
// 		}
// 	}
// 	return (dest);
// }