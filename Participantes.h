#ifndef PARTICIPANTES_H_INCLUDED
#define PARTICIPANTES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define ERROR -1
#define ALLOK 1

#include "LinkedList.h"

typedef struct
{
    int id_cuatri;
    char nombre[24];
    char categoria[24];
    int tiempo;
    float promedio;

}eParticipante;

eParticipante* part_new();
eParticipante* part_Parametros(char* id, char* nombre, char* categoria, char* tiempo, char* promedio);
void part_delete(eParticipante* p);

// SETTERS
int part_setID(eParticipante* part, int id);
int part_setNombre(eParticipante* part, char* nombre);
int part_setCategoria(eParticipante* part, char* cate);
int part_setTiempo(eParticipante* part, int time);
int part_setPromedio(eParticipante* part, float promedio);

// GETTERS
int part_getID(eParticipante* part, int* id);
int part_getNombre(eParticipante* part, char* nombre);
int part_getCategoria(eParticipante* part, char* cate);
int part_getTiempo(eParticipante* part, int* time);
int part_getPromedio(eParticipante* part, float* promedio);

// PRINTF

int part_mostrarUnParticipante(eParticipante* part);
int part_mostrarListaParticipantes(LinkedList* pList);
void part_encabezado();


#endif // PARTICIPANTES_H_INCLUDED
