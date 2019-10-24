/*
 * controller.h
 *
 *  Created on: 16 oct. 2019
 *      Author: sergio
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_


int listarClientesPendiente(eClientes list[], int len, ePedidos list2[], int len2);

int listar_pendientes(eClientes list[], int size, ePedidos list2[], int size2);

int pedido_ImprimirArrayProcesado(eClientes list[], int len, ePedidos list2[], int len2);

int clienteMasPendientes(eClientes list[], int len, ePedidos list2[], int len2);

int clienteMasPedidosCompletos(eClientes list[], int len, ePedidos list2[], int len2);

int clienteMasPedidos(eClientes list[],ePedidos list2[], int len, int len2);

int clienteMasReciclo(eClientes list[], int len, ePedidos list2[], int len2);

int clienteMenosReciclo(eClientes list[], int len, ePedidos list2[], int len2);

int clientesConMasDeMilKg(eClientes list[], int len, ePedidos list2[], int len2);

int clientesConMenosDeCienKg(eClientes list[], int len, ePedidos list2[], int len2);

int porcentajePedidosCompletados(eClientes list[], int len, ePedidos list2[], int len2);

int localidad_pendientes(eClientes list[], int len, ePedidos list2[], int len2);


int cuitTipoDePlasticoReciclado(eClientes list[], int len, ePedidos list2[], int len2);
#endif /* CONTROLLER_H_ */
