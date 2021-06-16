#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED






struct Empleado//llevarlo al .h
{
    int id;
    char nombre[51];
    char apellido[51];
    float sueldo;
    int sector;
    int isEmpty;

};

#endif // EMPLOYEE_H_INCLUDED



/** \brief inicia la busquedad
 *
 * \param vec[] struct Empleado recibe parametros reales
 * \param tam int   cant
 * \param posicion int* devuelve la posicion libre encotnrada
 * \return int
 *
 */
int initEmployees(struct Empleado vec[], int tam,int* posicion);

/** \brief agregar Empleado
 *
 * \param arrayEmpleado[] struct Empleado recibe paramatros reales
 * \param len int
 * \param contadorId int* cambia el valor para guardarlo en ID
 * \param name[] char guarda el nombre
 * \param lastName[] char guarda el apellido
 * \param salary float guarda el sueldo
 * \param sector int guarda el sector
 * \return int
 *
 */
int addEmployee(struct Empleado arrayEmpleado[], int len, int* contadorId, char name[],char lastName[],float salary,int sector);


/** \brief encuentra enpleado a travez del ID
 *
 * \param arrayEmpleado[] struct Empleado
 * \param len int
 * \param buscarId int busca el id
 * \param posicion int* devuelve en que posicion se encuentra
 * \return int
 *
 */
int findEmployeeById(struct Empleado arrayEmpleado[], int len,int buscarId,int *posicion);

/** \brief remueve un Empleado a travez del id
 *
 * \param arrayEmpleado[] struct Empleado recibe datos tipo struct
 * \param len int el largo
 * \param id int el
 * \return int
 *
 */
int removeEmployee(struct Empleado arrayEmpleado[], int len, int id);

/** \brief ordena segun que criterio
 *
 * \param arrayEmpleado[] struct Empleado
 * \param len int
 * \param order int
 * \return int
 *
 */
int sortEmployees(struct Empleado arrayEmpleado[], int len, int orden);

/** \brief muestra los datos ingresados
 *
 * \param arrayEmpleado[] struct Empleado
 * \param len int
 * \return int
 *
 */
int printEmployees(struct Empleado arrayEmpleado[], int len);




