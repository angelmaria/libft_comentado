/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angemart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:42:14 by angemart          #+#    #+#             */
/*   Updated: 2024/04/24 12:42:18 by angemart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// se utilizar para establecer los primeros 'n' bytes del área de memoria apuntada por 'str' a cero (es decir, bytes nulos)

void	ft_bzero(void *str, size_t n) // toma un puntero genérico 'str' y un tamaño 'n'.
{
	memset(str, '\0', n); // llama a la fx memset para llenar los primeros 'n' bytes del área de memoria apuntada por 'str' con el byte nulo '\0'.
}
// función que se utiliza para llenar un bloque de memoria con un valor particular. En este caso, se utiliza para llenar la memoria con el carácter nulo '\0', efectivamente "borrando" los datos en esa área de memoria al establecer cada byte a cero. La función ft_bzero es una envoltura alrededor de memset para proporcionar esta funcionalidad específica. 