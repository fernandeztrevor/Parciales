#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <float.h>
#include "funciones.h"


int devolverHorasEstadia()
{
    int horas;

    srand(time(NULL));

    horas = (rand()%24)+1;


    return horas ;

};


void imprimirMenu()
{
    printf("\n1. Alta de propietario\n2. Modificacion de propietario\n3. Baja de propietario\n4. Ingreso de automovil\n5. Egreso de automovil\n6. Recaudacion total del estacionamiento\n7. Recaudacion total por marca\n8.Buscar propietario por ID\n9.Datos de los propietarios de autos AUDI\n10. Listado de autos con usuarios ordenados por patente\n99. Salir\n");
};

void inicializar(Propietarios listaPersonas[], int cantidad, int valor)
{
    int i;

    for (i=0; i<cantidad; i++)
    {
        listaPersonas[i].id = valor;
    }
}

void inicializarIngresos(Ingresos listaIngresos[], int cantidad, int valor)
{
    int i;

    for (i=0; i<cantidad; i++)
    {
        listaIngresos[i].id = valor;
    }
}

int obtenerEspacioLibre(Propietarios listaPersonas[], int cantidad, int valor)
{
    int i;
    for (i=0; i<cantidad; i++)
    {
     if (listaPersonas[i].id == valor)
     {
         return i;
     }
    }
    return -1;
}

int letras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if ((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}

int alfanumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
            return 0;
        i++;
    }
    return 1;
}

int numerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i]>'9')
            return 0;
        i++;
    }
    return 1;
}


int imprimirListaPropietarios(Propietarios listaPersonas[], int cantidad, int j, int valor)
{
    int i;
    j=0;

    for(i=0; i<cantidad; i++)
                {
                    if(listaPersonas[i].id > valor)
                    {
                        if(j==0)
                        {
                          printf("\nId      Nombre      Direccion      Tarjeta\n");
                        }
                        printf("%d.      %s      %s      %s\n", listaPersonas[i].id, listaPersonas[i].nombre, listaPersonas[i].direccion, listaPersonas[i].tarjeta);
                        j++;
                    }
                }

    return j;
}

int imprimirListaIngresos(Propietarios listaPersonas[], Ingresos listaIngresos[], int cantidad, int j, int valor)
{
        int i;
        j=0;

        for(i=0; i<cantidad; i++)
                    {
                        if(listaIngresos[i].id > valor)
                        {
                            if(j==0)
                                {
                                  printf("\nId      Patente      Marca      ID Propietario\n");
                                }
                                printf("%d      %s      %d      %d\n", listaIngresos[i].id, listaIngresos[i].patente, listaIngresos[i].marca, listaPersonas[i].id);
                                j++;
                        }
                    }

        return j;
}




