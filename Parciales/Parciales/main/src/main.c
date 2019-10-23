/*
 ============================================================================
 Name        : main.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "clientes.h"
#include "utn.h"
#include "pedidos.h"
#include "controller.h"

#define QTY_CLIENTES 100
#define QTY_PEDIDOS 1000

int main()
{
	int opcion;
	char menuPrincipalMensaje[] ="\n1-MENU DE OPCIONES\
            \n\n1-ALTAS CLIENTES\
            \n2-MODIFICAR DATOS DE CLIENTE\
            \n3-BAJA DE CLIENTE\
            \n4-CREAR PEDIDO DE RECOLECCION\
	 	 	\n5 PROCESAR RESIDUOS \
			\n6 IMPRIMIR CLIENTES\
			\n7 IMPRIMIR PEDIDOS CLIENTES\
			\n8 IMPRIMIR PEDIDOS PROCESADOS\
		    \n9-SALIR\n\n\
			\nIngrese opcion:";
	eClientes arrayClientes[QTY_CLIENTES]=
			{
					{0,"Anfibia","22-22444444-0","Belgrano 156","Banfield",0},
					{1,"El borne","23-22333444-0","Solis 234","Lomas",0},
					{2,"Skaal","22-22443674-0","Italia 275","Lomas",0},
					{3,"Hormiga Negra","22-22415793-0","Maipu 250","Lanus",0},
					{4,"Burga","22-22413463-0","Jorge 89","Adrogue",0},
					{5,"1870s","22-22413254-0","Colombres 101","Banfield",0},
					{6,"KickOff","23-24563444-7","Alvear 1509","Lomas",0},
					{7,"La Zorra","22-22443961-2","Italia 315","Adrogue",0},
					{8,"Guten Bier","22-22442193-5","Bolivar 80","Lomas",0},
					{9,"Beerfield","22-22413222-1","Alsina 12512","Banfield",0}

			};
	ePedidos arrayPedidos[QTY_PEDIDOS];
	initClientes(arrayClientes,QTY_CLIENTES);
	initPedidos(arrayPedidos,QTY_PEDIDOS);


	do
	{
		utn_getUnsignedInt(menuPrincipalMensaje,"\nError",1,sizeof(int),1,8,1,&opcion);

		__fpurge(stdin);

		switch(opcion)
		{
		case 1:
			printf("\n ALTAS\n");
			controllerGetClientes(arrayClientes,QTY_CLIENTES);
			break;
		case 2:
			printf("\nMODIFICAR\n");
			printClientes(arrayClientes,QTY_CLIENTES);
			if(existClientes(arrayClientes,QTY_CLIENTES)==0)
			{
				modificarClientes(arrayClientes,QTY_CLIENTES);
			}
			else
			{
				printf("Debe dar de alta un cliente vuelva a la opcion 1 \n");
			}
			break;
		case 3:
			printf("\nBAJAS\n");
			printClientes(arrayClientes,QTY_CLIENTES);
			if(existClientes(arrayClientes,QTY_CLIENTES)==0)
			{
				getDeleteClientes(arrayClientes,QTY_CLIENTES);
			}
			else
			{
				printf("Debe dar de alta un Cliente vuelva a la opcion 1 \n");
			}
			break;
		case 4:
				printClientes(arrayClientes,QTY_CLIENTES);
				addPedidos(arrayPedidos,QTY_PEDIDOS,arrayClientes,QTY_CLIENTES);
			break;
		case 5:

			modificarPedidos(arrayPedidos,QTY_PEDIDOS);
			break;
		case 6:
			cliente_ImprimirArrayConPendientes(arrayPedidos,QTY_PEDIDOS,arrayClientes,QTY_CLIENTES);
			break;
		case 7:
			pedidos_listarPendiente(arrayPedidos,QTY_PEDIDOS,arrayClientes,QTY_CLIENTES);
			break;
		case 8:
			pedido_ImprimirArrayProcesado(arrayPedidos,QTY_PEDIDOS,arrayClientes,QTY_CLIENTES);
			break;
		case 9:
			break;
		default:
			printf("\nError. Ingresa una opcion de 1 a 9");

		}
	}while(opcion != 9);

	return 0;
}
