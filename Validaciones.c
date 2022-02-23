
#include "Validaciones.h"

int getInt(int *pResultado, char *pMensaje, char *pMensajeError, int minimo, int maximo)
{
    int retorno = ERROR;
    int buffer = 0;

    if(pResultado != NULL && pMensaje != NULL && pMensajeError != NULL && minimo < maximo)
    {
         printf("%s",pMensaje);
        do
        {
            fflush(stdin);

            if(scanf("%d",&buffer) == 1)
            {
                if(buffer >= minimo && buffer <= maximo)
                {
                    retorno = ALLOK;
                    *pResultado = buffer;
                    break;
                }
            }
            printf("%s",pMensajeError);
        }
        while(retorno);

    }
    return retorno;
}

int getChar(char *pResultado, char *pMensaje, char *pMensajeError, char minimo, char maximo)
{
    int retorno = ERROR;
    char buffer;

    if(pResultado != NULL && pMensaje != NULL && pMensajeError != NULL && minimo < maximo)
    {
        printf("%s",pMensaje);
        do
        {
            fflush(stdin);

            if(scanf("%c",&buffer) == 1)
            {
                if(buffer >= minimo && buffer <= maximo)
                {
                    retorno = ALLOK;
                    *pResultado = buffer;
                    break;
                }
            }
            printf("%s",pMensajeError);
        }
        while(retorno);

    }
    return retorno;
}

int isChar(char *pResultado, char *pMensaje, char *pMensajeError)
{
    int retorno = ERROR;
    char letra;

    if(pResultado != NULL && pMensaje != NULL && pMensajeError)
    {
        printf("%s",pMensaje);
        do
        {
            fflush(stdin);
            scanf("%c", &letra);
            if(isalpha(letra))
            {
                retorno = ALLOK;
                *pResultado = letra;
                letra = tolower(letra);
                break;
            }
            printf("%s",pMensajeError);
        }
        while(retorno);
    }
    return retorno;
}


int getString(char *pResultado, char *pMensaje, char *pMensajeError, int minimo, int maximo)
{
    int retorno = ERROR;
    char buffer[500];

    if(pResultado != NULL && pMensaje != NULL && pMensajeError != NULL && minimo < maximo)
    {
        printf("%s",pMensaje);
        do
        {
            fflush(stdin);
            fgets(buffer,sizeof(buffer),stdin);
            buffer[strlen(buffer)-1] = '\0';
            if(strlen(buffer)>=minimo && strlen(buffer)<=maximo)
            {
                strncpy(pResultado,buffer,maximo+1);
                retorno = ALLOK;
                break;
            }
            printf("%s",pMensajeError);
        }
        while(retorno);
    }
    return retorno;
}

float getFloat(float *pResultado, char *pMensaje, char *pMensajeError, float minimo, float maximo)
{
    int retorno = ERROR;
    float buffer;

    if(pResultado != NULL && pMensaje != NULL && pMensajeError != NULL && minimo < maximo)
    {
        printf("%s",pMensaje);
        do
        {
            fflush(stdin);

            if(scanf("%f",&buffer) == 1)
            {
                if(buffer >= minimo && buffer <= maximo)
                {
                    retorno = ALLOK;
                    *pResultado = buffer;
                    break;
                }
            }
            printf("%s",pMensajeError);
        }
        while(retorno);

    }
    return retorno;
}

