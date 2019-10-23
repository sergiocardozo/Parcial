#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "utn.h"
#include "pedidos.h"

int initClientes(eClientes* list, int len)
{

	int i;
	    int ret= -1;
	    if(list!=NULL&&len>0)
	    {
	        for(i=0;i<len;i++)
	        {
	            list[i].idClientes=0;
	            list[i].isEmpty = 0;
	            strcpy(list[i].nombreEmpresa,"");
	            strcpy(list[i].cuit,"");
	            strcpy(list[i].direccion,"");
	            strcpy(list[i].localidad,"");

	        }
	        ret=0;
	    }
	    return ret;
}

int findEmptySpaceClientes(eClientes* list, int len)
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

int existClientes(eClientes* list, int len)
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

int addClientes(eClientes* list, int len, int id, char nombreEmpresa[], char cuit[], char direccion[], char localidad[])
{

    list[id].idClientes = id;
    strcpy(list[id].nombreEmpresa, nombreEmpresa);
    strcpy(list[id].cuit, cuit);
    strcpy(list[id].direccion, direccion);
    strcpy(list[id].localidad, localidad);
    list[id].isEmpty = 1;
    return id;
}
int controllerGetClientes(eClientes* list, int len)
{
	char auxNombreEmp[50];
	char auxCuit[13];
	char auxDireccion[50];
	char auxLocalidad[50];
	int ret = -1;
	int espacioLibre;
	espacioLibre = findEmptySpaceClientes(list,len);

	if(espacioLibre != -1)
	{
		utn_getName("\nIngrese Nombre de la Empresa: ","\nNo es un nombre valido",1,50,3,auxNombreEmp);
		utn_getTexto("\nIngrese Cuit de la empresa: ","\nNo es un cuit valido",1,13,3,auxCuit);
		utn_getTexto("\nIngrese direccion del cliente: ","\nNo es una direccion valido",1,50,3,auxDireccion);
		utn_getName("\nIngrese localidad del cliente: ","\nNo es una localidad valido",1,50,3,auxLocalidad);

		addClientes(list, len, espacioLibre, auxNombreEmp, auxCuit, auxDireccion, auxLocalidad);
	}
	else
	{
		printf("No se pueden cargar mas clientes ");
	}
	return ret;
}

int modificarClientes(eClientes* list, int len)
{
    int ret = -1;
    int modify;
    int findClientes;
    char auxDireccion[50];
    char auxLocalidad[50];
    int id;

    printf("Ingrese ID del cliente a modificar: ");
    scanf("%d", &id);

    findClientes = findClientesById(list, len, id);

    if (findClientes > 0)
    {
        do
        {
            printf("\n---------------------------------------- \n");
            printf("1- Direccion \n2- Localidad \n3- Salir  \n");
            printf("------------------------------------------ \n");
            scanf("%d", &modify);

            switch(modify)
            {
            case 1:
            	utn_getTexto("\nIngrese direccion del cliente: ","\nNo es una direccion valido",1,50,3,auxDireccion);
                strcpy(list[findClientes].direccion, auxDireccion);
                break;
            case 2:
            	utn_getName("\nIngrese localidad del cliente: ","\nNo es una localidad valido",1,50,3,auxLocalidad);
                strcpy(list[findClientes].localidad, auxLocalidad);
                break;
            default:
                printf("Ingrese una opcion del 1 al 3: ");
            }
        }while (modify != 3);

        printf("Se han realizado las modificaciones correctamente \n");
    }
    else
    {
        printf("No se encontro Cliente con ese ID \n");
    }
   return ret;
}

int findClientesById(eClientes* list, int len, int id)
{
    int ret = -1;
    int i;

    if (list != NULL && len > 0)
    {
        for (i=1; i<len; i++)
        {
            if (list[i].isEmpty == 1 && list[i].idClientes == id)
            {
                return i;
            }
        }
    }
    return ret;
}

int removeClientes (eClientes* list, int len, int id)
{
    int findEmployee;

    findEmployee = findClientesById(list, len, id);

    if (findEmployee > 0)
    {
        list[findEmployee].isEmpty = -1;
        printf("Empleado eliminado con exito \n");
    }
    else
    {
        printf("No se ha encontrado empleado con ese ID \n");
    }

    return findEmployee;
}

int getDeleteClientes(eClientes* list,int len)
{
    int ret=-1;
    int auxId;


    if(list!=NULL && len > 0)
    {
    	utn_getUnsignedInt("\nIngrese id: ","\nValor invalido",1,sizeof(int),0,100,10,&auxId);
    	if(findClientesById(list,len,auxId)>=0)
    	{
    		removeClientes(list,len,auxId);
    		ret=0;
    	}
    	else
    	{
    		printf("\nId invalido");
    	}
    }
    return ret;
}


int printClientes (eClientes* listClientes, int lenClientes)
{
    int ret = -1;
    int i;

    if(lenClientes > 0)
    {
        printf("ID\tNombre Empresa\t\tCuit\tDomicilio\t\tLocalidad \n");

        for(i=0; i<lenClientes; i++)
        {
            if (listClientes[i].isEmpty == 1)
            {

                printf("%d\t%s\t\t%s\t\t\t%s\t\t%s \n", listClientes[i].idClientes,
                										listClientes[i].nombreEmpresa,
                										listClientes[i].cuit,
														listClientes[i].direccion,
														listClientes[i].localidad);
            }
        }
        ret = 0;
    }
    return ret;
}

int cli_printClienteById(eClientes* list,int len,int id)
{
    int i;
    int ret = -1;

    if(list!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty==1)
            {
                if(list[i].idClientes==id)
                {
                    printf("\n---------------------------\n");
                    printf("\nId del cliente: %d\nNombre: %s\nCuit: %s\nDireccion: %s\nLocalidad: %s\n",
                       list[i].idClientes,list[i].nombreEmpresa,list[i].cuit,list[i].direccion,list[i].localidad);
                           ret = 0;
                }
            }
        }
    }
    return ret;
}

/** \brief Imprime los clientes con cantidad de pendientes.
*
* \param list Cliente*
* \param len int
* \return int Retorna (-1) si Error [longitud invalida o
*  puntero NULL] - (0) si Ok
*
*/
int cliente_ImprimirArrayConPendientes(eClientes* list, int len, ePedidos* list2, int len2)
{
	int i;
	int retorno = -1;
	if(list != NULL && len>0)
	{
		retorno = 0;
		printf("id     Nombre    Cuit    Direccion   Localidad     Cantidad de Pendientes\n");
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == 1){
				printf("%d -- %s -- %s -- %s -- %s -- %d \n",list[i].idClientes,list[i].nombreEmpresa,list[i].cuit,list[i].direccion,list[i].localidad,pedido_contarPendientesPorCliente(list2, len2, list[i].idClientes));
			}

		}
	}
	return retorno;
}
