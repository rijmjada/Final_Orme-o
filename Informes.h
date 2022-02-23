#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Validaciones.h"
#include "Participantes.h"
#include "LinkedList.h"


int menu();
void* informes_cargarPromedio(void* pElement);

int informe_filterTipo_Mx3(void* part);
int informe_filterTipo_Mx2(void* part);
int informe_filterTipo_Mx1(void* part);
int informe_filterTipo_SUPER_ATV(void* part);
int informe_ordenarPorCategoria(void* p1, void* p2);
int informe_ordenarPorPromedio(void* p1, void* p2);
#endif // INFORMES_H_INCLUDED
