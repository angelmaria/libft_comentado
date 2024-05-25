#include "libft.h"

t_list	*ft_lstnew(void *content) // El parámetro content es un puntero genérico (void *) que representa el contenido que queremos almacenar en el nuevo nodo de la lista.
{
	t_list	*new; // Se declara una variable local llamada 'new' de tipo puntero a t_list.

	new = (t_list *)malloc(sizeof(t_list)); // Aquí se asigna memoria dinámica para un nuevo nodo de lista utilizando malloc. La cantidad de memoria asignada es el tamaño de la estructura t_list. El resultado se almacena en la variable new. Si no se puede asignar memoria (por ejemplo, si malloc devuelve NULL), la función devuelve NULL.
	if (!new)
		return (NULL);
	new->content = content; // Asigna el puntero content al campo content del nuevo nodo de la lista.
	new->next = NULL; // Establece el campo next del nuevo nodo en NULL, ya que este nodo aún no tiene un siguiente.
	return (new); // Devuelve el puntero al nuevo nodo de la lista.)
}
/* 
En resumen, la función ft_lstnew crea un nuevo nodo de lista enlazada, asigna memoria para él, almacena el contenido proporcionado y lo devuelve como un puntero. Es un paso fundamental para construir y manipular listas enlazadas en C
*/
// Test
int	main(void)
{
	t_list	*element;
	char	*content = "Este es el contenido del elemento";
	int		fd = 1; // Descriptor de archivo para la salida estándar

	element = ft_lstnew(content);
	if (!element)
	{
		ft_putendl_fd("Error al crear el elemento.", fd);
		return (1);
	}
	ft_putstr_fd("El contenido del elemento es: ", fd);
	ft_putendl_fd((char *)element->content, fd);
	free(element); // No olvides liberar la memoria al final
	return (0);
}