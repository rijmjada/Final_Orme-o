#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Parser.h"
#include "LinkedList.h"
#include "Informes.h"

int controller_LoadFromText(char* path, LinkedList* pList);
int controller_SaveAsText(char* path, LinkedList* pList);

int controller_Listar(LinkedList* pList);
LinkedList* controller_Promedios(LinkedList* pList);

int controller_FiltrarPorTipo(LinkedList* pList);
int menu_filter();

int controller_OrdenarYListar(LinkedList* pList);

#endif // CONTROLLER_H_INCLUDED
