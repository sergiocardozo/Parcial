/*
 * controller.h
 *
 *  Created on: 16 oct. 2019
 *      Author: sergio
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

    /** \brief add in a existing list of employees the values received as parameters in the first empty position.
     * \param list ePedidos* Pointer to array of employees
     * \param len int Array length
     * \param id int Id number
     * \param nameEmpresa[] char NameEmp array
     * \param cuit[] char cuit name array
     * \param direccion[] char direccion array
     * \param localidad[] char localidad array
     * \return Return -1 if error (NULL or invalid), 0 if no error
     */
    int addPedidos(ePedidos* list2, int len2, eClientes* list, int len);

    int pedidos_listarPendiente(eClientes *list, int len, ePedidos *list2, int len2);

    int pedido_ImprimirArrayProcesado(eClientes* list, int len, ePedidos* list2, int len2);



#endif /* CONTROLLER_H_ */
