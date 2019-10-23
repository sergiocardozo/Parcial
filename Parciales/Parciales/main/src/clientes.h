/*
 * clientes.h
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */

#ifndef CLIENTES_H_
#define CLIENTES_H_

#include "pedidos.h"

typedef struct
{
	int idClientes;
	char nombreEmpresa[50];
	char cuit[13];
	char direccion[50];
	char localidad[50];
	int isEmpty;

}eClientes;

/** \brief Indicates that all positions of the array are empty, setting the isEmpty flag in TRUE in all array positions
     *
     * \param list eClientes* Pointer to array of employees
     * \param len int Array length
     * \return Return -1 if error (NULL or invalid), 0 if no error
     *
     */
    int initClientes(eClientes* list, int len);

    /** \brief add in a existing list of employees the values received as parameters in the first empty position.
     * \param list eClientes* Pointer to array of employees
     * \param len int Array length
     * \param id int Id number
     * \param nameEmpresa[] char NameEmp array
     * \param cuit[] char cuit name array
     * \param direccion[] char direccion array
     * \param localidad[] char localidad array
     * \return Return -1 if error (NULL or invalid), 0 if no error
     */
    int addClientes(eClientes* list, int len, int id, char nombreEmpresa[], char cuit[], char direccion[], char localidad[]);

    /** \brief request to the users the information for a new employee
     *
     * \param list eclientes*
     * \param len int
     * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
     *
     */
    int controllerGetClientes(eClientes* list, int len);

    /** \brief Gets free space from the index
     *
     * \param list eClientes* Pointer to array of clientes
     * \param len int Array length
     * \return Return -1 if error (NULL or invalid), 0 if no error
     *
     */

    int existClientes(eClientes* list, int len);

    int findEmptySpaceClientes(eClientes* list, int len);

    /** \brief find an eCliente by Id en returns the index position in array.
     * \param list eCliente* Pointer to array of clientes
     * \param len int Array length
     * \param id int Id number
     * \return Return -1 if error (NULL or invalid), 0 if no error
     */
    int findClientesById(eClientes* list, int len, int id);

    /** \brief Find an employee by id and asks what wants the user to modify
     *
     * \param list eClientes* Pointer to array of employees
     * \param len int Array length
     * \return Return modified data
     *
     */
    int modificarClientes(eClientes* list, int len);

    /** \brief Remove a Employee by Id (put isEmpty Flag in 1).
     * \param list Employee* Pointer to array of employees
     * \param len int Array length
     * \param id int Id number
     * \return Return -1 if error (NULL or invalid), 0 if no error
     */
    int removeClientes(eClientes* list, int len, int id);

    /** \brief Request an id and deletes the register.
     *
     * \param list Employee*
     * \param length int
     * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
     *
     */
    int getDeleteClientes(eClientes *list,int len);

    /** \brief print the content of employees array.
     * \param list Employee* Pointer to array of employees
     * \param length int Array length
     * \return int.
     */
    int printClientes(eClientes* listClientes, int lenClientes);

    int cliente_ImprimirArrayConPendientes(eClientes* list, int len, ePedidos* list2, int len2);

#endif /* CLIENTES_H_ */
