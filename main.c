#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "Controller.h"
#include "LinkedList.h"
#include "Parser.h"
#include "Validaciones.h"
#include "Participantes.h"
#include "Informes.h"

#define ERROR -1
#define ALLOK 1


int main()
{
    char seguir = 's';
    char archivo[20];
    int flag = 0;
    int flagEstadisticas = 0;
    LinkedList* pList = ll_newLinkedList();
    LinkedList* pMapList = NULL;

    do
    {
        switch(menu())
        {
        case 1:
            if(!flag)
            {
                getString(archivo,"\nIngrese nombre de archivo [enduro.csv]: ","\nreingrese:",4,18);

                if(controller_LoadFromText(archivo,pList) == ALLOK)
                {
                    printf("\nSe cargo el archivo correctamente.");
                    flag = 1;
                }
                else
                {
                    printf("\nError al intetntar leer el archivo!!.");
                }
            }
            else
            {
                printf("\nSolo puede cargar 1 vez el archivo.");
            }

            break;

        case 2:

            if(flag)
            {
                if(flagEstadisticas)
                {
                    controller_Listar(pMapList);
                }
                else
                {
                    controller_Listar(pList);
                }
            }
            else
            {
                printf("\nPrimero debe cargar el arhcivo.");
            }
            break;

        case 3:
            if(flag)
            {
                pMapList = controller_Promedios(pList);
                if(pMapList != NULL)
                {
                    printf("\nSe genero una nueva lista enlazada!.");
                    flagEstadisticas = 1;
                }
                else
                {
                    printf("\nError en el proceso!.");
                }
            }
            else
            {
                printf("\nPrimero debe cargar el arhcivo.");
            }
            break;

        case 4:
            if(flag && flagEstadisticas)
            {
                if(controller_FiltrarPorTipo(pMapList) == ALLOK)
                {
                    printf("\nSe genero un nuevo archivo .txt");
                }
            }
            else
            {
                printf("\nPrimero debe cargar el arhcivo y luego cargar promedios.");
            }
            break;

        case 5:
            if(flag && flagEstadisticas)
            {
                 if(controller_OrdenarYListar(pMapList) == ALLOK)
                 {
                     printf("\nLista ordenada.");
                 }
            }
            else
            {
                printf("\nPrimero debe cargar el arhcivo y luego cargar promedios.");
            }
            break;

        case 6:
            if(flag && flagEstadisticas)
            {
                if(controller_SaveAsText("posiciones.txt",pMapList) == ALLOK)
                {
                    printf("\nSe genero el arhcivo posiciones.txt.");
                }
            }
            else
            {
                printf("\nPrimero debe cargar el arhcivo y luego cargar promedios.");
            }

            break;

        case 7:
           printf("\n Saliendo...");
           seguir = 'n';
            break;

        case 8:

            break;
        }
        printf("\n\n");
        system("pause");
        system("cls");
    }
    while(seguir == 's');


    return 0;
}
