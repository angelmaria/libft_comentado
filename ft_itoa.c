/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angemart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:44:27 by angemart          #+#    #+#             */
/*   Updated: 2024/04/24 12:44:32 by angemart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// ft_itoa convierte un entero a una cadena de caracteres (string). 

static size_t	ft_intlen(long nb) // fx auxiliar para calcular la longitud de un número entero. 
{
	size_t	count; // variable para contar los dígitos. 

	count = 0;
	if (nb == 0) // si el número es 0... 
	{
		count++; // ... incrementa el contador (porque 0 tiene un dígito).
		return (count); // ... y devuelve el contador. 
	}
	if (nb < 0) // si el número es negativo...
	{
		nb = nb * -1; // ... convierte el número a positivo para el cálculo. 
		count++;
	}
	while (nb > 0)
	{
		nb = nb / 10; // ... divide el número por 10 (elimina el último dígito).
		count++;
	}
	return (count); // devuelve el número total de dígitos. 
}

char	*ft_itoa(int n)
{
	char	*strnum; // puntero para almacenar el string resultante. 
	size_t	len; // variable para almacenar la longitud del número. 
	long	nb; // variable para manejar el entero como long. 

	if (n == -2147483648) // si el número es el mínimo valor de un int...
		return (ft_strdup("-2147483648")); // ... devuelve directamente el string correspondiente. 
	nb = n; // convierte el int a long para manejar el rango extendido. 
	len = ft_intlen(nb); // calcula la longitud del número. 
	strnum = (char *)malloc(sizeof(char) * len + 1); // asigna memoria para el string.
	if (!strnum) // si la asignación falla...
		return (NULL); // ... devuelve NULL. 
	strnum[len--] = '\0'; // establece el carácter nulo al final del string. 
	if (n == 0)
		strnum[0] = '0';
	if (nb < 0)
	{
		strnum[0] = '-';
		nb = nb * -1;
	}
	while (nb > 0) // mientras queden dígitos en el número...
	{
		strnum[len--] = (nb % 10) + '0'; // ... convierte el último dígito a char y lo asigna al string. 
		nb = nb / 10; // ... elimina el último dígito del número.
	}
	return (strnum); // devuelve el string resultante. 
}
// Test
int	main(void)
{
	int num = 12345; // Cambia este número para probar diferentes valores

	// Llama a ft_itoa para convertir el número en una cadena
	char *str = ft_itoa(num);

	if (str)
	{
		printf("Número original: %d\n", num);
		printf("Número convertido a cadena: %s\n", str);
		free(str); // Libera la memoria asignada por ft_itoa
	}
	else
	{
		printf("Error al convertir el número.\n");
	}

	return 0;
}
