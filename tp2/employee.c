#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"

#define EMPLOYEE_H_INCLUDED


int initEmployees(struct Empleado arrayEmpleado[], int tam,int* posicion)
{
    int retorno=-1;
    int i;
    if(arrayEmpleado != NULL && tam >0 && posicion != NULL)
    {
        for(i=0; i<tam; i++)
        {
            if(arrayEmpleado[i].isEmpty==1)
            {
                *posicion=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

int addEmployee(struct Empleado arrayEmpleado[], int tam, int *contadorId, char name[],char lastName[],float salary,int sector)
{

    int retorno= -1;
    int posicion;
    if(arrayEmpleado != NULL && tam>0 && contadorId != NULL && name != NULL && lastName !=NULL &&salary>0 )
    {
        if(initEmployees(arrayEmpleado,tam,&posicion)==0)
        {
            (*contadorId)++;
            strcpy(arrayEmpleado[posicion].nombre,name);
            strcpy(arrayEmpleado[posicion].apellido,lastName);
            arrayEmpleado[posicion].sueldo=salary;
            arrayEmpleado[posicion].sector=sector;
            arrayEmpleado[posicion].id=*contadorId;
            arrayEmpleado[posicion].isEmpty =0;

            retorno=0;
        }
        else
        {
            printf("no hay lugares vacios");
        }
    }
    return retorno;
}


int findEmployeeById(struct Empleado arrayEmpleado[], int len,int buscarId,int* posicion)
{
    int i;
    int retorno;
    if(arrayEmpleado != NULL && len >0)
    {
        for(i=0; i<len; i++)
        {
            if(arrayEmpleado[i].isEmpty==0)
                continue;

            else if(arrayEmpleado[i].isEmpty==buscarId)
            {
                retorno =0;
                *posicion=i;
            }
        }
    }
    return retorno;
}


//elimina los datos de un empleado isEmpty en -1
int removeEmployee(struct Empleado arrayEmpleado[], int len, int id)
{
    int i;
    for(i=0; i<len; i++)
    {
        arrayEmpleado[id].isEmpty=1;

    }
    return;
}

//ordena los empleados
int sortEmployees(struct Empleado arrayEmpleado[], int len, int orden)
{
    int i,j;
    struct Empleado aux[len];

    for(i=0;i<len-1;i++)
    {
        if (arrayEmpleado[i].isEmpty == 0 )
        {
            continue;
        }
        for(j=i+1;j <len;j ++)
        {
            if (arrayEmpleado[j]. isEmpty == 0 )
            {
                continue;
            }

            if(orden==1)
            {
                if ( strcmp ( arrayEmpleado[i].apellido, arrayEmpleado[j].apellido)>0)
                {
                    aux= arrayEmpleado [i];
                    arrayEmpleado[i] =arrayEmpleado[j];
                    arrayEmpleado[j] = aux;
                }
                else if(strcmp ( arrayEmpleado[i].apellido, arrayEmpleado[j].apellido)==0 && array[i].sector>arrayEmpleado[j]sector)
                {
                    aux=arrayEmpleado[i];
                    arrayEmpleado[i] =arrayEmpleado[j];
                    arrayEmpleado[j] = aux;
                }
            }
            else if(orden==2)
            {
                if ( strcmp ( arrayEmpleado[j].apellido, arrayEmpleado[i].apellido)<0)
                {
                    aux= arrayEmpleado [j];
                    arrayEmpleado[j] =arrayEmpleado[i];
                    arrayEmpleado[i] = aux;
                }
                else if(strcmp ( arrayEmpleado[i].apellido, arrayEmpleado[j].apellido)==0 && arrayEmpleado[i].sector,arrayEmpleado[j]sector))
                {
                    aux=arraEmpleado[i];
                    arrayEmpleado[i] =arrayEmpleado[j];
                    arrayEmpleado[j] = aux;
                }
            }
        }
    }

return 0;
}


int printEmployees(struct Empleado arrayEmpleado[], int len)
{
    int i;
    if(arrayEmpleado != NULL && len >0)
    {
        for(i=0; i<len; i++)
        {

            if (arrayEmpleado[i]. isEmpty  == 0 )
            {
                printf ( " \n %d - %s - %s - %.2f - %d", arrayEmpleado[i].id, arrayEmpleado[i].nombre, arrayEmpleado[i].apellido, arrayEmpleado[i].sueldo, arrayEmpleado[i].sector);
            }
        }

    }
    return 0;
}

