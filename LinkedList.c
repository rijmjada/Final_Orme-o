
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* pList = (LinkedList*) malloc(sizeof(LinkedList));

    if(pList != NULL)
    {
        pList->pFirstNode = NULL;
        pList->size = 0;
    }
    return pList;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param pList LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* pList)
{
    int returnAux = -1;

    if(pList != NULL)
    {
        returnAux = pList->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param pList LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* pList, int nodeIndex)
{
    int len = ll_len(pList);
    Node* NodoAux = NULL;

    if(pList != NULL && nodeIndex >= 0 && nodeIndex < len)
    {
        NodoAux = pList->pFirstNode;
        while(nodeIndex > 0)
        {
            NodoAux = NodoAux->pNextNode;
            nodeIndex--;
        }
        /*for(int i=0; i<nodeIndex ; i++)
        {
            NodoAux = NodoAux->pNextNode;
            nodeIndex--;
        }*/
    }
    return NodoAux;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param pList LinkedList* Puntero a la lista
 * \param nodeIndex int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* pList, int nodeIndex)
{
    return getNode(pList,nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param pList LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* pList, int nodeIndex, void* pElement)
{
    int returnAux = -1;
    int len = ll_len(pList);
    Node* NuevoNodo = NULL;

    if(pList != NULL && nodeIndex >= 0 && nodeIndex <= len )
    {
        NuevoNodo = (Node*) malloc(sizeof(Node));
        if(NuevoNodo != NULL)
        {
            NuevoNodo->pElement = pElement;
            NuevoNodo->pNextNode = getNode(pList,nodeIndex);

            if(nodeIndex == 0)
            {
                pList->pFirstNode = NuevoNodo;
            }
            else
            {
                (getNode(pList,nodeIndex-1))->pNextNode = NuevoNodo;
            }
            pList->size++;
            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param pList LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* pList, int nodeIndex,void* pElement)
{
    return addNode(pList,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* pList, void* pElement)
{
    int returnAux = -1;
    int len = ll_len(pList);

    if(pList != NULL)
    {
        if(addNode(pList,len,pElement) == 0)
        {
            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief Devuelve el elemento guardado en la lista en el indice index
 *
 * \param pList LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* pList, int nodeIndex)
{
    void* returnAux = NULL;
    int len = ll_len(pList);

    if(pList != NULL && nodeIndex >= 0 && nodeIndex < len)
    {
        Node* nodoAux = getNode(pList,nodeIndex);
        if(nodoAux != NULL)
        {
            returnAux = nodoAux->pElement;
        }
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param pList LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* pList, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    int len = ll_len(pList);

    if(pList != NULL && nodeIndex >= 0 && nodeIndex < len)
    {
        Node* nodoAux = getNode(pList,nodeIndex);
        if(nodoAux != NULL)
        {
            nodoAux->pElement = pElement;
            returnAux = 0;
        }
    }

    return returnAux;
}


/** \brief Elimina un Nodo de la lista
 *
 * \param pList LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del Nodo a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* pList,int nodeIndex)
{
    int returnAux = -1;
    int len = ll_len(pList);
    Node* nodoAux = NULL;

    if(pList != NULL && nodeIndex >= 0 && nodeIndex < len)
    {
        nodoAux = getNode(pList,nodeIndex);
        if(nodeIndex == 0)
        {
            pList->pFirstNode = nodoAux->pNextNode;
        }
        else
        {
            (getNode(pList,nodeIndex-1))->pNextNode = nodoAux->pNextNode;
        }
        pList->size--;
        returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los Nodos de la lista
 *
 * \param pList LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* pList)
{
    int returnAux = -1;
    int len = ll_len(pList);

    if(pList != NULL)
    {
        for(int i=0; i<len; i++)
        {
            ll_remove(pList,i);
            free(getNode(pList,i));
        }
        returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina todos los Nodos de la lista y la lista
 *
 * \param pList LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* pList)
{
    int returnAux = -1;

    if(pList != NULL)
    {
        ll_clear(pList);
        pList = NULL;
        returnAux = 0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* pList, void* pElement)
{
    int returnAux = -1;
    int len = ll_len(pList);
    Node* NodoAux = NULL;

    if(pList != NULL)
    {
        NodoAux = pList->pFirstNode;
        for(int i=0; i<len; i++)
        {
            if(NodoAux->pElement == pElement)
            {
                returnAux = i;
                break;
            }
            NodoAux = NodoAux->pNextNode;
        }
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param pList LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* pList)
{
    int returnAux = -1;

    if(pList != NULL)
    {
        if(pList->pFirstNode != NULL)
        {
            returnAux = 0;
        }
        else
        {
            returnAux = 1;
        }
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param pList LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* pList, int nodeIndex, void* pElement)
{
    return addNode(pList,nodeIndex,pElement);
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param pList LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* pList,int nodeIndex)
{
    void* ptr = ll_get(pList,nodeIndex);
    if(ll_remove(pList,nodeIndex) == -1)
    {
        ptr = NULL;
    }
    return ptr;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* pList, void* pElement)
{
    int returnAux = -1;

    if(pList != NULL)
    {
        if(ll_indexOf(pList,pElement) == -1)
        {
            returnAux = 0;
        }
        else
        {
            returnAux = 1;
        }
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (pListB)
            estan contenidos en la lista (pListA)
 *
 * \param pListA LinkedList* Puntero a la lista
 * \param pListB LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (pListB) estan contenidos en la lista (pListA)
                        ( 0) si los elementos de (pListB) NO estan contenidos en la lista (pListA)
*/
int ll_containsAll(LinkedList* pListA,LinkedList* pListB)
{
    int returnAux = -1;
    int lenpListB = ll_len(pListB);
    void* pElement = NULL;

    if(pListA != NULL && pListB != NULL)
    {
        returnAux = 1; // Presumo que los contiene, caso contario cambio el ret.
        for(int i=0; i<lenpListB; i++)
        {
            pElement = ll_get(pListB,i);
            if(ll_contains(pListA,pElement) == 0)
            {
                returnAux = 0;
                break;
            }
        }
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* pList,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int lenpList = ll_len(pList);

    if(pList != NULL && from >= 0 && from <= lenpList && to > from && to <= lenpList)
    {
        cloneArray = ll_newLinkedList();
        if(cloneArray != NULL)
        {
            for(int i=from; i<to; i++)
            {
                ll_add(cloneArray,ll_get(pList,i));
            }
        }
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* pList)
{
    return  ll_subList(pList,0,ll_len(pList));
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* pList, int (*pFunc)(void*,void*), int order)
{
    int returnAux = ERROR;
    int len = ll_len(pList);
    void* auxI = NULL;
    void* auxJ = NULL;

    if(pList != NULL && pFunc != NULL && order >= 0 && order <= 1)
    {
        for(int i=0; i < len - 1; i++)
        {
            for(int j= i+1; j<len; j++)
            {
                auxI = ll_get(pList,i);
                auxJ = ll_get(pList,j);

                if((pFunc(auxI,auxJ) > 0 && order) ||
                        (pFunc(auxI,auxJ) < 0 && !order))
                {
                    ll_set(pList,i,auxJ);
                    ll_set(pList,j,auxI);
                }
            }
        }
        returnAux = ALLOK;
    }

    return returnAux;

}

/** \brief Retorna una nueva LinkedList con los valores filtrados por la funcion pFunc
 *
 * \param pList puntero a LinkedList original
 * \param pFunc Puntero a funcion que se encarga de determinar si el elemento pertenecera o no a la nueva Lista
 * \return puntero a nueva LinkedList
 *
 */

LinkedList* ll_filter(LinkedList* pList, int (*pFunc)(void*))
{
    LinkedList* pFilterList = NULL;
    int len;
    int flag = ERROR;
    void* aux = NULL;

    if(pList != NULL && pFunc != NULL)
    {
        pFilterList = ll_newLinkedList();
        if(pFilterList != NULL)
        {
            len = ll_len(pList);
            for(int i=0; i<len; i++)
            {
                aux = ll_get(pList,i);
                if(pFunc(aux) == ALLOK)
                {
                    ll_add(pFilterList,aux);
                    flag = ALLOK;
                }
            }
        }
        if(flag != ALLOK)
        {
            pFilterList = NULL;
        }
    }

    return pFilterList;
}


/** \brief Retorna una nueva LinkedList con los campos cargados aleatoriamente por la funcion pFunc.
 *
 * \param pList puntero a LinkedList original.
 * \param pFunc puntero a la funcion que se encargara de cargar aleatoriamente los campos de element.
 * \return puntero a una nueva LinkedList.
 *
 */

LinkedList* ll_map(LinkedList* pList, void*(*pFunc) (void* element))
{
    LinkedList* listaAux = NULL;
    int len = 0;
    void* pElement = NULL;


    if(pList != NULL && pFunc != NULL)
    {
        listaAux = ll_newLinkedList();

        if(listaAux != NULL)
        {
            len = ll_len(pList);

            for(int i=0; i<len; i++)
            {
               pElement = pFunc(ll_get(pList,i));

               if(pElement != NULL)
               {
                   if(ll_add(listaAux,pElement) != 0)
                   {
                       ll_deleteLinkedList(listaAux);
                       break;
                   }
               }
            }
        }
    }

    return listaAux;
}
