#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *)) // ft_lstmap toma tres parámetros: un puntero al primer nodo de la lista enlazada original, un puntero a una función que se aplicará a cada contenido de los nodos de la lista y un puntero a una función que se usará para liberar la memoria del conetenido de los nodos si es necesario.  
{
	t_list	*lst2;
	t_list	*node;

	lst2 = NULL; // Se inicializa un puntero lst2 a NULL para empezar a construir la nueva lista.
	if (!lst || !f || !del) // Se verifica si alguno de los punteros lst, f, o del es NULL. Si alguno lo es, la función termina y devuelve NULL.
		return (NULL);
	while (lst != NULL) // Se itera sobre cada nodo de la lista lst. Igual que "while (lst)""
	{
		node = ft_lstnew(f(lst->content)); // Se aplica la función f al contenido del nodo actual y se crea un nuevo nodo con ft_lstnew con el resultado de f.
		if (!node)
		{
			ft_lstclear(&lst, del); // Si la creación del nuevo nodo falla (por ejemplo, si no hay suficiente memoria), se libera toda la nueva lista creada hasta el momento con ft_lstclear y se devuelve NULL.
			return (NULL);
		}
		ft_lstadd_back(&lst2, node); // Si el nodo se crea con éxito, se añade al final de la nueva lista lst2 con ft_lstadd_back.
		lst = lst->next; // Se avanza al siguiente nodo de la lista original.

	}
	return (lst2); // Una vez terminado el bucle, se devuelve la nueva lista lst2.
}
// Esta función es útil cuando quieres transformar los contenidos de una lista enlazada sin modificar la lista original. Es importante asegurarse de que las funciones 'f' y 'del' estén bien definidas para evitar fugas de memoria o comportamientos inesperados.
/* 
El segundo parámetro de la función ft_lstmap tiene un propósito importante en el contexto de la creación de una nueva lista a partir de una lista original. Permíteme explicarte:

La función ft_lstmap se utiliza para crear una nueva lista a partir de los elementos de una lista original. La nueva lista contendrá copias de los elementos transformados por la función que se pasa como primer parámetro (f).
El segundo parámetro (del) es un puntero a una función que se utiliza para liberar la memoria asignada a los elementos de la nueva lista en caso de que ocurra un error durante la creación de la lista. Esto es importante para evitar fugas de memoria.
Aunque la función ft_lstmap no modifica directamente la lista original, puede haber situaciones en las que ocurran errores al crear la nueva lista (por ejemplo, si no se puede asignar memoria para un nuevo nodo). En tales casos, la función del se invoca para liberar la memoria asignada a los elementos transformados antes de que la nueva lista sea completamente destruida.
En resumen, el segundo parámetro (del) es crucial para garantizar la gestión adecuada de la memoria y prevenir posibles fugas de memoria durante la creación de la nueva lista. Aunque no afecta directamente a la lista original, su papel es fundamental para mantener la integridad del programa
*/
// Test (borrar)
// Función para duplicar el contenido de un nodo.
void *duplicate_content(void *content)
{
    int *new_content = malloc(sizeof(int));
    if (!new_content)
        return (NULL);
    *new_content = *(int *)content * 2; // Duplicamos el valor.
    return (new_content);
}

// Función para liberar la memoria del contenido de un nodo.
void del_content(void *content)
{
    free(content);
}

int main(void)
{
    t_list *list = NULL;
    t_list *new_list = NULL;
    int values[] = {1, 2, 3, 4, 5}; // Valores para la lista original.
    int i;

    // Crear y llenar la lista original.
    for (i = 0; i < 5; i++)
    {
        ft_lstadd_back(&list, ft_lstnew(&values[i]));
    }

    // Aplicar ft_lstmap a la lista.
    new_list = ft_lstmap(list, duplicate_content, del_content);

    // Imprimir la lista nueva.
    while (new_list != NULL)
    {
        printf("%d\n", *(int *)new_list->content);
        new_list = new_list->next;
    }

    // Liberar ambas listas.
    ft_lstclear(&list, del_content);
    ft_lstclear(&new_list, del_content);

    return (0);
}