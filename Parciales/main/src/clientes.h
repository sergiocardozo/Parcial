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

/** \brief  Para indicar que todas las posiciones en el array están vacías,
* esta función pone la bandera (isEmpty) en TRUE en todos
* posición del array
* \ param array eClientes array de clientes
* \ param size int largo del array
* \ return int retorna (-1) si da Error [Longitud inválida o puntero NULL] - (0) si esta Ok
*
*/
int cliente_Inicializar(eClientes array[], int size);

/** \brief Busca el primer lugar vacio en un array
* \param array eClientes Array de clientes
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int cliente_buscarEmpty(eClientes array[], int size, int* posicion);

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array eCliente Array de clientes
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int cliente_buscarID(eClientes array[], int size, int valorBuscado, int* posicion);

/** \brief Verifica si hay al menos un cliente cargado en el array
     *
     * \param list eClientes lista del campo de eClientes
     * \param len int  largo del array
     * \return 0 si no hay Clientes, 1 si hay al menos uno cargado
     *
     */

int clienteBuscarCuit(eClientes array[], int size, char* valorBuscado, int* indice);

int clienteBuscarLocalidad(eClientes array[], int size, char* valorBuscado, int* indice);
int clientesExistente(eClientes list[], int len);

/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array eClientes Array de clientes
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int cliente_alta(eClientes array[], int size, int* contadorID);

/** \brief Borra un elemento del array por ID
* \param array eClientes Array de clientes
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int cliente_baja(eClientes clieArray[], int sizeClieArray);

/** \brief Busca un elemento por ID y modifica sus campos direccion y localidad
* \param array eClientes Array de clientes
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int cliente_modificar(eClientes array[], int sizeArray);

/** \brief Lista los elementos de un array
* \param array eClientes Array de clientes
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int cliente_listar(eClientes array[], int size);

#endif /* CLIENTES_H_ */
