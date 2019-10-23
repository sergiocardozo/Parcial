/*
 * controller.c
 *
 *  Created on: 16 oct. 2019
 *      Author: sergio
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "pedidos.h"
#include "utn.h"

static int autoId(void)
{
    static int id=1;
    return id++;
}

int addPedidos(ePedidos* list2, int len2, eClientes* list, int len)
{
	int idClientes;
	float auxKilos;
	int i;
	int ret = -1;
	if(list2 != NULL && len2 > 0)
	{
		utn_getUnsignedInt("\nIngrese id del cliente: ","\nValor invalido",1,sizeof(int),0,100,10,&idClientes);
		if(findClientesById(list,len,idClientes)>=0)
		{
			utn_getFloat("\nIngrese kilos a procesar : ","\nValor invalido",1,sizeof(float),0,3200000,10,&auxKilos);

			i=findEmptySpacePedidos(list,len);
			if(i>=0)
			{
				list2[i].idPedidos = autoId();
				list2[i].idClientes = idClientes;
				printf("%.2f kilos a retirar",list2[i].kilos = auxKilos);
				strncpy(list2[i].estado,"PENDIENTE",50);
				list2[i].isEmpty = 1;
				printf("\nAgregado Exitosamente");
				printf("\nPENDIENTE");
				ret=0;
			}
		}
		else
		{
			printf("No se encontro Cliente con ese ID \n");
		}
	}
	return ret;
}

int pedidos_listarPendiente(eClientes *list, int len, ePedidos *list2, int len2)
{
	int i;
	int retorno = -1;

	if(list != NULL && len>0)
	{
		retorno = 0;
		printf("Cuit    Direccion    Cantidad \n");
		for(i=0;i<len2;i++)
		{
			if(list2[i].isEmpty == 1
					&& strncmp(list2[i].estado,"Pendiente", 50) == 0 ){
				list[i].idClientes = list2[i].idClientes;

				printf("%s -- %s -- %.2f \n",list[i].cuit,list[i].direccion,list2[i].kilos);
			}

		}
	}
	return retorno;
}

int pedido_ImprimirArrayProcesado(eClientes* list, int len, ePedidos* list2, int len2)
{
	int i;
	int retorno = -1;
		if(list != NULL && len>0)
	{
		retorno = 0;
		printf("Cuit    Direccion    Plastico HDPE     Plastico LDPE	Plastico PP		Desechables\n");
		for(i=0;i<len2;i++)
		{
			if(list2[i].isEmpty == 1
					&& strncmp(list2[i].estado,"COMPLETADO", 50) == 0 ){
				list[i].idClientes = list2[i].idClientes;
				printf("%s -- %s -- %.2f -- %.2f -- %.2f -- %.2f \n",list[i].cuit,list[i].direccion,list2[i].HDPE,list2[i].LPDE,list2[i].PP,list2[i].desechables);
			}

		}
	}
	return retorno;
}
