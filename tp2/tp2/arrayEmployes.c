#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployes.h"


//INICIA EL CAMPO isEmpty para que todas las posiciones estes vacias
int initEmployee(Employee* list,int len)
{
    int retorno =-1;
    int i;
    if(list !=NULL && len >0)
    {
        for(i=0; i<len; i++)
        {
            list[i].isEmpty=1;
        }
        retorno =0;
    }
    return retorno;
}


int addEmployee(Employee* list,int len, int idEmpleado, char* nombre,char* apellido,float sueldo,int sector)
{
    int retorno =-1;
    int posicion;

    if(list!= NULL && len>=0&& nombre!= NULL && apellido!=NULL)
    {
        if(employee_buscarIsEmpty(list,len,&posicion)==-1)
        {
            printf("\nNo hay mas lugares libres.\n");
            system("pause");
        }
        else
        {
            list[posicion].id=idEmpleado;
            strcpy(list[posicion].nombre,nombre);
            strcpy(list[posicion].apellido,apellido);
            list[posicion].salario=sueldo;
            list[posicion].sector=sector;
            list[posicion].isEmpty=0;

            //mostrar empleado.

            retorno=0;
        }

    }
    return retorno;
}



int employee_buscarIsEmpty(Employee* list,int tam,int* posicion)
{
    int retorno=-1;
    int i;
    if(list!= NULL && tam>0)
    {
        for(i=0; i<tam; i++)
        {
            if(list[i].isEmpty==1)
            {
                *posicion=i;
                retorno =0;
                break;
            }
        }
    }
    return retorno;
}

int printEmployee(Employee* list, int length)
{
    int retorno=-1;
    int i;
    //int posicion;
    if(list != NULL && length >=0)
    {
        retorno =0;
        printf("_ID___|_NOMBRE___|_APELLIDO____|_SUELDO____|_SECTOR__");
        for(i=0; i<length; i++)
        {
            if(list[i].isEmpty==0)
            {
                printf("\n  %d    %s,  %s,  %.2f,  %d   ",
                       list[i].id,
                       list[i].nombre,
                       list[i].apellido,
                       list[i].salario,
                       list[i].sector);

            }
        }
        system("pause");
    }
    return retorno;
}

int findEmployee(Employee* list,int len,int id)
{
    int retorno =-1;
    int i;
    if(list != NULL && len >0&& id>0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].id==id)
            {
                retorno=i;
                break;
            }
        }

    }
    return retorno;
}


int removeEmployee(Employee* list, int len, int id)
{
    int retorno=-1;
    int auxPosicion;
    char resp;
    int i;
    if(list != NULL && len >0 && id>=0)
    {
        auxPosicion=findEmployee(list,len,id);

        printf("\n Se borraran los siguientes datos");
        mostrar_unEmpleado(list,len,auxPosicion);

        printf("\n\nEsta seguro de querer borrar los datos (s/n)?: ");
        fflush(stdin);
        scanf("%c",&resp);
        if(resp=='s')
        {
            for(i=0; i<len; i++)
            {
                if(list[i].id == id)
                {
                    list[i].isEmpty=1;
                    retorno=0;
                    break;
                }
            }
        }
    }
    return retorno;
}

int mostrar_unEmpleado(Employee* list,int len,int posicion)
{
    int retorno=-1;
    if(list != NULL && len>0 && (posicion >=0 || posicion<=len))
    {
        printf("\n|_ID__|____NOMBRE___|___APELLIDO___|___SUELDO___|_SECTOR__");
        printf("\n| %d   |   %s     |  %s    |  %2.f    |  %d",list[posicion].id,
               list[posicion].nombre,
               list[posicion].apellido,
               list[posicion].salario,
               list[posicion].sector);
        retorno=0;
    }
    return retorno;
}

