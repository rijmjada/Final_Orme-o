
#include "Informes.h"

int menu()
{
    int ret = ERROR;

    printf("\n 1) Cargar archivo:.");
    printf("\n 2) Imprimir Lista.");
    printf("\n 3) Asignar promedios.");
    printf("\n 4) Filtrar por tipo.");
    printf("\n 5) Mostrar posiciones.");
    printf("\n 6) Guardar posiciones.");
    printf("\n 7) Salir.");

    getInt(&ret,"\n\n Ingrese una opcion [1/7]: ","\n Dato invalido.Reingrese: ",1,7);

    return ret;
}

void* informes_cargarPromedio(void* pElement)
{
    eParticipante* nuevoPart = NULL;
    eParticipante* partRef = (eParticipante*)pElement;
    if(pElement != NULL)
    {
        nuevoPart = part_new();

        part_setID(nuevoPart,partRef->id_cuatri);
        part_setNombre(nuevoPart,partRef->nombre);
        part_setCategoria(nuevoPart,partRef->categoria);
        part_setTiempo(nuevoPart,partRef->tiempo);

        if(partRef->tiempo < 15)
        {
            part_setPromedio(nuevoPart,6);
        }
        if(partRef->tiempo >= 15 && partRef->tiempo <= 20)
        {
            part_setPromedio(nuevoPart,8);
        }
        if(partRef->tiempo > 20)
        {
            part_setPromedio(nuevoPart,10);
        }
    }
    return nuevoPart;
}

int informe_filterTipo_SUPER_ATV(void* part)
{
    int ret = ERROR;
    eParticipante* parti = (eParticipante*)part;
    if(strcmp(parti->categoria,"SUPER_ATV") == 0)
    {
        ret = ALLOK;
    }
    return ret;
}

int informe_filterTipo_Mx3(void* part)
{
    int ret = ERROR;
    eParticipante* parti = (eParticipante*)part;
    if(strcmp(parti->categoria,"MX3") == 0)
    {
        ret = ALLOK;
    }
    return ret;
}

int informe_filterTipo_Mx2(void* part)
{
    int ret = ERROR;
    eParticipante* parti = (eParticipante*)part;
    if(strcmp(parti->categoria,"MX2") == 0)
    {
        ret = ALLOK;
    }
    return ret;
}

int informe_filterTipo_Mx1(void* part)
{
    int ret = ERROR;
    eParticipante* parti = (eParticipante*)part;
    if(strcmp(parti->categoria,"MX1") == 0)
    {
        ret = ALLOK;
    }
    return ret;
}

int informe_ordenarPorCategoria(void* p1, void* p2)
{
    int ret = ERROR;
    eParticipante* part1 = (eParticipante*)p1;
    eParticipante* part2 = (eParticipante*)p2;
    if(part1 != NULL && part2 != NULL)
    {
        if(strcmp(part1->categoria,part2->categoria) > 0)
        {
            ret = 1;
        }
    }
    return ret;
}

int informe_ordenarPorPromedio(void* p1, void* p2)
{
    int ret = ERROR;
    eParticipante* part1 = (eParticipante*)p1;
    eParticipante* part2 = (eParticipante*)p2;
    if(part1 != NULL && part2 != NULL)
    {
        if(strcmp(part1->categoria,part2->categoria) == 0 && part1->promedio > part2->promedio)
        {
            ret = 1;
        }
    }
    return ret;
}
