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
	int j;
	int i;

	    if(list != NULL && len > 0 && list2 != NULL && len2 > 0)
	    {
	    	for(i=0;i<len2;i++)
	    	    {
	    		if(list2[i].isEmpty==0 && list2[i].estado == 1)
	    		{
	    			for(j=0;j<len;j++)
	    			{
	    				if(list2[i].idClientes == list[j].idClientes
	    						&& list[j].isEmpty == 0)
	    				{
	    					printf( "\n ID: %d \n Cuit: %s\t Direccion: %s\t Kilos de HDPE: %.2f\t Kilos de LDPE: %.2f\tKilos de PP: %.2f\tEstado: Completado",
	    							list2[i].idPedidos,
									list[j].cuit,
									list[j].direccion,
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
	int j;
	int i;
	int posPendMax;


	    if(list != NULL && len > 0 && list2 != NULL && len2 > 0) //verifico que el array no de NULL y el largo sea mayor a 0
	    {
	    	for(i=0;i<len;i++)//recorre las posicion del array de clientes
	    	{
	    		if(list[i].isEmpty==1) // y verifica si el array tiene datos cargados y continua
	    		{
	    			continue;
	    		}
	    		if(list[i].isEmpty==0 && list[i].idClientes >= 0)//si el estado es activo y el id es mayor o igual a 0
	    		{
	    			for(j=0;j<len2;j++)// recorre el largo del array de pedidos
	    			{
	    				if(list[i].idClientes == list2[j].idClientes // y verifica si el id de clientes es igual a id de clientes de pedidos
	    						&& list2[j].isEmpty==0//si el status es activo y el estado esta en pendiente
								&& list2[j].estado==PENDIENTE)
	    				{
	    					pedidosPend++; // entonces suma los pedidos pendientes
	    				}
	    			}
	    			if(pedidosPend>pedidosPendMax)//si pedidos pendientes es mayor a el max de pedidos pendientes
	    			{
	    				pedidosPendMax = pedidosPend;
	    				posPendMax = i;
	    			}

	    			pedidosPend=0; // inicializa la cantidad de pedidos pendientes en 0

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
	int j;
	int i;
	int posCompletMax;


	    if(list != NULL && len > 0 && list2 != NULL && len2 > 0) //verifico si array clientes y pedidos es distinto de null y su largo mayor a 0
	    {
	    	for(i=0;i<len;i++) //recorro el array de clientes
	    	{
	    		if(list[i].isEmpty==1)//y verifico si isempty esta activo y continuo
	    		{
	    			continue;
	    		}
	    		if(list[i].isEmpty==0 && list[i].idClientes >= 0) //verifico si isempty esta con valores y el id de clientes empiece en 0
	    		{
	    			for(j=0;j<len2;j++) //recorro el largo del array de pendientes
	    			{
	    				if(list[i].idClientes == list2[j].idClientes //y verifico si el id de clientes es igual al id de pedidos
	    						&& list2[j].isEmpty==0 //si el estado es activo
								&& list2[j].estado==COMPLETADOS) // y si el estado esta en completado
	    				{
	    					pedidosCompletados++; // y sumo en 1 los pedidos completados
	    				}
	    			}

	    			if(pedidosCompletados>pedidosCompletMax) // verifico si pedidos completados es mayor a los pedidos completados maximos
	    			{
	    				pedidosCompletMax = pedidosCompletados; // a pedidos completados maximo le asigo los pedidos completados
	    				posCompletMax = i; //y a la posicion completada mayor le asigno la posicion
	    			}

	    			pedidosCompletados=0; // inicializo los pedidos completados en 0

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
    int j;
    int i;
    int posMax;


    if(list != NULL && len > 0 && list2 != NULL && len2 > 0) // verifico el array cliente y pedidos si es distinto de null o mayor al largo
    {
    	for(i=0;i<len;i++) // recorro el array de clientes
    	{
    		if(list[i].isEmpty==1) // busco si hay lugar inicializado
    		{
    			continue;
    		}
    		if(list[i].isEmpty==0 && list[i].idClientes >= 0) //verifico si es estado esta activo y si el id de clientes inicia en 0
    		{
    			for(j=0;j<len2;j++) //recorro el array de pedidos
    			{
    				if(list[i].idClientes == list2[j].idClientes // verifico si el id de clientes es igual al id clientes de pedidos es igual
    						&& list2[j].isEmpty==0 // y si el estado es activo
							&& (list2[j].estado==PENDIENTE || list2[j].estado==COMPLETADOS)) // y si el estado es completado o pendiente
    				{
    					pedidos++; // sumo todos los pedidos
    				}
    			}

    			if(pedidos>pedidosMax) //si la cantidad de pedidos es mayor a pedidosmaximo
    			{
    				pedidosMax = pedidos; // pedidosmaximo es igual a la cantidad de pedidos
    				posMax = i; // y a posicion maximo le asigno el lugar que ocupa en el array
    			}

    			pedidos=0; // inicializo los pedidos en 0

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
    int j;
    int i;
    int posMax;


    if(list != NULL && len > 0 && list2 != NULL && len2 > 0) // verifico el array cliente y pedidos si es distinto de null o mayor al largo
    {
    	for(i=0;i<len;i++)//recorro el array de pedidos
    	{
    		if(list[i].isEmpty==1) // verifico si se inicializo el array de clientes y continuo
    		{
    			continue;
    		}
    		if(list[i].isEmpty==0 && list[i].idClientes >= 0) // si el estado es activo y el id de clientes es mayor o igual a 0
    		{
    			for(j=0;j<len2;j++) // recorro el array de pedidos
    			{
    				if(list[i].idClientes == list2[j].idClientes //si el id del array de clientes es igual al de pedidos
    						&& list2[j].isEmpty==0// y si el estado es ocupado
							&& list2[j].estado==COMPLETADOS) // y si el estado es completados
    				{
    					kilosRecic=0; // inicializo los kilos reciclados en 0
    					kilosRecic = kilosRecic + list2[j].HDPE + list2[j].LPDE + list2[j].PP;// y le asigno la suma de los tipos de residuos
    				}
    			}

    			if(kilosRecic>kilosRecicMax) // si la cantidad de kilos reciclados es mayor al maximo de kilos reciclados
    			{
    				kilosRecicMax = kilosRecic; // al maximo de kilos reciclados le asigno los kilos reciclados
    				posMax = i; // y a la posicion maximo le asigno la posicion que ocupa en el array
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
    int j;
    int i;
    int posMin;


    if(list != NULL && len > 0 && list2 != NULL && len2 > 0)// verifico si el array de clientes y el de pedidos es distinto a 0 y si el largo es mayor a 0
    {
    	for(i=0;i<len;i++)// recorro el array de clientes
    	    {
    		if(list[i].isEmpty==1) // verifico si se inicializo el array y continuo
    		{
    			continue;
    		}
    		if(list[i].isEmpty==0 && list[i].idClientes >= 0) // si el array esta ocupado y el id de clientes es mayor o igual a 0
    		{
    			for(j=0;j<len2;j++)// recorro el array de pedidos
    			{
    				if(list[i].idClientes == list2[j].idClientes // si el id del array de clientes es igual al id de clientes de pedidos
    						&& list2[j].isEmpty==0 // y el estado es ocupado
							&& list2[j].estado==COMPLETADOS)// y el estado es completados
    				{
    					kilosRecic = 0; // inicializo los kilos reciclados en 0
    					kilosRecic = kilosRecic + list2[j].HDPE + list2[j].LPDE + list2[j].PP;//y le asigo a kilos reciclados la suma de los residuos
    				}
    			}

    			if(kilosRecic<kilosRecicMin)//verifico si los kilos reciclados es menor al minimo reciclado
    			{
    				kilosRecicMin = kilosRecic; // le asigno los kilos reciclados a la variable kilosreciclados minimo
    				posMin = i;//le asigno a la posicion minima el lugar en el array
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

    if(list != NULL && len > 0 && list2 != NULL && len2 > 0)// verifico si el array de clientes y el de pedidos es distinto a null y si su largo es mayor a 0
    {
    	for(i=0;i<len;i++)// recorro el array de clientes
    	{
    		if(list[i].isEmpty==1)//si se inicializo el array y continuo
    		{
    			continue;
    		}
    		if(list[i].isEmpty==0 && list[i].idClientes >= 0)// si el estado es ocupado y si el id de clientes es mayor o igual a 0
    		{
    			for(j=0;j<len2;j++)//recorro el array de pedidos
    			{
    				if(list[i].idClientes == list2[j].idClientes//si el id de clientes es igual al id de clientes del array de pedidos
    						&& list2[j].isEmpty==0// y si el estado es ocupado
							&& list2[j].estado==COMPLETADOS)// y si el estado es completado
    				{
    					kilosRecic=0;// inicializo los kilos reciclados en 0
    					kilosRecic = kilosRecic + list2[j].HDPE	+ list2[j].LPDE + list2[j].PP;// a los kilos reciclados le asigno la suma de los residuos
    				}
    			}

    			if(kilosRecic>1000) // si la suma es mayor a 1000
    			{
    				cantCliente++;//cuento la cantidad de clientes
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

    if(list != NULL && len > 0 && list2 != NULL && len2 > 0)// verifico si el array de pedidos y clientes es distinto de 0 y si el largo es mayor a 0
    {
    	for(i=0;i<len;i++)//recorro el array de clientes
    	{
    		if(list[i].isEmpty==1)//verifico si se inicializo el array
    		{
    			continue;//continuo
    		}
    		if(list[i].isEmpty==0 && list[i].idClientes >= 0)// verifico que el estado sea ocupado y el id del array de clientes es mayor o igual a 0
    		{
    			for(j=0;j<len2;j++)//recorro el array de pedidos
    			{
    				if(list[i].idClientes == list2[j].idClientes//si el id de clientes es igual al id del array de pedidos
    						&& list2[j].isEmpty==0//y el estado es ocupado
							&& list2[j].estado==1)//y el estado es completado
    				{
    					kilosRecic = 0;//inicializo los kilos reciclados en 0
    					kilosRecic = kilosRecic + list2[j].HDPE + list2[j].LPDE + list2[j].PP;//a kilos reciclados le asigno la suma de residuos
    				}
    			}

    			if(kilosRecic<100 && list2[j].idClientes>=0)// verifico si los kilos reciclados es menor a 100 y el id clientes del array de pedidos es mayor o igual a 0
    			{
    				cantCliente++;//cuento la cantidad de clientes
    				kilosRecic=100;// le asigno el valor maximo a los kilos reciclados que es 100
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

    if(list != NULL && len > 0 && list2 != NULL && len2 > 0)//verifico si el array cliente y pedidos es distinto de null y el largo es mayor a 0
    {
    	for(i=0;i<len2;i++)//recorro el array de pedidos
    	{
    		if(list2[i].isEmpty==0 && list2[i].estado == COMPLETADOS)//verifico si tiene valores y el estado sea completado
    		{
    			for(j=0;j<len;j++)//recorro el array de clientes
    			{
    				if(list2[i].idClientes == list[j].idClientes//verifico si el array de pedidos es igual al id del array de clientes
    						&& list[j].isEmpty == 0// que el estado del array de clientes sea ocupado
							&& list[j].idClientes >= 0)//y que el id de clientes sea mayor o igual a 0
    				{

    					acumulador = 0;//inicializo el acumulador en 0
    					porcentaje = 0;//inicializo el porcentaje en 0

    					acumulador = list2[i].HDPE + list2[i].LPDE + list2[i].PP; // le asigno al acumulado la suma de los tipos de residuos
    					porcentaje = acumulador / list2[i].kilos;// le asigno al porcentaje la division del acumulado divido los kilos a procesar
    					porcentaje = porcentaje * 100;//y lo multiplico por 100

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
    int i;
    int j;
    int cantPedidos = 0;
    char localidad[50];
    if(list != NULL && len > 0 && list2 != NULL && len2 > 0)//verifico que el array de clientes y pedidos sea distinto de null y el largo mayor a 0
    {
    	utn_getTexto("\nIngrese localidad: ","\nError",1,50,2,localidad);// validacion de la localidad con funcion utngettexto
    	if(clienteBuscarLocalidad(list, len,localidad,&j)== -1)//verifico que el string exista si es falso
    	{
    		printf("\nLa localidad ingresa no existe en el registro");//imprimo que no existe
    	}
    	else//si es verdadero entro al else
    	{
    		for( i=0;i<len;i++)// y recorro el array de clientes
    		{
    			if(list[i].isEmpty==0 && strcmp(list[i].localidad,localidad)==0) //verifico si el estado es ocupado y comparo la localidad ingresada con la localidad del array si es verdadero
    			{
    				for(j=0;j<len2;j++)// recorro el array de pedidos
    				{
    					if(list[i].idClientes == list2[j].idClientes//y verifico si el del array de clientes es igual al array de pedidos
    							&& list2[j].isEmpty == 0//si el estado es ocupado
								&& list2[j].estado == 0)//y si el estado es pendiente
    					{
    						cantPedidos++;//sumo la cantidad de pedidos
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

int cuitTipoDePlasticoReciclado(eClientes list[], int len, ePedidos list2[], int len2)
{
	int retorno = -1;
	int i;
	int j;
	char cuit[13];
	int posicion;
	int opcion;
	int acumulador = 0;
	if(list != NULL && len>0 && list2 != NULL && len2 > 0)//verifico si el array de clientes y de pedidos es distinto de null y el valor sea mayor a 0
	{
		utn_getTexto("\nIngrese cuit: ","\nError",1,13,2,cuit);//le pido que ingrese el cuit y lo verifico
		if(clienteBuscarCuit(list, len,cuit,&posicion)== -1)//busco el cuit en el array y si el resultado es falso
		{
			printf("\nEl cuit ingresado no existe en el registro");// no existe el cuit

		}
		else//si es verdadero entro al else
		{
			for( i=0;i<len;i++)//y recorro el array de clientes
			{
				if(list[i].isEmpty==0 && strcmp(list[i].cuit,cuit)==0)//si el estado es ocupado y comparo el cuit del array con el cuit ingresado sea verdadero
				{

					utn_getUnsignedInt("\nIngrese el plastico a mostrar 1. HDPE 2. LDPE 3. PP\nElija una opcion: ", "Error",1,sizeof(int),1,3,2,&opcion);//pido que ingrese que tipo de residuo desea ver
							switch(opcion)//entro al switch
							{
							case 1:
								for(j=0;j<len2;j++)//recorro el array de pedidos
								{
									if(list[i].idClientes == list2[j].idClientes//si el id del array de clientes es igual al de pedidos
											&& list2[j].isEmpty == 0 //y si el estado es ocupado
											&& list2[j].estado == COMPLETADOS)//y el estado es completado
									{
										acumulador = acumulador + list2[j].HDPE;//le asigno al acumulador los valores del residuos las veces que se haya procesado

									}
								}
								printf("\nEl cliente con cuit: %s reciclo un total de %.2f de residuos HDPE",list[i].cuit,(float)acumulador);
								break;
							case 2:
								for(j=0;j<len2;j++) // recorro el array de pedidos
								{
									if(list[i].idClientes == list2[j].idClientes // si el id del array clientes es igual al id del array pedidos
											&& list2[j].isEmpty == 0//y el estado ocupado
											&& list2[j].estado == COMPLETADOS)//y el estado sea completado
									{
										acumulador = acumulador + list2[j].LPDE;//acumulador mas los kilos del tipo de residuo
									}
								}
								printf("\nEl cliente con cuit: %s reciclo un total de %.2f de residuos LPDE",list[i].cuit,(float)acumulador);//casteo para que sea float el valor del acumulador
								break;
							case 3:
								for(j=0;j<len2;j++)//recorro el array de pedidos
								{
									if(list[i].idClientes == list2[j].idClientes//si el id del array clientes es igual al de pedidos
											&& list2[j].isEmpty == 0// isempty este ocupado
											&& list2[j].estado == COMPLETADOS)//y el estado sea procesado
									{
										acumulador = acumulador + list2[j].PP;//acumulo los kilos del tipo de residuo y los sumo
									}
								}
								printf("\nEl cliente con cuit: %s reciclo un total de %.2f de residuos PP",list[i].cuit,(float)acumulador);//parseo el acumulador para que me de un numero flotante
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
	return retorno;

}