int sortEmployees(Employee* list, int len, int order)
{
    int retorno=-1;
    int i,j;

    //int flagSwap=-1;
    int auxID=0;
    char auxNombre[50];
    char auxApellido[50];
    float auxSueldo=0;
    int  auxSector=0;

    if(list != NULL && len >0 && (order==0 || order==1))
    {
        switch(order)
        {
        case 0:
            for(i=0; i<len-1; i++)
            {
                for(j=i+1; j<len; j++)
                {
                    if(list[i].isEmpty==0 && list[j].isEmpty==0)
                    {
                        if(strcmp(list[i].apellido,list[j].apellido)>0)//de Menor a Mayor
                        {
                            auxID=list[i].id;
                            list[i].id=list[j].id;
                            list[j].id=auxID;

                            strcpy(auxNombre,list[i].nombre);
                            strcpy(list[i].nombre,list[j].nombre);
                            strcpy(list[j].nombre,auxNombre);

                            strcpy(auxApellido,list[i].apellido);
                            strcpy(list[i].apellido,list[j].apellido);
                            strcpy(list[j].apellido,auxApellido);

                            auxSueldo=list[i].salario;
                            list[i].salario=list[j].salario;
                            list[j].salario=auxSueldo;

                            auxSector=list[i].sector;
                            list[i].sector=list[j].sector;
                            list[j].sector=auxSector;
                        }
                        else if(strcmp(list[i].apellido,list[j].apellido)==0)
                        {
                            if(list[i].sector>=list[j].sector)
                            {
                                auxID=list[i].id;
                                list[i].id=list[j].id;
                                list[j].id=auxID;

                                strcpy(auxNombre,list[i].nombre);
                                strcpy(list[i].nombre,list[j].nombre);
                                strcpy(list[j].nombre,auxNombre);

                                strcpy(auxApellido,list[i].apellido);
                                strcpy(list[i].apellido,list[j].apellido);
                                strcpy(list[j].apellido,auxApellido);

                                auxSueldo=list[i].salario;
                                list[i].salario=list[j].salario;
                                list[j].salario=auxSueldo;

                                auxSector=list[i].sector;
                                list[i].sector=list[j].sector;
                                list[j].sector=auxSector;
                            }
                        }
                    }
                }
            }

            break;
        case 1:
            printf("\nOrdenamiento de MAYOR A MENOR\n");
            for(i=0; i<len-1; i++)
            {
                for(j=i+1; j<len; j++)
                {
                    if(list[i].isEmpty==0 && list[j].isEmpty==0)
                    {
                        if(strcmp(list[i].apellido,list[j].apellido)<0)//de Mayor a Menor
                        {

                            auxID=list[i].id;
                            list[i].id=list[j].id;
                            list[j].id=auxID;

                            strcpy(auxNombre,list[i].nombre);
                            strcpy(list[i].nombre,list[j].nombre);
                            strcpy(list[j].nombre,auxNombre);

                            strcpy(auxApellido,list[i].apellido);
                            strcpy(list[i].apellido,list[j].apellido);
                            strcpy(list[j].apellido,auxApellido);

                            auxSueldo=list[i].salario;
                            list[i].salario=list[j].salario;
                            list[j].salario=auxSueldo;

                            auxSector=list[i].sector;
                            list[i].sector=list[j].sector;
                            list[j].sector=auxSector;

                        }
                        else if(strcmp(list[i].apellido,list[j].apellido)==0)
                        {
                            if(list[i].sector<=list[j].sector)
                            {
                                auxID=list[i].id;
                                list[i].id=list[j].id;
                                list[j].id=auxID;

                                strcpy(auxNombre,list[i].nombre);
                                strcpy(list[i].nombre,list[i+1].nombre);
                                strcpy(list[i+1].nombre,auxNombre);

                                strcpy(auxApellido,list[i].apellido);
                                strcpy(list[i].apellido,list[j].apellido);
                                strcpy(list[j].apellido,auxApellido);

                                auxSueldo=list[i].salario;
                                list[i].salario=list[j].salario;
                                list[j].salario=auxSueldo;

                                auxSector=list[i].sector;
                                list[i].sector=list[j].sector;
                                list[j].sector=auxSector;
                            }
                        }
                    }
                }
            }
            break;

        }
        retorno=0;
    }
    return retorno;
}


