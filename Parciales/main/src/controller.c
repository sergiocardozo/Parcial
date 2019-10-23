/*
 * controller.c
 *
 *  Created on: 16 oct. 2019
 *      Author: sergio
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "pedidos.h"
#include "utn.h"


int listarClientesPendiente(eClientes list[], int len, ePedidos list2[], int len2)
{
	int i;
	int auxPos;
	int contadorPendientes = 0;
	int retorno = -1;

	if(list != NULL && len>0 && list2 != NULL && len2 >0)
	{
		printf("\nID: -- Nombre de la Empresa:  -- cuit:  -- Direccion:	--	Localidad:  -- Pendientes: \n");
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == 1)
			{
				continue;
			}
			else
			{
				for(auxPos=0;auxPos<len2;auxPos++)
				{
					if(list[i].idClientes == list2[auxPos].idClientes
							&& list2[auxPos].isEmpty==0
							&& list2[auxPos].estado==PENDIENTE)
					{
						contadorPendientes++;
					}
				}
				list2[i].idClientes = list[i].idClientes;

				printf("\n\n%4d		%-20s		%-10s		%-10s		%-25s		%4d",list[i].idClientes,
																		list[i].nombreEmpresa,
																		list[i].cuit,
																		list[i].direccion,
																		list[i].localidad,
																		contadorPendientes);
				contadorPendientes = 0;

			}
		}
		retorno = 0;
	}
	return retorno;
}

int listar_pendientes(eClientes list[], int len, ePedidos list2[], int len2)
{
    int retorno=-1;
    int posicion,i;

    if(list != NULL && len > 0 && list2 != NULL && len2 > 0)
    {

		for(i=0;i<len2;i++)
    	    {
    			if(list2[i].isEmpty==0 && list2[i].estado == 0)
    	          {
    				for(posicion=0;posicion<len;posicion++)
    				{
    					if(list2[i].idClientes == list[posicion].idClientes
    							&& list[posicion].isEmpty == 0)
    					{
    						printf( "\n ID: %d\t Cuit: %s\tDireccion: %s\t Kilos: %.2f\t Estado: Pendiente",
									list2[i].idPedidos,
    								list[posicion].cuit,
 									list[posicion].direccion,
									list2[i].kilos);
    					}
    				}
    	          }
    	    }
    	retorno=0;
    }
    return retorno;
}

int pedido_ImprimirArrayProcesado(eClientes list[], int len, ePedidos list2[], int len2)
{
	int retorno=-1;
	int posicion;
	int i;

	    if(list != NULL && len > 0 && list2 != NULL && len2 > 0)
	    {
	    	for(i=0;i<len2;i++)
	    	    {
	    		if(list2[i].isEmpty==0 && list2[i].estado == 1)
	    		{
	    			for(posicion=0;posicion<len;posicion++)
	    			{
	    				if(list[i].idClientes == list[posicion].idClientes
	    						&& list[posicion].isEmpty == 0)
	    				{
	    					printf( "\n ID: %d \n Cuit: %s\t Direccion: %s\t Kilos de HDPE: %.2f\t Kilos de LDPE: %.2f\tKilos de PP: %.2f\tEstado: Completado",
	    							list2[i].idPedidos,
									list[posicion].cuit,
									list[posicion].direccion,
									list2[i].HDPE,
									list2[i].LPDE,
									list2[i].PP);

	    				}
	    			}
	    		}
	    	    }
	    	retorno=0;
	    }
	    return retorno;
}


int clienteMasPendientes(eClientes list[], int len, ePedidos list2[], int len2)
{
	int retorno=-1;
	int pedidosPend = 0;
	int pedidosPendMax = 0;
	int posicion;
	int i;
	int posPendMax;
	int flag = 0;

	    if(list != NULL && len > 0 && list2 != NULL && len2 > 0)
	    {
	    	for(i=0;i<len;i++)
	    	    {
	    			if(list[i].isEmpty==1)
	    	          {
	    	            continue;
	    	          }
	                else if(list[i].isEmpty==0 && list[i].idClientes >= 0)
	    	            {
	    	            	for(posicion=0;posicion<len2;posicion++)
	    	            	{
	    	            		if(list[i].idClientes == list2[posicion].idClientes
	    	            			&& list2[posicion].isEmpty==0
									&& list2[posicion].estado==PENDIENTE)
	    	            		{
	    	            			pedidosPend++;
	    	            		}
	    	            	}

	    	            	if(flag==0)
	    	            	{
	    	            		pedidosPendMax = pedidosPend;
	    	            		posPendMax = i;
	    	            		flag++;
	    	            	}

	    	            	if(pedidosPend>pedidosPendMax)
	    	            	{
	    	            		pedidosPendMax = pedidosPend;
	    	            		posPendMax = i;
	    	            	}

	    	            	pedidosPend=0;

	    	            }

	    	        }

	    	printf("\nEl cliente con mas pedidos pendientes es %s\tCon una cantidad de %d pedidos pendientes",
	    																					list[posPendMax].nombreEmpresa,
																							pedidosPendMax);
	        retorno=0;
	    }
	    return retorno;
}

int clienteMasPedidosCompletos(eClientes list[], int len, ePedidos list2[], int len2)
{
	int retorno=-1;
	int pedidosCompletados = 0;
	int pedidosCompletMax = 0;
	int posicion;
	int i;
	int posCompletMax;
	int flag = 0;

	    if(list != NULL && len > 0 && list2 != NULL && len2 > 0)
	    {
	    	for(i=0;i<len;i++)
	    	{
	    		if(list[i].isEmpty==1)
	    		{
	    			continue;
	    		}
	    		if(list[i].isEmpty==0 && list[i].idClientes >= 0)
	    		{
	    			for(posicion=0;posicion<len2;posicion++)
	    			{
	    				if(list[i].idClientes == list2[posicion].idClientes
	    						&& list2[posicion].isEmpty==0
								&& list2[posicion].estado==COMPLETADOS)
	    				{
	    					pedidosCompletados++;
	    				}
	    			}

	    			if(flag==0)
	    			{
	    				pedidosCompletMax = pedidosCompletados;
	    				posCompletMax = i;
	    				flag++;
	    			}

	    			if(pedidosCompletados>pedidosCompletMax)
	    			{
	    				pedidosCompletMax = pedidosCompletados;
	    				posCompletMax = i;
	    			}

	    			pedidosCompletados=0;

	    		}

	    	}

	    	printf("\nEl cliente con mas pedidos procesados es %s\tCon una cantidad de %d pedidos completados",
	    																								list[posCompletMax].nombreEmpresa,
																										pedidosCompletMax);
	    	retorno=0;
	    }
	    return retorno;
}

int clienteMasPedidos(eClientes list[],ePedidos list2[], int len, int len2)
{
    int retorno=-1;
    int pedidos = 0;
    int pedidosMax = 0;
    int posicion;
    int i;
    int posMax;
    int flag = 0;

    if(list != NULL && len > 0 && list2 != NULL && len2 > 0)
    {
    	for(i=0;i<len;i++)
    	{
    		if(list[i].isEmpty==1)
    		{
    			continue;
    		}
    		if(list[i].isEmpty==0 && list[i].idClientes >= 0)
    		{
    			for(posicion=0;posicion<len2;posicion++)
    			{
    				if(list[i].idClientes == list2[posicion].idClientes
    						&& list2[posicion].isEmpty==0
							&& (list2[posicion].estado==PENDIENTE || list2[posicion].estado==COMPLETADOS))
    				{
    					pedidos++;
    				}
    			}

    			if(flag==0)
    			{
    				pedidosMax = pedidos;
    				posMax = i;
    				flag++;
    			}

    			if(pedidos>pedidosMax)
    			{
    				pedidosMax = pedidos;
    				posMax = i;
    			}

    			pedidos=0;

    		}

    	}

    	printf("\nEl cliente que hizo mas pedidos es %s\tRealizo %d pedidos",
    														list[posMax].nombreEmpresa,
															pedidosMax);
        retorno=0;
    }
    return retorno;
}

int clienteMasReciclo(eClientes list[], int len, ePedidos list2[], int len2)
{
    int retorno=-1;
    int kilosRecic = 0;
    int kilosRecicMax = 0;
    int posicion;
    int i;
    int posMax;
    int flag = 0;

    if(list != NULL && len > 0 && list2 != NULL && len2 > 0)
    {
    	for(i=0;i<len;i++)
    	{
    		if(list[i].isEmpty==1)
    		{
    			continue;
    		}
    		if(list[i].isEmpty==0 && list[i].idClientes >= 0)
    		{
    			for(posicion=0;posicion<len2;posicion++)
    			{
    				if(list[i].idClientes == list2[posicion].idClientes
    						&& list2[posicion].isEmpty==0
							&& list2[posicion].estado==COMPLETADOS)
    				{
    					kilosRecic=0;
    					kilosRecic = kilosRecic + list2[posicion].HDPE + list2[posicion].LPDE + list2[posicion].PP;
    				}
    			}
    			if(flag==0)
    			{
    				kilosRecicMax = kilosRecic;
    				posMax = i;
    				flag++;
    			}
    			if(kilosRecic>kilosRecicMax)
    			{
    				kilosRecicMax = kilosRecic;
    				posMax = i;
    			}

    		}

    	}

    	printf("\nEl cliente que mas reciclo es %s\tReciclo: %d kilos de residuos\n",
    																				list[posMax].nombreEmpresa,
																					kilosRecicMax);
        retorno=0;
    }
    return retorno;
}

int clienteMenosReciclo(eClientes list[], int len, ePedidos list2[], int len2)
{
    int retorno=-1;
    int kilosRecic = 0;
    int kilosRecicMin = 0;
    int posicion;
    int i;
    int posMin;
    int flag = 0;

    if(list!=NULL && len>0)
    {
    	for(i=0;i<len;i++)
    	    {
    		if(list[i].isEmpty==1)
    		{
    			continue;
    		}
    		if(list[i].isEmpty==0 && list[i].idClientes >= 0)
    		{
    			for(posicion=0;posicion<len2;posicion++)
    			{
    				if(list[i].idClientes == list2[posicion].idClientes
    						&& list2[posicion].isEmpty==0
							&& list2[posicion].estado==COMPLETADOS)
    				{
    					kilosRecic = 0;
    					kilosRecic = kilosRecic + list2[posicion].HDPE
    	            									+ list2[posicion].LPDE
														+ list2[posicion].PP;
    				}
    			}

    			if(flag==0)
    			{
    				kilosRecicMin = kilosRecic;
    				posMin = i;
    				flag++;
    			}

    			if(kilosRecic<kilosRecicMin)
    			{
    				kilosRecicMin = kilosRecic;
    				posMin = i;
    			}


    		}

    	    }

    	printf("\nEl cliente que menos reciclo es: %s\tReciclo %d kilos de residuos.",
    																	list[posMin].nombreEmpresa,
																		kilosRecicMin);
        retorno=0;
    }
    return retorno;
}

int clientesConMasDeMilKg(eClientes list[], int len, ePedidos list2[], int len2)
{
    int retorno=-1;
    int kilosRecic = 0;
    int cantCliente = 0;
    int j;
    int i;

    if(list != NULL && len > 0 && list2 != NULL && len2 > 0)
    {
    	for(i=0;i<len;i++)
    	{
    		if(list[i].isEmpty==1)
    		{
    			continue;
    		}
    		if(list[i].isEmpty==0 && list[i].idClientes >= 0)
    		{
    			for(j=0;j<len2;j++)
    			{
    				if(list[i].idClientes == list2[j].idClientes
    						&& list2[j].isEmpty==0
							&& list2[j].estado==COMPLETADOS)
    				{
    					kilosRecic=0;
    					kilosRecic = kilosRecic + list2[j].HDPE	+ list2[j].LPDE + list2[j].PP;
    				}
    			}

    			if(kilosRecic>1000)
    			{
    				cantCliente++;
    			}

    		}

    	}

    	printf("\nHay %d que reciclaron mas de 1000 kg.",cantCliente);
        retorno=0;
    }
    return retorno;
}


int clientesConMenosDeCienKg(eClientes list[], int len, ePedidos list2[], int len2)
{
    int retorno=-1;
    int kilosRecic=0;
    int cantCliente = 0;
    int j;
    int i;

    if(list != NULL && len > 0 && list2 != NULL && len2 > 0)
    {
    	for(i=0;i<len;i++)
    	{
    		if(list[i].isEmpty==1)
    		{
    			continue;
    		}
    		if(list[i].isEmpty==0 && list[i].idClientes >= 0)
    		{
    			for(j=0;j<len2;j++)
    			{
    				if(list[i].idClientes == list2[j].idClientes
    						&& list2[j].isEmpty==0
							&& list2[j].estado==1)
    				{
    					kilosRecic = 0;
    					kilosRecic = kilosRecic + list2[j].HDPE + list2[j].LPDE + list2[j].PP;
    				}
    			}

    			if(kilosRecic<100 && list2[j].idClientes>0)
    			{
    				cantCliente++;
    				kilosRecic=100;
    			}

    		}

    	}

    	printf("\nHay %d que reciclaron menos de 100 kg.\n",cantCliente);
        retorno=0;
    }
    return retorno;
}

int porcentajePedidosCompletados(eClientes list[], int len, ePedidos list2[], int len2)
{
    int retorno=-1;
    int j;
    int i;
    float porcentaje;
    int acumulador;

    if(list != NULL && len > 0 && list2 != NULL && len2 > 0)
    {
    	for(i=0;i<len2;i++)
    	{
    		if(list2[i].isEmpty==0 && list2[i].estado == COMPLETADOS)
    		{
    			for(j=0;j<len;j++)
    			{
    				if(list2[i].idClientes == list[j].idClientes
    						&& list[j].isEmpty == 0
							&& list[j].idClientes >= 0)
    				{

    					acumulador = 0;
    					porcentaje = 0;

    					acumulador = list2[i].HDPE + list2[i].LPDE + list2[i].PP;
    					porcentaje = acumulador / list2[i].kilos;
    					porcentaje = porcentaje * 100;

    					printf("\nID: %d\tCuit: %s\tPorcentaje de residuos reciclados: %.2f\n",
															list2[i].idPedidos,
															list[j].cuit,
															porcentaje);

    				}
    			}
    		}


    	}
    	retorno=0;
    }
    return retorno;
}

int localidad_pendientes(eClientes list[], int len, ePedidos list2[], int len2)
{
    int retorno=-1;
    int j;
    int cantPedidos = 0;
    char localidad[50];
    if(list != NULL && len > 0 && list2 != NULL && len2 > 0)
    {
    	utn_getTexto("\nIngrese localidad: ","\nError",1,50,2,localidad);
    	if(clienteBuscarLocalidad(list, len,localidad,&j)== -1)
    	{
    		printf("\nLa localidad ingresa no existe en el registro");
    	}
    	else
    	{
    		for(int i=0;i<len;i++)
    		{
    			if(list[i].isEmpty==0 && strcmp(list[i].localidad,localidad)==0)
    			{
    				for(j=0;j<len2;j++)
    				{
    					if(list[i].idClientes == list2[j].idClientes
    							&& list2[j].isEmpty == 0
								&& list2[j].estado == 0)
    					{
    						cantPedidos++;
    					}
    				}

    			}
    		}
    	}
    	printf("\nLa localidad %s \tTiene %d pedidos pendientes.\n", localidad, cantPedidos);
      	retorno=0;
    }
    return retorno;
}

int cliente_PPPromedio(eClientes list[], int len, ePedidos list2[], int len2)
{
	 int retorno=-1;
	 int kilosRecic = 0, cantClientes = 0,promedio = 0;
	 int j;
	 int i;
	 int idAnterior = 0;

	 if(list != NULL && len > 0 && list2 != NULL && len2 > 0)
	 {
		 for(i=0;i<len;i++)
		 {
			 if(list[i].isEmpty==1)
			 {
				 continue;
			 }
			 if(list[i].isEmpty==0 && list[i].idClientes >= 0)
			 {
				 for(j=0;j<len;j++)
				 {
					 if(list[i].idClientes == list2[j].idClientes
							 && list2[j].isEmpty==0
							 && list2[j].estado==COMPLETADOS)
					 {
						 if(idAnterior!=list2[j].idClientes)
						 {
							 idAnterior = list2[j].idClientes;
							 cantClientes++;
						 }
						 kilosRecic = kilosRecic + list2[j].PP;
					 }

				 }

				 promedio = kilosRecic/cantClientes;

			 }

		 }

		 printf("\nPromedio de kilos de PP por cliente: %d",
				 	 	 	 	 	 	 	 	 	 	 	 promedio);
	        retorno=0;
	    }
	    return retorno;
}

int cuitTipoDePlasticoReciclado(eClientes list[], int len, ePedidos list2[], int len2)
{
	int retorno = -1;
	int i;
	int j;
	char cuit[13];
	int posicion;
	int opcion;
	int acumulador = 0;
	if(list != NULL && len>0 && list2 != NULL && len2 > 0)
	{
		utn_getTexto("\nIngrese cuit: ","\nError",1,13,2,cuit);
		if(clienteBuscarCuit(list, len,cuit,&posicion)== -1)
		{
			printf("\nEl cuit ingresado no existe en el registro");

		}
		else
		{
			for( i=0;i<len;i++)
			{
				if(list[i].isEmpty==0 && strcmp(list[i].cuit,cuit)==0)
				{

						if(list2[i].idClientes == list[i].idClientes
						        					&& list2[i].isEmpty == 0
						    						&& list2[i].estado == COMPLETADOS)

						{
							utn_getUnsignedInt("\nIngrese el plastico a mostrar 1. HDPE 2. LDPE 3. PP\nElija una opcion: ", "Error",1,sizeof(int),1,3,2,&opcion);

							switch(opcion)
							{
							case 1:
								for(j=0;j<len2;j++)
								{
								acumulador += list2[j].HDPE;
								}
								printf("\nEl cliente con cuit: %s reciclo un total de %.2f de residuos HDPE",list[i].cuit,(float)acumulador);
								break;
							case 2:
								acumulador += list2[i].LPDE;
								printf("\nEl cliente con cuit: %s reciclo un total de %.2f de residuos LPDE",list[j].cuit,(float)acumulador);
								break;
							case 3:
								acumulador += list2[i].PP;
								printf("\nEl cliente con cuit: %s reciclo un total de %.2f de residuos PP",list[j].cuit,(float)acumulador);
								break;
							default:
								printf("\nOpcion Incorrecta");
								break;
							}

						}
						retorno = 0;


				}
			}

		}

	}
	return retorno;
}


