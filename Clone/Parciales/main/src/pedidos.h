/*
 * pedidos.h
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */

#ifndef PEDIDOS_H_
#define PEDIDOS_H_

#define PENDIENTE 0
#define COMPLETADOS 1

typedef struct
{
	int idPedidos;
	int idClientes;
	float kilos;
	int estado;
	float HDPE;
	float LPDE;
	float PP;
	int isEmpty;

}ePedidos;

/** \brief  Para indicar que todas las posiciones en el array están vacías,
* esta función pone la bandera (isEmpty) en TRUE en todos
* posición del array
* \ param array ePedidos array de pedidos
* \ param size int largo del array
* \ return int retorna (-1) si da Error [Longitud inválida o puntero NULL] - (0) si esta Ok
*
*/
int pedidos_Inicializar(ePedidos array[], int size);

/** \brief Busca el primer lugar vacio en un array
* \param array eClientes Array de clientes
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int pedidos_buscarEmpty(ePedidos array[], int size, int* posicion);

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array eCliente Array de clientes
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/

int pedidos_buscarID(ePedidos array[], int size, int valorBuscado, int* posicion);

/** \brief Verifica si hay al menos un cliente cargado en el array
     *
     * \param list eClientes lista del campo de eClientes
     * \param len int  largo del array
     * \return 0 si no hay Clientes, 1 si hay al menos uno cargado
     *
     */


/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array eClientes Array de clientes
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int pedidos_alta(ePedidos array[], int size, int* contadorID);

/** \brief Lista los elementos de un array
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int pedidos_procesar(ePedidos array[], int size);

/** \brief Lista los elementos de un array
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int pedidos_listar(ePedidos array[], int size);

#endif /* PEDIDOS_H_ */
