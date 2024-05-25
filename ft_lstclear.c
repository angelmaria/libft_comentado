#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *)) // toma dos parámetros: un doble puntero a t_list y un puntero a una función del.
{
	t_list	*curr; // Declara un puntero a t_list para usarlo como variable actual en el bucle.

	if (!lst || !(*lst) || !del) // Comprueba si alguno de los parámetros es NULL. Si es así, sale de la función.
		return ;
	while (*lst != NULL) // Mientras la lista no esté vacía...
	{
		curr = *lst; // Establece curr como el primer elemento de la lista.
		*lst = (*lst)->next; // Avanza lst al siguiente elemento de la lista.
		ft_lstdelone(curr, del); // Llama a ft_lstdelone para eliminar y liberar la memoria del elemento actual, usando la función del.
	}
}
/* La función del es un puntero a otra función que se encarga de liberar la memoria del contenido de cada nodo de la lista. Esto permite que ft_lstclear sea flexible y pueda manejar listas de diferentes tipos de datos, ya que el usuario puede proporcionar su propia función de eliminación adaptada al tipo de datos que contiene la lista.

En resumen, ft_lstclear recorre la lista enlazada y elimina cada nodo utilizando la función del proporcionada por el usuario, liberando así toda la memoria asociada con la lista. Es importante que la función del esté bien definida para evitar fugas de memoria. */
// Test
// Función auxiliar para liberar el contenido de un nodo
void del(void *content)
{
    free(content);
}

// Función auxiliar para imprimir el contenido de un nodo
void print_list(t_list *lst)
{
    while (lst)
    {
        printf("%s\n", (char *)lst->content);
        lst = lst->next;
    }
}

int main(void)
{
    t_list *head;
    t_list *node1;
    t_list *node2;

    // Crear y asignar valores a los nodos
    node1 = ft_lstnew(strdup("Hola"));
    node2 = ft_lstnew(strdup("Mundo"));

    // Enlazar los nodos
    head = node1;
    node1->next = node2;

    // Imprimir la lista antes de limpiarla
    printf("Lista antes de ft_lstclear:\n");
    print_list(head);

    // Limpiar y liberar la lista
    ft_lstclear(&head, del);

    // Intentar imprimir la lista después de limpiarla
    printf("Lista después de ft_lstclear:\n");
    if (head == NULL)
        printf("La lista ha sido eliminada correctamente.\n");

    return 0;
}