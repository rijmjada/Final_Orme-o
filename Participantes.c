
#include "Participantes.h"

eParticipante* part_new()
{
    eParticipante* part = (eParticipante*) malloc(sizeof(eParticipante));

    if(part != NULL)
    {
        part->id_cuatri = 0;
        strcpy(part->nombre,"");
        strcpy(part->categoria,"");
        part->tiempo = 0;
        part->promedio = 0;
    }
    return part;
}

eParticipante* part_Parametros(char* id, char* nombre, char* categoria, char* tiempo, char* promedio)
{
    eParticipante* part = NULL;

    if(id != NULL && nombre != NULL && categoria != NULL && tiempo != NULL && promedio != NULL)
    {
        part = part_new();
        if(part != NULL)
        {
            if(!(
                        part_setID(part,atoi(id)) &&
                        part_setNombre(part,nombre) &&
                        part_setCategoria(part,categoria) &&
                        part_setTiempo(part,atoi(tiempo)) &&
                        part_setPromedio(part,atof(promedio))
                    ))
            {
                part_delete(part);
            }
        }
    }
    return part;
}

void part_delete(eParticipante* p)
{
    free(p);
}

// SETTERS
int part_setID(eParticipante* part, int id)
{
    int ret = ERROR;
    if(part != NULL && id >= 0)
    {
        part->id_cuatri = id;
        ret = ALLOK;
    }
    return ret;
}

int part_setNombre(eParticipante* part, char* nombre)
{
    int ret = ERROR;
    if(part != NULL && nombre != NULL)
    {
        strcpy(part->nombre,nombre);
        ret = ALLOK;
    }
    return ret;
}

int part_setCategoria(eParticipante* part, char* cate)
{
    int ret = ERROR;
    if(part != NULL && cate != NULL)
    {
        strcpy(part->categoria,cate);
        ret = ALLOK;
    }
    return ret;
}

int part_setTiempo(eParticipante* part, int time)
{
    int ret = ERROR;
    if(part != NULL && time >= 0)
    {
        part->tiempo = time;
        ret = ALLOK;
    }
    return ret;
}

int part_setPromedio(eParticipante* part, float promedio)
{
    int ret = ERROR;
    if(part != NULL && promedio >= 0)
    {
        part->promedio = promedio;
        ret = ALLOK;
    }
    return ret;
}

// GETTERS

int part_getID(eParticipante* part, int* id)
{
    int ret = ERROR;
    if(part != NULL && id >= 0)
    {
        *id = part->id_cuatri;
        ret = ALLOK;
    }
    return ret;
}

int part_getNombre(eParticipante* part, char* nombre)
{
    int ret = ERROR;
    if(part != NULL && nombre != NULL)
    {
        strcpy(nombre,part->nombre);
        ret = ALLOK;
    }
    return ret;
}

int part_getCategoria(eParticipante* part, char* cate)
{
    int ret = ERROR;
    if(part != NULL && cate != NULL)
    {
        strcpy(cate,part->categoria);
        ret = ALLOK;
    }
    return ret;
}

int part_getTiempo(eParticipante* part, int* time)
{
    int ret = ERROR;
    if(part != NULL && time >= 0)
    {
        *time = part->tiempo;
        ret = ALLOK;
    }
    return ret;
}

int part_getPromedio(eParticipante* part, float* promedio)
{
    int ret = ERROR;
    if(part != NULL && promedio >= 0)
    {
        *promedio = part->promedio;
        ret = ALLOK;
    }
    return ret;
}

//PRINT
int part_mostrarUnParticipante(eParticipante* part)
{
    int ret = ERROR;

    if(part != NULL)
    {
        printf("\n|   %3d   |   %12s   |   %12s   |   %6d   |   %6.2f   |",
               part->id_cuatri,
               part->nombre,
               part->categoria,
               part->tiempo,
               part->promedio);

        ret= ALLOK;
    }

    return ret;
}

int part_mostrarListaParticipantes(LinkedList* pList)
{
    int ret = ERROR;
    int len;
    eParticipante* part = NULL;

    if(pList != NULL)
    {
        len = ll_len(pList);

        part_encabezado();

        for(int i=0; i<len; i++)
        {
            part = ll_get(pList,i);
            part_mostrarUnParticipante(part);
        }
        ret = ALLOK;
    }
    if(len == 0)
    {
        printf("\n No hay participantes para mostrar.");
    }
    printf("\n-------------------------------------------------------------------");

    return ret;
}

void part_encabezado()
{
    system("cls");
    printf("\n|   ID    |      Nombre      |    Categoria     |    Tiempo  |  Promedio  |");
    printf("\n-----------------------------------------------------------------------------");
}
