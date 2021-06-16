#ifndef ARRAYEMPLOYES_H_INCLUDED
#define ARRAYEMPLOYES_H_INCLUDED

#define MAX_LETRAS 50
typedef struct
{
    int id;
    char nombre[MAX_LETRAS];
    char apellido[MAX_LETRAS];
    float salario;
    int sector;
    int isEmpty;

}Employee;


#endif // ARRAYEMPLOYES_H_INCLUDED

/** \brief Inicializa el campo isEmpty para que todas las posiciones.
 *          del array esten vacias.
 * \param list Employee* Recibe un puntero al array empleado.
 * \param len int Recibe el tamaño.
 * \return Devuelve 0 si funciono y -1 si no.
 *
 */
int initEmployee(Employee* list,int len);


/** \brief Busca en el array un lugar libre y lo devuelve por puntero
 *
 * \param list Employee* Recibe un puntero a aray Empleado
 * \param Recibe la cantidad de elementos del array
 * \param Recibe un puntero por donde devuelve el lugar encontrado
 * \return Devuelve 0  si se encontro lugar y -1 si no lo encontro.
 *
 */
int employee_buscarIsEmpty(Employee* list,int tam,int* posicion);


/** \brief agregar en una lista existente de empleados los valores
 *          recibidos como parámetros en la primera posición vacía
 * \param list Employee*
 * \param len int
 * \param id int*
 * \param nombre[] char
 * \param apellido[] char
 * \param sueldo float
 * \param sector int
 * \return int devuelve -1 si no se pudo agregar y 0 si esta OK.
 *
 */
int addEmployee(Employee* list,int len, int id, char* nombre,char* apellido,float sueldo,int sector);


/** \brief Muestra el contenido del array empleados
 *
 * \param list Employee*
 * \param length int
 * \return devuelve 0 si esta todo OK y -1 si no.
 *
 */
int printEmployee(Employee* list, int length);


/** \brief Encuentra un empleado por Id y devuelve la posición del índice
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Devuelve la posicion del Id encontrado o -1 si no se encontro.
 *
 */
int findEmployee(Employee* list,int len,int id);

/** \brief Muestra un solo empleado
 *
 * \param array de Empleados
 * \param Cantidad de empleados.
 * \param Que empleado debe mostrar.
 * \return Devuelve 0 si salio todo ok y -1 si no.
 *
 */
int mostrar_unEmpleado(Employee* list,int len,int posicion);


/** \brief Elimina un empleado poniendo el campo isEmpty en 1(vacio)
 *
 * \param Recibe el array de Employee
 * \param El tamañano del array
 * \param el Id a dar de baja
 * \return Devuelve -1 si fallo y 0 si se puedo dar de baja logica el empleado
 *
 */
int removeEmployee(Employee* list, int len, int id);



/** \brief Ordena el array de empleados
 *
 * \param Array de empleados
 * \param el tamaño del array
 * \param Depende del order lo acomoda de
            mayor a menor(1) o de menor a mayor(0)
 * \return int
 *
 */
int sortEmployees(Employee* list, int len, int order);


/** \brief Calcula y muestra el resultado
 *
 * \param list Employee* Recibe un array de empleados.
 * \param len int Recibe el tamaño.
 * \return int devuelve 0 si pudo calcular o -1 si fallo
 *
 */
int promedioEmployees(Employee* list, int len);




/** \brief Busca el id del empleado
 *
 * \param list Employee* Recibe el array de empleados
 * \param len int Recibe el tamaño del arrat
 * \param posicion int Recibe la posicion
 * \return Devuelve el id buscado o -1 si no se encontro
 *
 */
int buscarid_Employee(Employee* list,int len,int posicion);



/** \brief Guarda automaticamente datos precargados
 *
 * \param list Employee* Recibe el array de empleados donde lo va a guardar
 * \
 */
void harcodeoEmpleados(Employee* list);


/** \brief Modifica capos de una estructura
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int devuelve 0 si salio Ok o -1 si no.
 *
 */
int ModEmployee(Employee* list, int len, int id);
