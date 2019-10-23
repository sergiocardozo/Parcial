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

#define QTY_CLIENTES 6
#define QTY_PEDIDOS 9

int main()
{
	int contadorClientes=0;
	int contadorPedidos;
	int opcion;
	int opcionInformes = 's';
	char menuPrincipalMensaje[] ="\n1-MENU DE OPCIONES\
            \n\n1-ALTAS CLIENTES\
            \n2-MODIFICAR DATOS DE CLIENTE\
            \n3-BAJA DE CLIENTE\
            \n4-CREAR PEDIDO DE RECOLECCION\
	 	 	\n5 PROCESAR RESIDUOS \
			\n6 IMPRIMIR CLIENTES\
			\n7 IMPRIMIR PEDIDOS CLIENTES\
			\n8 IMPRIMIR PEDIDOS PROCESADOS\
		    \n9-INFORMES\
			\n10-SALIR\n\n\
			\nIngrese opcion:";

	eClientes arrayClientes[QTY_CLIENTES] = {
						{0,"Telefonica","30112233445","Lima 1234","CABA",0},
						{1,"DATASOFT","30445566776","Corrientes 2547","CABA",0},
						{2,"NESTLE","30889955219","cucha cucha 555","LANUS",0},
						{3,"TERRABUSI","30567814235","rocha 784","QUILMES",0},
						{4,"DIA","31545812533","Mitre 750","AVELLANEDA",0},
						{5,"QUILMES","30514857596","Crocha 741","QUILMES",0}

	};
	ePedidos arrayPedidos[QTY_PEDIDOS]={
			{0,0,1000,COMPLETADOS,200,145,230,0},
			{1,0,800,COMPLETADOS,210,45,30,0},
			{2,1,100,PENDIENTE,0,0,0,0},
			{3,1,300,PENDIENTE,0,0,0,0},
			{4,2,1500,COMPLETADOS,500,150,270,0},
			{5,3,750,COMPLETADOS,100,50,70,0},
			{6,0,200,PENDIENTE,0,0,0,0},
			{7,4,30,COMPLETADOS,10,5,3,0},
			{8,5,456,PENDIENTE,0,0,0,0},

	};

	/*cliente_Inicializar(arrayClientes,QTY_CLIENTES);
	pedidos_Inicializar(arrayPedidos,QTY_PEDIDOS);
	*/


	do
	{
		__fpurge(stdin);
		utn_getUnsignedInt(menuPrincipalMensaje,"\nError",1,sizeof(int),1,8,1,&opcion);



		switch(opcion)
		{
		case 1:
			printf("\n ALTAS\n");
			cliente_alta(arrayClientes,QTY_CLIENTES,&contadorClientes);
			break;
		case 2:
			printf("\nMODIFICAR\n");
			cliente_listar(arrayClientes,QTY_CLIENTES);
			cliente_modificar(arrayClientes,QTY_CLIENTES);
			break;
		case 3:
			printf("\nBAJAS\n");
			cliente_baja(arrayClientes,QTY_CLIENTES);
			break;
		case 4:
			printf("\nCREAR PEDIDO DE RECOLECCION");
			cliente_listar(arrayClientes,QTY_CLIENTES);
			pedidos_alta(arrayPedidos,QTY_PEDIDOS,&contadorPedidos);
			break;
		case 5:
			printf("PROCESAR RESIDUOS");
			pedidos_listar(arrayPedidos,QTY_PEDIDOS);
			pedidos_procesar(arrayPedidos,QTY_PEDIDOS);
			break;
		case 6:
			listarClientesPendiente(arrayClientes,QTY_CLIENTES,arrayPedidos,QTY_PEDIDOS);
			break;
		case 7:
			listar_pendientes(arrayClientes,QTY_CLIENTES,arrayPedidos,QTY_PEDIDOS);
			break;
		case 8:
			pedido_ImprimirArrayProcesado(arrayClientes,QTY_CLIENTES,arrayPedidos,QTY_PEDIDOS);
			break;
		case 9:
			printf("\nINFORMES");

			do
				{
					utn_getChar("\n\na. Cliente con mas pedidos pendientes.\
							\nb.Cliente con mas pedidos procesados.\
							\nc.Cliente con mas pedidos\
							\nd.Cliente que mas kilos reciclo\
							\ne.Cliente que menos reciclo\
							\nf.Cantidad de clientes que reciclaron mas de 1000 kg\
							\ng.Cantidad de clientes que reciclaron menos de 100 kg\
							\nh.Pedidos completados: ID, CUIT, % de plastico reciclado\
							\ni.Cantidad de pedidos pendientes por localidad\
							\nj.Cantidad de PP reciclado promedio por cliente\
							\nk.Cantidad de kilos reciclado de cada tipo de residuo por cliente\
							\nS. SALIR","\nOpcion invalida",'a','z',2,&opcionInformes);

					switch(opcionInformes)
					{
					case 'a':
						clienteMasPendientes(arrayClientes,QTY_CLIENTES,arrayPedidos,QTY_PEDIDOS);
						break;
					case 'b':
						clienteMasPedidosCompletos(arrayClientes,QTY_CLIENTES,arrayPedidos,QTY_PEDIDOS);
						break;
					case 'c':
						clienteMasPedidos(arrayClientes,arrayPedidos,QTY_CLIENTES,QTY_PEDIDOS);
						break;
					case 'd':
						clienteMasReciclo(arrayClientes,QTY_CLIENTES,arrayPedidos,QTY_PEDIDOS);
						break;
					case 'e':
						clienteMenosReciclo(arrayClientes,QTY_CLIENTES,arrayPedidos,QTY_PEDIDOS);
						break;
					case 'f':
						 clientesConMasDeMilKg(arrayClientes,QTY_CLIENTES,arrayPedidos,QTY_PEDIDOS);
						break;
					case 'g':
						clientesConMenosDeCienKg(arrayClientes,QTY_CLIENTES,arrayPedidos,QTY_PEDIDOS);
						break;
					case 'h':
						porcentajePedidosCompletados(arrayClientes,QTY_CLIENTES,arrayPedidos,QTY_PEDIDOS);
						break;
					case 'i':
						localidad_pendientes(arrayClientes,QTY_CLIENTES,arrayPedidos,QTY_PEDIDOS);
						break;
					case 'j':
						cliente_PPPromedio(arrayClientes,QTY_CLIENTES,arrayPedidos,QTY_PEDIDOS);
						break;
					case 'k':
						cliente_listar(arrayClientes,QTY_CLIENTES);
						cuitTipoDePlasticoReciclado(arrayClientes,QTY_CLIENTES,arrayPedidos,QTY_PEDIDOS);
						break;
					default:
						printf("\nOpcion incorrecta");
					}
				}while(opcionInformes == 's');
			break;
		case 10:
			break;
		default:
			printf("\nError. Ingresa una opcion de 1 a 9");

		}
	}while(opcion != 10);

	return 0;
}
