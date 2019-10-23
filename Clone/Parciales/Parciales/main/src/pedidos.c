/*
 * pedidos.c
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "pedidos.h"
#include "utn.h"




int initPedidos(ePedidos* listPed, int lenPed)
{

	int i;
	    int ret= -1;
	    if(listPed!=NULL&&lenPed>0)
	    {
	        for(i=0;i<lenPed;i++)
	        {
	        	listPed[i].isEmpty = 0;
	        }
	        ret=0;
	    }
	    return ret;
}

int findEmptySpacePedidos(ePedidos* list, int len)
{
    int ret = -1;
    int i;

    for (i=1; i<len; i++)
    {
        if (list[i].isEmpty == 0)
        {
            ret = i;
            break;
        }
    }
    return ret;
}

int existPedidos(ePedidos* list, int len)
{
	int ret = -1;
    int i;

    for( i = 0; i < len; i++)
    {
        if(list[i].isEmpty == 1)
        {
            ret = 0;
        }
    }
    return ret;
}


int findPedidosById(ePedidos* list, int len, int id)
{
    int ret = -1;
    int i;

    if (list != NULL && len > 0)
    {
        for (i=1; i<len; i++)
        {
            if (list[i].isEmpty == 1 && list[i].idPedidos == id)
            {
                return i;
            }
        }
    }
    return ret;
}

int modificarPedidos(ePedidos* list, int len)
{
    int retorno=-1;
    float auxHDPE = 0;
    float auxLPDE = 0;
    float auxPP = 0;
    float auxdesechables = 0;
    int opcion;
    ePedidos aux;
    if(list!=NULL && len>0)
    {
    	printPedidos(list,len);
        utn_getUnsignedInt("\nID a cargar datos: ","\nError",1,sizeof(int),1,100,1,&aux.idPedidos);         //cambiar si no se busca por ID
        if(findPedidosById(list, len, aux.idPedidos)== -1)
        {
        	printf("\nNo existe el id del pedido ingresado");
        }
        else
        {
        	do
            {
                utn_getUnsignedInt("\nElegir tipo de plasticos procesado : 1 - HDPE | 2 - LDPE | 3 - PP | 4 - Desechables | 5 - Procesar Pedidos | 6(salir)","\nError",1,sizeof(int),1,6,3,&opcion);
                switch(opcion)
                {
                    case 1:
                    	utn_getFloat("\nIngrese los kilos de HDPE procesados: ","\nValor invalido",1,sizeof(float),0,3200000,10,&auxHDPE);
                        break;
                    case 2:
                    	utn_getFloat("\nIngrese los kilos de LPDE procesados: ","\nValor invalido",1,sizeof(float),0,3200000,10,&auxLPDE);
                        break;
                    case 3:
                    	utn_getFloat("\nIngrese los kilos de PP procesados: ","\nValor invalido",1,sizeof(float),0,3200000,10,&auxPP);
                        break;
                    case 4:
                    	utn_getFloat("\nIngrese los kilos de residuos Desechables procesados: ","\nValor invalido",1,sizeof(float),0,3200000,10,&auxdesechables);
                        break;
                    case 5:
                    	if(aux.kilos <= aux.HDPE + aux.LPDE + aux.PP + aux.desechables)
                    	{
                    		strncpy(aux.estado,"COMPLETADO",50);
                    		printf("\nHDPE: %.2f",auxHDPE);
                    		printf("\nLPDE: %.2f",auxLPDE);
                    		printf("\nPP: %.2f",auxPP);
                    		printf("\ndesechables: %.2f",auxdesechables);
                    	}
                    	else
                    	{
                    		printf("\nKilos superiores a los ingresados");

                    	}
                    	break;
                    case 6:
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!=6);
            retorno=0;
        }
    }
    return retorno;
}

int removePedidos (ePedidos* list, int len, int id)
{
    int findPedido;

    if(list != NULL && len > 0)
    {
    	findPedido = findPedidosById(list, len, id);

    	if (findPedido > -1)
    	{
    		list[findPedido].isEmpty = 0;
    		printf("Pedido eliminado con exito \n");
    	}
    	else
    	{
    		printf("No se ha encontrado pedido con ese ID \n");
    	}
    }
    return findPedido;
}

int getDeletePedidos(ePedidos* list,int len)
{
    int ret=-1;
    int auxId;
    utn_getUnsignedInt("\nIngrese id: ","\nValor invalido",1,sizeof(int),0,100,10,&auxId);
    if(findPedidosById(list,len,auxId)>=0)
    {
        removePedidos(list,len,auxId);
        ret=0;
    }
    else
    {
        printf("\nId invalido");
    }
    return ret;
}


int printPedidos (ePedidos* list, int len)
{
    int ret = -1;
    int i;

    if(list != NULL && len > 0)
    {
    	printf("id  -   id cliente  -  kilos  -   estado      \n");

        for(i=0; i<len; i++)
        {
            if (list[i].isEmpty == 1)
            {

                printf("%d  -   %d  -  %.2f  -   PENDIENTE  -   \n", list[i].idPedidos,
                											list[i].idClientes,
															list[i].kilos);
            }
        }
        ret = 0;
    }
    return ret;
}

int printPedidosById(ePedidos* list,int len,int id)
{
    int i;
    int ret = -1;
    if(list!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty==1)
            {
                if(list[i].idPedidos==id)
                {
                    printf("\n---------------------------\n");
                    printf("id: %d  -   id cliente:  %d-  kilos:  %.2f-   estado:  %d- \n",list[i].idPedidos,
                    		                											list[i].idClientes,
                    																	list[i].kilos,
                    																	list[i].estado);
                           ret = 0;
                }
            }
        }
    }
    return ret;
}


int pedido_contarPendientesPorCliente(ePedidos *list,int len, int idCliente)
{
	int retorno = -1;
	int i;
	int contador = 0;
	if(list != NULL && len >= 0 && idCliente >= 0){
		for(i=0; i<len; i++){
			if(list[i].isEmpty == 1 && list[i].idClientes == idCliente && strncmp(list[i].estado,"Pendiente",50)==0){
				contador++;
			}
		}
		retorno = contador;
	}

	return retorno;
}

