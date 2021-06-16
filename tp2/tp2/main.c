#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployes.h"
#include "utn.h"
#define MAX 1000
#define SUELDO 1000000.00

int main()
{
    Employee arrayEmpleado[MAX];

    int menu;
    char respuesta ='n';
    int flag=1;

    int contadorId=0;
    int auxID;
    char Name[30];
    char lastname[30];
    float salary;
    int sector;
    int fPosicion;
    int opListar;
    int orden;
    char subMenu='n';

    initEmployee(arrayEmpleado,MAX);
    //harcodeoEmpleados(arrayEmpleado);

    do
    {
        system("CLS");
        printf("___MENU____\n\n");
        printf("1-Alta.\n");
        printf("2-Modificar.\n");
        printf("3-Baja.\n");
        printf("4-Informar.\n");
        printf("5-Salir.\n\n");
        fflush(stdin);
        scanf("%d",&menu);

        switch(menu)
        {
        case 1:// agregar un empleado
            system("CLS");
            if(employee_buscarIsEmpty(arrayEmpleado,MAX,&fPosicion)==0)
            {
                printf("Bienvenido al alta de Empleados\n\n");
                contadorId++;
                utn_getName("\nIngrese el Nombre del empleado: ", "\nError ",1,51,3,Name);
                utn_getName("\nIngrese el Apellido del empleado: ", "\nError ",1,51,3,lastname);
                utn_getFloat("\nIngrese el sueldo del empleado: ", "\nError Fuera de presupuesto",1,SUELDO,3,&salary);
                utn_getInt("\nIngrese uno de los 5 sectores donde trabajara el empleado: ", "Error no existe ese sector, intente devuelta: ",1,5,3,&sector);

                if(addEmployee(arrayEmpleado,MAX,contadorId,Name,lastname,salary,sector)==0)
                {
                    printf("\n\n Se cargo correctamente los siguientes datos");

                    mostrar_unEmpleado(arrayEmpleado,MAX,findEmployee(arrayEmpleado,MAX,contadorId));
                    system("pause");
                }
                else
                {
                    printf("\n algo salio mal");
                }
                flag=0;
            }
            else
            {
                printf("no hay espacios libres");
            }
            break;
        case 2://Modificar un Empleado.

            if(flag==1)
            {
                printf("No se ingreso ningun empleado\n");
                system("pause");

            }
            else
            {
                system("CLS");
                printf("Modificar Empleados\n\n");

                printEmployee(arrayEmpleado,MAX);

                printf("Ingrese el Id del usuario a modificar: ");
                fflush(stdin);
                scanf("%d",&auxID);

                ModEmployee(arrayEmpleado,MAX,auxID);
            }
            break;
        case 3://Eliminar un Empleado

            if(flag==1)
            {
                printf("No se ingreso ningun empleado\n");
                system("pause");
            }
            else
            {
                system("CLS");
                printf("Baja Empleado\n\n");

                printf("Ingrese Id a dar de baja: ");
                fflush(stdin);
                scanf("%d",&auxID);
                removeEmployee(arrayEmpleado,MAX,auxID);
            }

            break;
        case 4://Listar
            if(flag==1)
            {
                printf("No se ingreso ningun empleado\n");
                system("pause");
            }
            else
            {
                do
                {
                    system("CLS");
                    printf("Listado de Empleados.\n\n");

                    printf("1- Mostrar Empleados.\n");
                    printf("2- Listar por orden alfabetico.\n");
                    printf("3- Calcular el promedio.\n");
                    printf("4- <-[menu principal]\n");
                    fflush(stdin);
                    scanf("%d",&opListar);

                    switch(opListar)
                    {
                    case 1:
                        printEmployee(arrayEmpleado,MAX);
                        break;
                    case 2:
                        printf("\n Elija una opcion: \n0-DE MENOR A MAYOR. \n1-DE MAYOR A MENOR.\n");
                        fflush(stdin);
                        scanf("%d",&orden);
                        sortEmployees(arrayEmpleado,MAX,orden);
                        printEmployee(arrayEmpleado,MAX);

                        break;
                    case 3:
                        promedioEmployees(arrayEmpleado,MAX);
                        system("pause");
                        break;
                    case 4:
                        printf("\nvolver al menu principal (s/n): ");
                        fflush(stdin);
                        scanf("%c",&subMenu);
                        break;
                    default:
                        printf("opcion invalida");
                        system("pause");
                        break;
                    }
                }
                while(subMenu!='s');
                break;
            case 5:
                printf("Presione s para salir (s/n): ");
                fflush(stdin);
                scanf("%c",&respuesta);
                break;
            default:
                printf("Opcion invalida...\n\n");
                system("pause");
                break;
            }


        }
    }
    while(respuesta !='s');
    return 0;
}
