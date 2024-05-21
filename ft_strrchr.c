#include "libft.h"
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = strlen(s);
	if (c == 0) // Si c es igual a 0 (es decir, estamos buscando el carácter nulo \0), la función simplemente devuelve un puntero al final de la cadena s (es decir, s + i). Esto tiene en cuenta que el carácter nulo también forma parte de la cadena.
		return ((char *)s + i);
	while (i >= 0)
	{
		if (s[i] == c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
// Test (borrar)

int	main(void)
{
	const char	*cadena = "Ejemplo de cadena de texto";
	char		caracter_a_buscar = 'd';
	char	*resultado;

	// Buscar la última aparición del carácter 'd'
	resultado = ft_strrchr(cadena, caracter_a_buscar);
	if (resultado != NULL)
		printf("Última aparición del carácter '%c': %s\n", caracter_a_buscar, resultado);
	else
		printf("Carácter '%c' no encontrado.\n", caracter_a_buscar);

	// Prueba con el carácter nulo
	resultado = ft_strrchr(cadena, '\0');
	if (resultado != NULL)
		printf("Carácter nulo encontrado al final de la cadena: %s\n", resultado);
	else
		printf("Carácter nulo no encontrado.\n");

	return (0);
}