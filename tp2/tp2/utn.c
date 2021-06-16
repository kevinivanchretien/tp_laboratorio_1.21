#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int utn_getInt(char* msg, char* msgError, int minimo, int maximo,int reintentos,int* entero)
{
    int retorno=-1;
    int auxi;
    if(msg!= NULL && msgError != NULL && minimo<=maximo && reintentos >=0 && entero != NULL)
    {
        do
        {
            printf("%s",msg);
            fflush(stdin);
            scanf("%d",&auxi);
            if(auxi<minimo || auxi >maximo)
            {
                reintentos--;
                printf("\n%s",msgError);
                fflush(stdin);
                scanf("%d",&auxi);
            }
            else
            {
                *entero=auxi;
                retorno=0;
                break;
            }

        }
        while(reintentos>=0);
    }
    return retorno;
}


int utn_getFloat(char* msg, char* msgError, int minimo, int maximo, int reintentos, float* flotante)
{
    int retorno=-1;
    float auxi;

    if(msg!=NULL && msgError!=NULL && minimo<maximo && reintentos>=0 && flotante!=NULL)
    {
        do
        {
            printf("%s",msg);
            fflush(stdin);
            scanf("%f",&auxi);
            if(auxi<minimo || auxi >maximo)
            {
                reintentos--;
                printf("\n %s Re%s",msgError,msg);
                fflush(stdin);
                scanf("%f",&auxi);
            }
            else
            {
                *flotante=auxi;
                retorno=0;
                break;
            }
        }
        while(reintentos>=0);
    }


    return retorno;
}



int utn_getName(char* msg, char* msgError, int minimo, int maximo, int* reintentos, char* palabra)
{
    int retorno=-1;
    char buffer[maximo];

    if(msg!=NULL && msgError!=NULL && minimo<=maximo && reintentos>=0 && palabra!=NULL)
    {
        do
        {
            printf("%s",msg);
            fflush(stdin);
            scanf("%s",buffer);

            if(strlen(buffer)>=minimo || strlen(buffer)<maximo)
            {
                strcpy(palabra,buffer);
                retorno=0;
                break;
            }
            else
            {
                printf(" \n %s ",msgError);
                (*reintentos)--;
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}
