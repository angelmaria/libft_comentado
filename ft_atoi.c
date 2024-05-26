/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angemart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:08:48 by angemart          #+#    #+#             */
/*   Updated: 2024/03/13 13:33:29 by angemart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 1. Obviar espacios en blanco
 2. Transformar el signo negativo si lo hubiera
 3. La conversión de ascii a integer
 */

#include "libft.h"

int	ft_atoi(const char *str) // toma como argumento una cadena de caracteres constante. 
{
	int	res; // declara una variable "res" para almacenar el resultado final. 
	int	sign; // declara una variable "sign" para almacenar el signo del número, 1 para positivo o -1 para negativo

	res = 0;
	sign = 1; 
	while (*str == 32 || (*str >= 9 && *str <= 13)) // mientras el caracter actual sea un espacio (ASCII 32) o un caracter de control (tabulación, nueva línea, tabulador horizontal o vertical, etc=)
		str++;
	if (*str == '-')
		sign *= -1; // multiplica 'sign' por -1 para cambiar el signo a negativo. 
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0'; // ... multiplica por 10 (desplaza un lugar en decimal) y suma el valor numérico del caracter actual. 
		str++;
	}
	return (res * sign);
}
// Test (borrar)
int main(void)
{
    // Prueba con números positivos
    printf("ft_atoi('123') = %d\n", ft_atoi("123"));
    
    // Prueba con números negativos
    printf("ft_atoi('-123') = %d\n", ft_atoi("-123"));
    
    // Prueba con espacios al principio
    printf("ft_atoi('   456') = %d\n", ft_atoi("   456"));
    
    // Prueba con signo más
    printf("ft_atoi('+789') = %d\n", ft_atoi("+789"));
    
    // Prueba con caracteres no numéricos al principio
    printf("ft_atoi('abc123') = %d\n", ft_atoi("abc123"));
    
    // Prueba con caracteres no numéricos al final
    printf("ft_atoi('123abc') = %d\n", ft_atoi("123abc"));
    
    return 0;
}
