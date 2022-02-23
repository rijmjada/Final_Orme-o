#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



#define ERROR -1
#define ALLOK 1


int getInt(int *pResultado, char *pMensaje, char *pMensajeError, int minimo, int maximo);
int getChar(char *pResultado, char *pMensaje, char *pMensajeError, char minimo, char maximo);
int getString(char *pResultado, char *pMensaje, char *pMensajeError, int minimo, int maximo);
float getFloat(float *pResultado, char *pMensaje, char *pMensajeError, float minimo, float maximo);

#endif // VALIDACIONES_H_INCLUDED
