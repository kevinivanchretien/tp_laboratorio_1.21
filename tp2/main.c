#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "employee.h"
#define MAX 3


int menu();
int submenu();

int main()
{
    struct Empleado vecPersona[MAX];

    int i;
    char respuesta='s';
    char respuesta2='s';

    int contadorID=0;

    char auxiNombre[51];
    char auxiApellido[51];
    int auxSector;
    float auxSueldo;
    int auxiID;

    int flag=0;
    int orden;

    float acumSueldo=0;
    float resulPromedio;
    int contador=0;
    int contador2=0;



    for(i=0; i<MAX; i++)
    {
        vecPersona[i].isEmpty=1;
    }
    do
    {
        switch(menu())
        {
        case 1:
            system("CLS");
            printf("   ALTA DEL EMPLEADO \n\n");

            printf("\n Nombre: ");
            fflush(stdin);
            scanf("%s",&auxiNombre);

            printf("\n Apellido: ");
            fflush(stdin);
            scanf("%s",&auxiApellido);

            printf("\n Sueldo: ");
            fflush(stdin);
            scanf("%f",&auxSueldo);
            acumSueldo+auxSueldo;

            printf("\n Sector: ");
            fflush(stdin);
            scanf("%d",&auxSector);

            addEmployee(vecPersona,MAX,&contadorID,auxiNombre,auxiApellido,auxSueldo,auxSector);

            if(addEmployee ==0)
            {
                printf("CArga exitosa\n");
                system("pause");
            }
            else
            {
                printf("no se pudo cargar los datos \n.");
                system("pause");
            }
            flag=1;
            break;
        case 2:
            if(flag==1)
            {
                system("CLS");
                printf("   MODIFICACION\n\n");

                printf("ID del empleado a modificar:");
                scanf("%d",&auxiID);

                findEmployeeById(vecPersona,MAX,&auxiID,0);

                if(findEmployeeById==0)
                {

                    do
                    {
                        switch(submenu())
                        {

                        case 1:
                            printf("cambiar nombre del empleado %d: ",auxiID);
                            fflush(stdin);
                            scanf("%s",&auxiNombre);
                            strcpy(vecPersona[auxiID].nombre,auxiNombre);
                            break;
                        case 2:
                            printf("cambiar Apellido del empleado %d: ",auxiID);
                            fflush(stdin);
                            scanf("%s",&auxiApellido);
                            strcpy(vecPersona[auxiID].apellido,auxiApellido);
                            break;
                        case 3:
                            printf("cambiar Sueldo del empleado %d: ",auxiID);
                            fflush(stdin);
                            scanf("%f",&auxSueldo);
                            vecPersona[auxiID].sueldo=auxSueldo;
                            break;
                        case 4:
                            printf("cambiar sector del empleado %d: ",auxiID);
                            fflush(stdin);
                            scanf("%d",&auxSector);
                            vecPersona[auxiID].sector=auxSector;
                        case 5:
                            printf("desea volver al menu principal? s/n");
                            fflush(stdin);
                            scanf("%c",&respuesta);
                            break;
                        }
                    }
                    while(respuesta2 =='s');
                    addEmployee(vecPersona,MAX,&contadorID,auxiNombre,auxiApellido,auxSueldo,auxSector);

                }
                else
                {
                    printf("no se encontro el Id ingresado");
                    system("pause");
                }
            }
            else
            {
                printf("No hay datos para modificar..");
            }
            break;
        case 3:
            printf("   BAJA");
            printf("Ingrese el ID para la baja:");
            fflush(stdin);
            scanf("%d",&auxiID);


            removeEmployee(vecPersona, MAX, auxiID);
            break;
        case 4:
            printf("eliga un orden para mostrar: \n");
            printf("\n 1-orden ascendente.");
            fflush(stdin);
            scanf("%d",&orden);
            printf("\n 2-orden descendente.");
            fflush(stdin);
            scanf("%d",&orden);

            sortEmployees(vecPersona, MAX,&orden);
            printEmployees(vecPersona,MAX);

            for(i=0;i<MAX;i++){
            if (vecPersona[i].isEmpty == 0 )
                {
                   contador++;
                }}
            for(i=0; i<contador; i++)
            {
                acumSueldo=acumSueldo+vecPersona[i].sueldo;
            }
            resulPromedio=acumSueldo/contador;
            for(i=0; i<MAX; i++)
            {
                if (vecPersona[i].sueldo >resulPromedio)
                {
                    contador2++;
                }
            }
            printf("El sueldo promedio es %f", resulPromedio);
            printf("Hay %d empleados que superan el sueldo promedio",contador2);


            break;
        case 5:
            printf("Seguro que desea salir? s/n");
            fflush(stdin);
            scanf("%c",&respuesta);
            break;
        default:
            printf("opcion invalida");
            break;
        }
    }
    while(respuesta !='s');







    return 0;
}







int menu()
{
    int opcion=0;
    system ("CLS");
    printf("BIENVENIDOS al Menu de empleados:\n\n");

    printf("1- ALTA.\n");
    printf("2- MODIFICACION.\n");
    printf("3- BAJA.\n");
    printf("4- INFORMAR.\n");
    printf("5- Salir.\n");
    scanf("%d",&opcion);

    return opcion;
}

int submenu()
{
    int opcion;
    printf("Menu Modificar:\n");

    printf("\n 1-Modificar Nombre.");
    printf("\n 2-Modificar Apellido.");
    printf("\n 3-Modificar sueldo.");
    printf("\n 4-Modificar sector.");
    printf("\n 5-volver al menu principal.\n");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}

