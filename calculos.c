
int adicion(int num1, int num2)//a) “El resultado de A+B es: r”
{
    int resultado;
    resultado=num1+num2;
    return resultado;
}


int sustraendo(int num1, int num2)//b) “El resultado de A-B es: r”
{
    int diferencia;
    diferencia=num1-num2;
    return diferencia;
}

int division(int num1, int num2)//c) “El resultado de A/B es: r”
{
    float cociente;


    if(num2 !=0)
    {
       cociente =num1/num2;
    }
    else
    {
        return 0;
    }
    return cociente;
}

int multiplicacion(int num1, int num2)
//“El resultado de A*B es: r"
{
    int producto;
    producto=num1*num2;
    return producto;
}

int factoreo(int num) //e) “El factorial de A es:r1 y El factorial de B es:r2”
{
    double respuesta=1;
    int i;
    for(i=num; i>1; i--)
    {
        respuesta=respuesta*i;
    }
    return respuesta;
}
