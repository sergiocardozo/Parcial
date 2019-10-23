#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "utn.h"
#include "pedidos.h"

/** \brief  Para indicar que todas las posiciones en el array están vacías,
* esta función pone la bandera (isEmpty) en TRUE en todos
* posición del array
* \ param array eClientes array de clientes
* \ param size int largo del array
* \ return int retorna (-1) si da Error [Longitud inválida o puntero NULL] - (0) si esta Ok
*
*/
int cliente_Inicializar(eClientes array[], int size)
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

/** \brief Busca el primer lugar vacio en un array
* \param array eClientes Array de clientes
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int cliente_buscarEmpty(eClientes array[], int size, int* posicion)
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

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array eCliente Array de clientes
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int cliente_buscarID(eClientes array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idClientes==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un string en un array
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int clienteBuscarCuit(eClientes array[], int size, char* valorBuscado, int* indice)                    //cambiar fantasma
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].cuit,valorBuscado)==0)                                        //cambiar campo varString
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un string en un array
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int clienteBuscarLocalidad(eClientes array[], int size, char* valorBuscado, int* indice)                    //cambiar fantasma
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].localidad,valorBuscado)==0)                                        //cambiar campo varString
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}


/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array eClientes Array de clientes
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int cliente_alta(eClientes* array, int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
    	__fpurge(stdin);
        if(cliente_buscarEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
        	(*contadorID)++;
            array[posicion].idClientes = *contadorID;
        	array[posicion].isEmpty=0;
        	utn_getTexto("\nIngrese nombre de la Empresa: ","\nError",1,50,2,array[posicion].nombreEmpresa);
        	utn_getTexto("\nIngrese Cuit: ","\nError",1,13,2,array[posicion].cuit);
        	utn_getTexto("\nIngrese direccion: ","\nError",1,50,2,array[posicion].direccion);
        	utn_getTexto("\nIngrese localidad: ","\nError",1,50,2,array[posicion].localidad);


            printf( "\n ID: %d\t Nombre Empresa: %s\t Cuit: %s\t Direccion: %s\t Localidad: %s",
            																					array[posicion].idClientes,
																								array[posicion].nombreEmpresa,
																								array[posicion].cuit,
																								array[posicion].direccion,
																								array[posicion].localidad);
            retorno=0;
        }
    }
    return retorno;
}



/** \brief Borra un elemento del array por ID
* \param array eClientes Array de clientes
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int cliente_baja(eClientes clieArray[], int sizeClieArray)
{
    int retorno=-1;
    int posicion;
    int id;
    char opcion;
    if(clieArray!=NULL && sizeClieArray>0)
    {
    	__fpurge(stdin);
    	utn_getUnsignedInt("\nID de cliente a dar de baja: ","\nError",1,sizeof(int),1,sizeClieArray,3,&id);
        if(cliente_buscarID(clieArray,sizeClieArray,id,&posicion)==-1)
        {
            printf("\nNo existe el ID de este cliente");
        }
        else
        {
        	utn_getChar("\nEsta seguro que desea dar de baja? S/N","\nError",'A','S',2,&opcion);
        	switch(opcion)
        	{
        	  case 'S':
        		  clieArray[posicion].isEmpty=1;
        		  clieArray[posicion].idClientes=0;
        		  strcpy(clieArray[posicion].nombreEmpresa,"");
        		  strcpy(clieArray[posicion].cuit,"");
        		  strcpy(clieArray[posicion].direccion,"");
        		  strcpy(clieArray[posicion].localidad,"");

        		  retorno = 0;
        	      break;
        	  case 'N':
        		  printf("\nBaja cancelada");
        	      break;
        	  default:
        		  printf("\nOpcion no valida");
        	 }

        }

        retorno=0;
    }

   	return retorno;
}

/** \brief Busca un elemento por ID y modifica sus campos direccion y localidad
* \param array eClientes Array de clientes
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int cliente_modificar(eClientes array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
    	__fpurge(stdin);
    	utn_getUnsignedInt("\nID de cliente a modificar: ","\nError",1,sizeof(int),1,sizeArray,2,&id);
        if(cliente_buscarID(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {
            	printf( "\nID: %d\tCuil: %s\tNombre: %s\tDireccion %s\tLocalidad: %s",
            			array[posicion].idClientes,
						array[posicion].cuit,
            			array[posicion].nombreEmpresa,
						array[posicion].direccion,
						array[posicion].localidad);
                utn_getChar("\nModificar: Direccion(A) Localidad(B) S(Salir)","\nError",'A','S',2,&opcion);
                switch(opcion)
                {
                    case 'A':
                    	utn_getTexto("\nIngrese direccion: ","\nError",1,50,2,array[posicion].direccion);
                    	break;
                    case 'B':
                    	utn_getTexto("\nIngrese localidad: ","\nError",1,50,2,array[posicion].localidad);
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}

/** \brief Verifica si hay al menos un cliente cargado en el array
     *
     * \param list eClientes lista del campo de eClientes
     * \param len int  largo del array
     * \return 0 si no hay Clientes, 1 si hay al menos uno cargado
     *
     */

int clientesExistente(eClientes list[], int len)
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

/** \brief Lista los elementos de un array
* \param array eClientes Array de clientes
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int cliente_listar(eClientes array[], int size)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
    	__fpurge(stdin);
    	 printf("ID		NOMBRE DE LA EMPRESA		CUIT			DIRECCION		LOCALIDAD \n");
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
            	printf( "\n%4d		%-20s		%-10s		%-10s		%-25s",array[i].idClientes,
            										array[i].nombreEmpresa,
													array[i].cuit,
													array[i].direccion,
													array[i].localidad);
        }
        retorno=0;
    }
    return retorno;
}
void mostrar_cliente(eClientes cliente)
{

    printf("%2d   %9s   %7s   %5s   %10s\n", cliente.idClientes, cliente.nombreEmpresa,cliente.cuit, cliente.direccion,cliente.localidad);

}


