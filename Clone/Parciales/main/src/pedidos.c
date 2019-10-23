/*
 * pedidos.c
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "pedidos.h"
#include "utn.h"




int pedidos_Inicializar(ePedidos array[], int size)
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

int pedidos_buscarEmpty(ePedidos array[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}


int pedidos_buscarID(ePedidos array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idPedidos==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int pedidos_alta(ePedidos array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID>0)
    {
    	__fpurge(stdin);
        if(pedidos_buscarEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
        	if(utn_getUnsignedInt("\n:Ingrese ID de cliente: ","\nError",1,sizeof(int),1,size,2,&array[posicion].idClientes)==0)
        	{
        		(*contadorID)++;
        		array[posicion].idPedidos = *contadorID;

        		array[posicion].isEmpty=0;
        		array[posicion].estado=PENDIENTE;
        		utn_getFloat("\n:Ingrese cantidad de kilos: ","\nError",1,sizeof(float),1,10000,2,&array[posicion].kilos);

        		printf("\nID: %d\tCantidad de kilos: %.2f\tEstado: Pendiente",array[posicion].idPedidos,array[posicion].kilos);
        		retorno=0;
        	}
        	else
        	{
        		printf("Numero de ID incorrecto");
        	}
        }
    }
    return retorno;
}


int pedidos_procesar(ePedidos array[], int size)
{
    int retorno=-1;
    int posicion;
    int id;
    float cantidadTotal =0;
    if(array!=NULL && size>0)
    {
    	__fpurge(stdin);
    	utn_getUnsignedInt("\nID de pedido: ","\nError",1,sizeof(int),1,size,3,&id);
    	if(pedidos_buscarID(array,size,id,&posicion)==-1)
    	{
    		printf("No existe el ID del pedido");
    	}
    	else
    	{
    		cantidadTotal = array[posicion].kilos;
    		if(array[posicion].estado==0)
    		 {
    			utn_getFloat("\nCantidad de kilos de HDPE ","\nError",1,sizeof(float),1,3000,1,&array[posicion].HDPE);
    			cantidadTotal = cantidadTotal - array[posicion].HDPE;
    			utn_getFloat("\nCantidad de kilos de LPDE ","\nError",1,sizeof(float),1,3000,1,&array[posicion].LPDE);
    			cantidadTotal = cantidadTotal - array[posicion].LPDE;
    			utn_getFloat("\nCantidad de kilos de PP ","\nError",1,sizeof(float),1,3000,1,&array[posicion].PP);
    			cantidadTotal = cantidadTotal - array[posicion].PP;
    			array[posicion].estado=COMPLETADOS;

    			printf("\n ID: \tCantidad de kilos procesados: \tCantidad de kilosHDPE: \tCantidad de kilosLDPE: \tCantidad de kilosPP: \tCantidad de kilos de residuos desechables: \tEstado: Completado");

    			printf("\n%4d\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f",
													array[posicion].idPedidos,
													array[posicion].kilos,
													array[posicion].HDPE,
													array[posicion].LPDE,
													array[posicion].PP,
													cantidadTotal);

    		 }

    		else
    		{
    			printf("El pedido ya fue procesado");
    		}
    	}

    }


    return retorno;
}



int pedidos_listar(ePedidos array[], int size)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
    	__fpurge(stdin);
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                continue;
            }
            else
            {
            	printf("\n ID: %d\t Cantidad de kilos: %f",
            	        array[i].idPedidos,
            	        array[i].kilos);
            	if(array[i].estado==0)
            	{
            		printf("\n Estado: Pendiente");
            	}
            	else
            	{
            		printf("\n Estado: Completado");
            	}
            }
        }
        retorno=0;
    }
    return retorno;
}

