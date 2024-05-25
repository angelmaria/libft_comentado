#include "libft.h"

int	ft_strncmp(const char *s1, char *s2, size_t n)
{
	while (*s1 != '\0' && *s1 == *s2 && n > 0)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
// Test
int main(void)
{
	const char *str1 = "Hello, world!";
	const char *str2 = "Hello, there!";
	size_t n = 5; // Número de caracteres a comparar

	int result = ft_strncmp(str1, str2, n);

	if (result == 0)
		printf("Las primeras %zu letras son iguales.\n", n);
	else if (result < 0)
		printf("La cadena 1 es menor que la cadena 2.\n");
	else
		printf("La cadena 1 es mayor que la cadena 2.\n");

	return 0;
}