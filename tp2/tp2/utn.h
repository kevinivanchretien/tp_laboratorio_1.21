#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED



#endif // UTN_H_INCLUDED

/** \brief Carga de un numero entero
 *
 * \param msg char* Mensaje a mostrar
 * \param msgError char* Mensaje de error a mostrar
 * \param minimo int limite menor
 * \param maximo int limite mayor
 * \param reintentos int cantidad de intentos
 * \param entero int* devuelve el dato ingresado de forma de puntero
 * \return int 0 si el numero ingresado esta dentro de los parametros
 *             -1 si no cumplio algo
 */
int utn_getInt(char* msg, char* msgError, int minimo, int maximo,int reintentos,int* entero);

/** \brief Carga de un numero flotante
 *
 * \param msg char* Mensaje a mostrar
 * \param msgError char* Mensaje de error a mostrar
 * \param minimo int limite menor
 * \param maximo int limite mayor
 * \param reintentos int cantidad de intentos
 * \param flotante int* devuelve el dato ingresado de forma de puntero
 * \return int 0 si el numero ingresado esta dentro de los parametros
 *             -1 si no cumplio algo
 */
int utn_getFloat(char* msg, char* msgError, int minimo, int maximo ,int reintentos, float* flotante);



/** \brief carga una cadena de caracteres
 *
 * \param msg char* mensaje a mostrar
 * \param msgError char* mensaje de error
 * \param min int limite menor
 * \param max int limite mayor
 * \param reintentos int* cantidad de intentos
 * \param palabra char* devuelve la candena de caracteres
 * \return int 0 si se cargo correctamente -1 si no.
 *
 */
int utn_getName(char* msg,char* msgError,int min,int max,int* reintentos,char* palabra);