int promedioEmployees(Employee* list, int len)
{
    int retorno=-1;
    int i,j;
    float acumSueldo;
    float Resultado;
    int cont=0;
    int posicion;
    int fantasmaId=0;
    if(list!= NULL && len >0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty==0)
            {
                acumSueldo=acumSueldo+list[i].salario;
                cont++;
            }
        }
        Resultado=acumSueldo/cont;
        printf("Total %.2f \n Sueldo promedio: %.2f",acumSueldo,Resultado);
        printf("\nEstas personas superan el sueldo promedio:");
        for(j=0; j<len; j++)
        {
            if(list[j].salario>Resultado)
            {
                fantasmaId=buscarid_Employee(list,len,j);
                posicion=findEmployee(list,len,fantasmaId);
                mostrar_unEmpleado(list,len,posicion);
                system("pause");
            }
        }

        retorno=0;
    }
    return retorno;
}


int buscarid_Employee(Employee* list,int len,int posicion)
{
    int retorno=-1;
    int i;
    if(list != NULL && len>=0)
    {
        for(i=0; i<len; i++)
        {
            if(i==posicion)
            {
                retorno=list[i].id;
                break;
            }
        }
    }
    return retorno;
}


void harcodeoEmpleados(Employee* list)
{
    if(list != NULL)
    {
        list[0].id=1;
        strcpy(list[0].nombre,"melchor");
        strcpy(list[0].apellido,"perez");
        list[0].salario=35800.00;
        list[0].sector=3;
        list[0].isEmpty=0;

        list[1].id=2;
        strcpy(list[1].nombre,"gaspar");
        strcpy(list[1].apellido,"perez");
        list[1].salario=65000.00;
        list[1].sector=2;
        list[1].isEmpty=0;

        list[2].id=3;
        strcpy(list[2].nombre,"baltazar");
        strcpy(list[2].apellido,"gomez");
        list[2].salario=1500.00;
        list[2].sector=3;
        list[2].isEmpty=0;

    }
    return;
}


int ModEmployee(Employee* list, int len, int id)
{
    int retorno=-1;
    int posicion;
    int opcion;
    char submenu='n';

    if(list!= NULL && len>0 && id<=len)
    {
        posicion=findEmployee(list,len,id);
        if(posicion==-1)
        {
            printf("\n el id ingresado no existe.");
        }
        else
        {
            do
            {
                mostrar_unEmpleado(list,len,posicion);
                printf("\n\n Elija la opcion que desea modificar.\n\n");

                printf("1-Nombre\n2-Apellido.\n3-Salario.\n4-Sector.\n5- <-[menu principal]\n\n");
                fflush(stdin);
                scanf("%d",&opcion);

                switch(opcion)
                {
                case 1:
                    printf("1- Nuevo Nombre: ");
                    fflush(stdin);
                    gets(list[posicion].nombre);
                    break;
                case 2:
                    printf("2-Nuevo Apellido: ");
                    fflush(stdin);
                    gets(list[posicion].apellido);
                    break;
                case 3:
                    printf("3-Nuevo Salario: ");
                    fflush(stdin);
                    scanf("%f",&list[posicion].salario);
                    break;
                case 4:
                    printf("4-Nuevo Sector: ");
                    fflush(stdin);
                    scanf("%d",&list[posicion].sector);
                    break;
                case 5:
                    printf("\nvolver al menu principal (s/n): ");
                    fflush(stdin);
                    scanf("%c",&submenu);
                    break;
                default:
                    printf("opcion invalida");
                    break;
                }
            }
            while(submenu!='s');
        }
    }
    return retorno;
}
