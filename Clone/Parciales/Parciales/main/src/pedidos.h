/*
 * pedidos.h
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */

#ifndef PEDIDOS_H_
#define PEDIDOS_H_

#include "clientes.h"

typedef struct
{
	int idPedidos;
	int idClientes;
	float kilos;
	char estado[50];
	float HDPE;
	float LPDE;
	float PP;
	float desechables;
	int isEmpty;

}ePedidos;

/** \brief Indicates that all positions of the array are empty, setting the isEmpty flag in TRUE in all array positions
     *
     * \param list eClientes* Pointer to array of employees
     * \param len int Array length
     * \return Return -1 if error (NULL or invalid), 0 if no error
     *
     */
int initPedidos(ePedidos* listPed, int lenPed);



    /** \brief request to the users the information for a new employee
     *
     * \param list eclientes*
     * \param len int
     * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
     *
     */
    int controllerGetPedidos(ePedidos* list, int len);

    /** \brief Gets free space from the index
     *
     * \param list ePedidos* Pointer to array of clientes
     * \param len int Array length
     * \return Return -1 if error (NULL or invalid), 0 if no error
     *
     */

    int existPedidos(ePedidos* list, int len);

    int findEmptySpacePedidos(ePedidos* list, int len);

    /** \brief find an eCliente by Id en returns the index position in array.
     * \param list eCliente* Pointer to array of clientes
     * \param len int Array length
     * \param id int Id number
     * \return Return -1 if error (NULL or invalid), 0 if no error
     */
    int findPedidosById(ePedidos* list, int len, int id);

    /** \brief Find an employee by id and asks what wants the user to modify
     *
     * \param list ePedidos* Pointer to array of employees
     * \param len int Array length
     * \return Return modified data
     *
     */
    int modificarPedidos(ePedidos* list, int len);

    /** \brief Remove a Employee by Id (put isEmpty Flag in 1).
     * \param list Employee* Pointer to array of employees
     * \param len int Array length
     * \param id int Id number
     * \return Return -1 if error (NULL or invalid), 0 if no error
     */
    int removePedidos(ePedidos* list, int len, int id);

    /** \brief Request an id and deletes the register.
     *
     * \param list Employee*
     * \param length int
     * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
     *
     */
    int getDeletePedidos(ePedidos *list,int len);

    /** \brief print the content of employees array.
     * \param list Employee* Pointer to array of employees
     * \param length int Array length
     * \return int.
     */
    int printPedidos(ePedidos* list, int len);




    int pedido_contarPendientesPorCliente(ePedidos *list,int len, int idCliente);


#endif /* PEDIDOS_H_ */
