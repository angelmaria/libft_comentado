#include "libft.h"

char	*ft_strrchr(const char *str, int c) // toma dos argumentos: "str": un puntero a una cadena de caracteres -la cadena en la que queremos buscar-; "c": el carácter que queremos encontrar. La f(x) devuelve un puntero al último carácter encontrado o NULL si no se encuentra. 
{
	int		i; // variable i tipo entero para usar como índice. 

	i = ft_strlen(str); // asigna a "i" la longitud de la cadena str utilizando la fx ft_strlen. 
	while (i >= 0)
	{
		if (str[i] == (char)c) // comprueba si el carácter en la posición i de str es igual al carácter c. 
			return ((char *)str + i); // si encuentra el carácter, devuelve un puntero a esa posición en la cadena str. 
		i--; // decrementa "i" para contintuar buscando hacia atrás en la cadena. 
	}
	if (c == '\0')
		return ((char *)str + i); // Si "c" es el carácter nulo, devuelve un puntero a la posición actual de i en la cadena "str".
	return (NULL); // si no se encuentra el carácter ni es el carácter nulo, devuelve NULL. 
}
// En reusmen, esta función busca el carácter "c" en la cadena "str" desde el final hacia el principio y devuelve un punteor a la última aparición de ese carácter o NULL si no se encuentra. Es útil para buscar la última ocurrencia de un carácter específico en una cadena. 
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