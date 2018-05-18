#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <float.h>
#include "funciones.h"
#define MARCA1  "ALPHA_ROMEO"
#define MARCA2  "FERRARI"
#define MARCA3  "AUDI"
#define MARCA4  "OTROS"


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

int obtenerEspacioIngresos(Ingresos listaIngresos[], int cantidad, int valor)
{
    int i;
    for (i=0; i<cantidad; i++)
    {
     if (listaIngresos[i].id == valor)
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
        if((str[i] != '-') && (str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
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
                          printf("\nId                  Nombre          Direccion             Tarjeta\n");

                        }
                        printf("%d.%20s%20s%20s\n", listaPersonas[i].id, listaPersonas[i].nombre, listaPersonas[i].direccion, listaPersonas[i].tarjeta);
                        j++;
                    }
                }

    return j;
}

int imprimirListaIngresos(Ingresos listaIngresos[], Propietarios listaPersonas[], int cantidad, int j, int valor)
{
        int i;
        int marca;

        j=0;

        for(i=0; i<20; i++)
                    {
                        if(listaIngresos[i].id > valor)
                        {
                            if(j==0)
                                {
                                  printf("\nId      Patente      Marca      ID Propietario\n");
                                }
                            switch(listaIngresos[i].marca)
                                {case 1:
                                marca=MARCA1;
                                break;
                                case 2:
                                marca=MARCA2;
                                break;
                                case 3:
                                marca=MARCA3;
                                break;
                                case 4:
                                marca=MARCA4;
                                break;}
                            printf("%4d%10s%10s%4d\n", listaIngresos[i].id, listaIngresos[i].patente, marca , listaIngresos[i].propietario);//se enmascaró marca
                            j++;
                        }
                    }


        return j;
}

void hardcode(Propietarios listaPersonas[])
{
        /*for(int i=1; i<5; i++)
    {
        switch (i)
            {
               case 1:
                   listaPersonas[i].id=i;
                   strcpy(listaPersonas[i].nombre,"Juan");
                   strcpy(listaPersonas[i].tarjeta,"111111");
                   strcpy(listaPersonas[i].direccion,"Mitre");
                   break;
                case 2:
                   listaPersonas[i].id = i;
                   strcpy(listaPersonas[i].nombre,"Luis");
                   strcpy(listaPersonas[i].tarjeta,"222222");
                   strcpy(listaPersonas[i].direccion,"Urquiza");
                   break;
                case 3:
                   listaPersonas[i].id=i;
                   strcpy(listaPersonas[i].nombre,"Maria");
                   strcpy(listaPersonas[i].tarjeta,"333333");
                   strcpy(listaPersonas[i].direccion,"Belgrano");
                   break;
                case 4:
                   listaPersonas[i].id=i;
                   strcpy(listaPersonas[i].nombre,"Jose");
                   strcpy(listaPersonas[i].tarjeta,"444444");
                   strcpy(listaPersonas[i].direccion,"Alsina");
                   break;
            }
    }*/
    int id[4] = {0,1,2,3};
    char nombre[4][20] = {"Juan","Luis","Maria","Jose"};
    char tarjeta[4][20] = {"111-111","222-222","333-333","444-444"};
    char direccion[4][20] = {"mitre","urquiza","belgrano","alsina"};

    for (int i = 0; i<4; i++)
    {
        listaPersonas[i].id = id[i];
        strcpy(listaPersonas[i].nombre,nombre[i]);
        strcpy(listaPersonas[i].tarjeta,tarjeta[i]);
        strcpy(listaPersonas[i].direccion,direccion[i]);
    }
    printf("\nCarga de personas OK");
}

void hardcodeIngresos(Ingresos listaIngresos[])
{
    int id[10] = {0,1,2,3,4,5,6,7,8,9};
    char patente[20][10]= {"AAA","CCC","DDD","BBB","ZZZ","III","HHH","EEE","FFF","GGG"};
    int marca[10]= {1,3,3,2,2,3,3,4,3,1};
    int propietario[10]= {2,1,2,1,3,3,4,1,4,3};

     for(int i = 0; i<10; i++)
    {
        listaIngresos[i].id = id[i];
        strcpy(listaIngresos[i].patente, patente[i]);
        listaIngresos[i].marca = marca[i];
        /*switch(marca[i])
                        {case 1:
                        listaIngresos[i].marca=MARCA1;
                        break;
                        case 2:
                        listaIngresos[i].marca=MARCA2;
                        break;
                        case 3:
                        listaIngresos[i].marca=MARCA3;
                        break;
                        case 4:
                        listaIngresos[i].marca=MARCA4;
                        break;}*/
        listaIngresos[i].propietario = propietario[i];
        //printf("%4d%10s%10s\n", listaIngresos[i].id, listaIngresos[i].patente, listaIngresos[i].marca);
    }
printf("\nCarga de ingresos OK");
}


