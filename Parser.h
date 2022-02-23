#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Validaciones.h"
#include "LinkedList.h"
#include "Participantes.h"


int parser_LoadFromText(FILE* pFile, LinkedList* pList);
int parser_SaveAsText(FILE* pFile, LinkedList* pList);

#endif // PARSER_H_INCLUDED
