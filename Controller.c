

#include "Controller.h"



int controller_LoadFromText(char* path, LinkedList* pList)
{
    int ret = ERROR;
    FILE* file = fopen(path,"r");

    if(path != NULL && pList != NULL)
    {
        if(parser_LoadFromText(file,pList) == ALLOK)
        {
            ret = ALLOK;
        }
    }
    fclose(file);

    return ret;
}

/** \brief Carga desde un archivo los datos
 *
 * \param path: ruta
 * \param pList: linkedlist
 * \return -1 : si alguno de los param es NULL
            1: si esta todo ok.
 *
 */
int controller_SaveAsText(char* path, LinkedList* pList)
{
    int ret = ERROR;
    FILE* file = fopen(path,"w");

    if(path != NULL && pList != NULL)
    {
        if(parser_SaveAsText(file,pList) == ALLOK)
        {
            ret = ALLOK;
        }
    }
    fclose(file);

    return ret;
}

int controller_Listar(LinkedList* pList)
{
    return part_mostrarListaParticipantes(pList);
}

LinkedList* controller_Promedios(LinkedList* pList)
{
    return ll_map(pList,informes_cargarPromedio);
}

int controller_FiltrarPorTipo(LinkedList* pList)
{
    int ret = ERROR;
    switch(menu_filter())
    {
    case 1:
        ret = controller_SaveAsText("MX1.txt",ll_filter(pList,informe_filterTipo_Mx1));
        break;
    case 2:
        ret = controller_SaveAsText("MX2.txt",ll_filter(pList,informe_filterTipo_Mx2));
        break;
    case 3:
        ret = controller_SaveAsText("MX3.txt",ll_filter(pList,informe_filterTipo_Mx3));
        break;
    case 4:
        ret = controller_SaveAsText("SUPER_ATV.txt",ll_filter(pList,informe_filterTipo_SUPER_ATV));
        break;
    }
    return ret;
}

int menu_filter()
{
    int ret = ERROR;

    printf("\n 1) Filter MX1.");
    printf("\n 2) Filter MX2.");
    printf("\n 3) Filter MX3.");
    printf("\n 4) Filter SUPER_ATV.");


    getInt(&ret,"\n\n Ingrese una opcion [1/4]: ","\n Dato invalido.Reingrese: ",1,4);

    return ret;
}


int controller_OrdenarYListar(LinkedList* pList)
{
    int ret = ERROR;
    if(ll_sort(pList,informe_ordenarPorCategoria,1) == ALLOK && ll_sort(pList,informe_ordenarPorPromedio,1) == ALLOK)
    {
        controller_Listar(pList);
        ret =  1;
    }
    return ret;
}
