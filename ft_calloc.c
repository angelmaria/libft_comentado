#include "libft.h"

void	*ft_calloc(size_t count, size_t size) // 2 argumentos de tipo size_t: la cantidad de elementos y el tamaño de cada elemento respectivamente.
{
	size_t	b; // almacena el tamaño total de bytes a asignar. 
	void	*p; // puntero para apuntar al bloque de memoria asignado. 

	if (count == 0 || size == 0)
	{
		count = 1; // establecer 'count' a 1 para asegurar que se asigne al menos un byte. 
		size = 1; // establece 'size' a 1 por la misma razón. 
	}
	b = count * size; // calcula el tamaño total de b = multiplicando el número de elementos por su tamaño. 
	p = malloc(b); // asigna memoria y almacena el puntero en 'p'.
	if (p == NULL) // si 'malloc' falla y devuelve NULL...
		return (NULL); // .. la fx devuelve NULL para indicar el fallo en la asignación de memoria.
	else
		ft_bzero(p, b); // si la asignación es exitosa, llama a 'ft_bzero' para establecer todos los bytes a cero. 
	return (p); // devuelve el puntero al bloque de memoria asignado y inicializando a cero. 
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
