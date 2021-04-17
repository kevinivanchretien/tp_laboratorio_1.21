#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"
int main()
{
    setbuf(stdout, NULL);

    int opciones;
    int primero;
    int segundo;
    int flag1=0;
    int flag2=0;
    int flag3=0;
    char pregunta;

    int resultadoS;
    int resultadoR;
    float resultadoD;
    int resultadoM;
    double resultadoSu1;
    double resultadoSu2;


    do
    {
        system("CLS");
        printf("ELIGA UNA OPCION: \n\n");
        printf(" 1-Ingrese primer operador. \n 2-Ingrese segundo operador. \n 3-Calcular.\n 4-Mostrar resultados. \n 5-Salir.\n\n");
        fflush(stdin);
        scanf("%d", &opciones);


        switch(opciones)
        {
        case 1:

            printf("\n Ingrese el primer numero: ");
            scanf("%d",&primero);
            flag1=1;
            break;
        case 2:

            if (flag1==1)
            {
                printf("\n Ingrese el segundo numero: ");
                scanf("%d",&segundo);
                flag2=1;
            }
            else
            {
                printf("\n Debe pasar por el punto 1");
            }
            break;
        case 3:

            if(flag1==0 || flag2 ==0)
            {
                printf("\n Debe ingresar dos numeros para poder calcularlos\n");
                system("pause");
                system("CLS");
            }
            else
            {
                printf("Calculando.\n");
                printf("Calculando..\n");
                printf("Calculando...\n");
                resultadoS= adicion(primero,segundo);
                resultadoR= sustraendo(primero,segundo);
                resultadoD= division(primero, segundo);
                resultadoM= multiplicacion(primero,segundo);
                resultadoSu1= factoreo(primero);
                resultadoSu2= factoreo(segundo);
                flag3=1;
            }

            break;
        case 4:

            if(flag3==1 )
            {
                printf("\n El resultado de la suma es %d",resultadoS);
                printf("\n El resultado de la resta es %d",resultadoR);
                if(segundo ==0)
                {
                    printf("\n No se puede dividir por 0");
                }
                else
                {
                    printf("\n El resultado de la division es %.2f",resultadoD);
                }
                printf("\n El resultado de la multiplicacion es %d", resultadoM);
                printf("\n El resultado del factoreo del primero es %.0f", resultadoSu1);
                printf("\n El resultado del factoreo del segundo es %.0f \n", resultadoSu2);
                system("pause");
            }
            else
            {
                printf("\nNo se calcularon los datos ingresados\n");
                system("pause");
            }
            break;
        case 5:
            system("CLS");
            printf("\n Esta seguro que desea salir? (s/n): " );
            fflush(stdin);
            scanf("%c", &pregunta);
            break;
        default:
            printf("\n OPCION NO VALIDA");
            break;

        }
    }
    while(pregunta!='s');
    flag1=0;
    flag2=0;
    flag3=0;
    system("CLS");
    printf("\n Gracias, que tenga buen dia\n\n");
    return 0;

}
