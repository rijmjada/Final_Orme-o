
#include "Parser.h"

int parser_LoadFromText(FILE* pFile, LinkedList* pList)
{

    int ret = ERROR;
    char buffer[5][65];
    int cant = 0;
    eParticipante* part = NULL;

    if(pFile != NULL && pList != NULL)
    {
        // Lectura fantasmaca (encabezado)
        fscanf(pFile,"%[^,], %[^,], %[^,], %[^,], %[^\n]\n",
               buffer[0],
               buffer[1],
               buffer[2],
               buffer[3],
               buffer[4]);

        while(!feof(pFile))
        {
            cant = fscanf(pFile,"%[^,], %[^,], %[^,], %[^,], %[^\n]\n",
                          buffer[0], // id(int)
                          buffer[1], // nombre(char*)
                          buffer[2], // categoria (char*)
                          buffer[3], // tiempo (int)
                          buffer[4]);// promedio (float)

            if(cant < 5) //cantidad de campos que pudo leer.
            {
                break;
            }
            else
            {
                part = part_Parametros(buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);

                if(part != NULL)
                {
                    ll_add(pList,part);
                    ret = ALLOK;
                }
            }
        }
    }
    return ret;
}

int parser_SaveAsText(FILE* pFile, LinkedList* pList)
{
    int ret = ERROR;
    int len = ll_len(pList);
    eParticipante* part = NULL;

    if(pFile != NULL && pList != NULL)
    {
        // Ecanbezado
        fprintf(pFile,"ID ,       Nombre ,  Categoria ,  Tiempo , Promedio\n");
        for(int i=0; i<len; i++)
        {

            part = (eParticipante*)ll_get(pList,i);

            if(part != NULL)
            {
                fprintf(pFile,"%2d ,%12s ,%12s ,%8d ,%8.2f \n",
                        part->id_cuatri,
                        part->nombre,
                        part->categoria,
                        part->tiempo,
                        part->promedio
                       );
                ret = ALLOK;
            }
        }
    }

    return ret;
}
