#include "libft.h"

void	*ft_calloc(size_t count, size_t size) // 2 argumentos de tipo size_t: la cantidad de elementos que deseamos asignar y el tamaño de cada elemento respectivamente.
{
	size_t	total; // almacena el tamaño total de bytes a asignar. 
	char	*mem; // puntero para apuntar al bloque de memoria asignado. 
    size_t	i; // índice para acceder a cada byte.

	total = count * size; // calcula el tamaño total de b = multiplicando el número de elementos por su tamaño. 
	mem = malloc(total); // asigna memoria y almacena el puntero en 'mem'.
	if (total == NULL) // si 'malloc' falla y devuelve NULL...
		return (NULL); // .. la fx devuelve NULL para indicar el fallo en la asignación de memoria.
	i = 0;
    while (i < total)
    {
        mem[i] = 0;
        i++;
    }
	return (mem); // devuelve el puntero al bloque de memoria asignado y inicializando a cero. 
}
// Test (borrar)
int main(void)
{
    int *array;
    int n;
    int i;

    // Definir el número de elementos del array
    n = 5;

    // Usar ft_calloc para asignar memoria para el array
    array = (int *)ft_calloc(n, sizeof(int));

    // Comprobar si ft_calloc retornó NULL
    if (!array)
    {
        printf("La asignación de memoria falló.\n");
        return (1);
    }

    // Imprimir los valores del arreglo para verificar que se inicializaron a cero
    printf("Valores del arreglo después de usar ft_calloc:\n");
    i = 0;
    while(i < n)
    {
        printf("%d ", array[i]);
        i++;
    }
    printf("\n");

    // Liberar la memoria asignada
    free(array);

    return (0);
}
