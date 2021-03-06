#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <float.h>
#include <time.h>
#include <string.h>
#include "funciones.h"
#define valor -1
#define cantidad 20
#define MARCA1  "ALPHA_ROMEO"
#define MARCA2  "FERRARI"
#define MARCA3  "AUDI"
#define MARCA4  "OTROS"


int main()
{
    int opcion=0;
    int espacioLibre;
    int i;
    int j;
    int k;
    int horasEstadia=0;
    int recaudacionTotal=0;
    int recaudacionMarca1=0;
    int recaudacionMarca2=0;
    int recaudacionMarca3=0;
    int recaudacionMarca4=0;
    char auxiliarNombre[100];
    char auxiliarDireccion[100];
    char auxiliarTarjeta[8];
    char auxiliarPatente[6];

    Propietarios listaPersonas[cantidad];
    Ingresos listaIngresos[30];
    Egresos listaEgresos[30];

    inicializar(listaPersonas, cantidad, valor);
    inicializarIngresos(listaIngresos, cantidad, valor);
    hardcode(listaPersonas);
    hardcodeIngresos(listaIngresos);
    hardcodeEgresos(listaEgresos);

    for(i=0;  i<10; i++)
    {
        if (listaEgresos[i].marca==1)
        {
            recaudacionTotal=recaudacionTotal+recaudacionMarca1;
            recaudacionMarca1=recaudacionMarca1+listaEgresos[i].importe;

        }
        if (listaEgresos[i].marca==2)
        {
            recaudacionTotal=recaudacionTotal+recaudacionMarca1;
            recaudacionMarca2=recaudacionMarca2+listaEgresos[i].importe;
        }
        if (listaEgresos[i].marca==3)
        {
            recaudacionTotal=recaudacionTotal+recaudacionMarca1;
            recaudacionMarca3=recaudacionMarca3+listaEgresos[i].importe;
        }
        if (listaEgresos[i].marca==4)
        {
            recaudacionTotal=recaudacionTotal+recaudacionMarca1;
            recaudacionMarca4=recaudacionMarca4+listaEgresos[i].importe;
        }
    }

    do
    {
        imprimirMenu();
        scanf("%d", &opcion);
        switch(opcion)
        {
    case 1:
        espacioLibre=obtenerEspacioLibre(listaPersonas, cantidad, valor);
        printf("%d", espacioLibre);

        if(espacioLibre == -1)
        {
            printf("No queda mas lugar");
        }
        else{

            printf("\nIngrese nombre: ");
            fflush(stdin);
            gets(auxiliarNombre);
            while (letras(auxiliarNombre)!=1)
                        {
                            printf("El nombre solo puede estar compuesto por letras, reingrese:\n");
                            gets(auxiliarNombre);
                        }
            printf("\nIngrese direccion: ");
            fflush(stdin);
            gets(auxiliarDireccion);
            while (alfanumerico(auxiliarDireccion)!=1)
                        {
                            printf("La direccion solo puede contener numeros y letras, reingrese:\n");
                            gets(auxiliarDireccion);
                        }
            printf("\nIngrese numero de tarjeta, sin guiones: ");
            fflush(stdin);
            gets(auxiliarTarjeta);
            while (numerico(auxiliarTarjeta)!=1)
                        {
                            printf("El numero de tarjeta solo puede estar compuesto por numeros, reingrese:\n");
                            gets(auxiliarTarjeta);
                        }

                        listaPersonas[espacioLibre].id=espacioLibre;
                        strcpy(listaPersonas[espacioLibre].nombre,auxiliarNombre);
                        strcpy(listaPersonas[espacioLibre].direccion,auxiliarDireccion);
                        strcpy(listaPersonas[espacioLibre].tarjeta,auxiliarTarjeta);
        break;

    case 2:
        j=imprimirListaPropietarios(listaPersonas, cantidad, j, valor);

        if (j == 0)
                {
                    printf("\nNo existen datos cargados\n");
                }
                else
                {
                printf("\nSeleccione el ID que desea modificar: ");
                scanf("%d", &i);

                printf("\nIngrese numero de tarjeta, sin guiones: ");
                fflush(stdin);
                gets(auxiliarTarjeta);
                while (numerico(auxiliarTarjeta)!=1)
                        {
                            printf("El numero de tarjeta solo puede estar compuesto por numeros, reingrese:\n");
                            gets(auxiliarTarjeta);
                        }
                printf("\n\nPara confirmar la operacion presione 1, para cancelar 2.\n");
                scanf("%d", &j);
                if(j == '1')
                {
                  strcpy(listaPersonas[i].tarjeta,auxiliarTarjeta);
                  printf("\nUsuario modificado\n");
                }
                else
                {
                    printf("\nOPERACION CANCELADA\N");
                }



                }break;

    case 3:
        j=imprimirListaPropietarios(listaPersonas, cantidad, j, valor);
        if (j == 0)
                {
                    printf("\nNo existen datos cargados\n");
                }
                else
                {
                    printf("\nSeleccione el ID que desea dar de baja: ");
                    scanf("%d", &i);
                    printf("\nPara confirmar la operacion presione 1, para cancelar 2.\n");
                scanf("%d", &j);
                if(j == 1)
                {
                  listaPersonas[i].id=valor;
                  printf("\nUsuario Borrado\n");
                }
                else
                {
                    printf("\nOPERACION CANCELADA\N");
                }

                }break;
    case 4:
        espacioLibre=obtenerEspacioIngresos(listaIngresos, cantidad, valor);
        printf("%d", espacioLibre);

        if(espacioLibre == -1)
        {
            printf("No queda mas lugar");
        }

        else{
        printf("\nIngrese la patente del auto ingresado: \n");
        fflush(stdin);
        gets(auxiliarPatente);//tomo patente
        while (alfanumerico(auxiliarPatente)!=1)
                        {
                            printf("\nLa patente solo puede contener numeros y letras, reingrese:\n");
                            gets(auxiliarPatente);
                        }
        printf("Seleccione la marca del vehiculo:\n1.ALPHA_ROMEO\n2.FERRARI\n3.AUDI\n4.OTROS\n");
        scanf("%d", &i);//tomo marca
        while(i<1 || i>4)
                        {
                            printf("Error. Seleccione la marca del vehiculo:\n1.ALPHA_ROMEO\n2.FERRARI\n3.AUDI\n4.OTROS\n");
                            scanf("%d", &i);
                        }
        printf("Ingrese el ID del propietario: ");
        imprimirListaPropietarios(listaPersonas, cantidad, j, valor);
        scanf("%d", &k);//tomo propietario
        listaIngresos[espacioLibre].propietario=listaPersonas[k].id;

        strcpy(listaIngresos[espacioLibre].patente, auxiliarPatente);

        switch (i)
            {
                case 1:
                        listaIngresos[espacioLibre].marca=MARCA1;
                        break;
                case 2:
                        listaIngresos[espacioLibre].marca=MARCA2;
                        break;
                case 3:
                        listaIngresos[espacioLibre].marca=MARCA3;
                        break;
                case 4:
                        listaIngresos[espacioLibre].marca=MARCA4;
                        break;
            }


         listaIngresos[espacioLibre].id=espacioLibre;
         //imprimirListaIngresos(listaIngresos, listaPersonas, cantidad, j, valor);
        }break;

    case 5:
            horasEstadia = devolverHorasEstadia(horasEstadia);
            printf("%d", horasEstadia);
            j = imprimirListaIngresos(listaIngresos, listaPersonas, cantidad, j, valor);

           if (j == 0)
                {
                    printf("No existen datos cargados");
                }
                else
                {
                   printf("\nIngrese el ID de ingreso:\n");
                   scanf("%d", &i);
                //printf("%s", listaIngresos[i].marca);
                  /* if(listaIngresos[i].marca == MARCA1)
                   {
                       j = horasEstadia*150;
                       printf("Usted ha estado %d hs y el precio a abonar es %d", horasEstadia, j);
                       recaudacionMarca1 = recaudacionMarca1+j;
                   }
                   if(listaIngresos[i].marca == MARCA2)
                   {
                       j = horasEstadia*175;
                       printf("Usted ha estado %d hs y el precio a abonar es %d", horasEstadia, j);
                       recaudacionMarca2 = recaudacionMarca2+j;
                   }
                   if(listaIngresos[i].marca == MARCA3)
                   {
                      j = horasEstadia*200;
                      printf("Usted ha estado %d hs y el precio a abonar es %d", horasEstadia, j);
                      recaudacionMarca3 = recaudacionMarca3+j;
                   }
                   if(listaIngresos[i].marca == MARCA4)
                   {
                       j = horasEstadia*250;
                       printf("Usted ha estado %d hs y el precio a abonar es %d", horasEstadia, j);
                       recaudacionMarca4 = recaudacionMarca4+j;
                   }*/


                   switch(listaIngresos[i].marca)
                   {
                       case 1:
                            j = horasEstadia*150;
                            printf("Usted ha estado %d hs y el precio a abonar es %d", horasEstadia, j);
                            recaudacionMarca1 = recaudacionMarca1+j;
                            break;
                       case 2:
                            j = horasEstadia*175;
                            printf("Usted ha estado %d hs y el precio a abonar es %d", horasEstadia, j);
                            recaudacionMarca2 = recaudacionMarca2+j;
                            break;
                        case 3:
                            j = horasEstadia*200;
                            printf("Usted ha estado %d hs y el precio a abonar es %d", horasEstadia, j);
                            recaudacionMarca3 = recaudacionMarca3+j;
                            break;
                        case 4:
                            j = horasEstadia*250;
                            printf("Usted ha estado %d hs y el precio a abonar es %d", horasEstadia, j);
                            recaudacionMarca4 = recaudacionMarca4+j;
                            break;
                   }

                recaudacionTotal = recaudacionTotal+j;
                printf("\n-ID Propietario: %d\n-Nombre: %s\n- Patente: %s\n- Tiempo de estadia: %dhs\n\n***El importe a abonar es de %d pesos***\n\n", listaIngresos[i].id, listaPersonas[i].nombre, listaIngresos[i].patente, horasEstadia, j);
                listaIngresos[i].id = valor;
                }
                break;
    case 6:
        printf("\nLa recaudacion hasta el momento es de %d Pesos\n", recaudacionTotal);
        break;
    case 7:
        printf("\nA continuacion se detalla la recaudacion por marca hasta el momento:\n\n1.ALPHA_ROMEO: $%d.\n2.FERRARI: $%d.\n3.AUDI: $%d.\n4.OTROS: $%d.\n", recaudacionMarca1, recaudacionMarca2, recaudacionMarca3, recaudacionMarca4);
        break;
    case 8:
        printf("Ingrese el ID del usuario que desea buscar: ");
        scanf("%d", &j);
        k = 0;
        for(i=0; i<20; i++)
        {
            if(j == listaPersonas[i].id)
            {
              printf("\nID: %d.\nNombre: %s.\nTarjeta: %s.\nDireccion: %s.\n",listaPersonas[i].id, listaPersonas[i].nombre, listaPersonas[i].tarjeta, listaPersonas[i].direccion);
              k = 1;
            }
        }
        if(k == 0)
            {
                printf("\nNo se encontraron usuarios para ese ID.\n");
            }
        break;

    case 9:
        k = 0;
        for(i=0; i<20; i++)
        {
            if(listaIngresos[i].marca == 3)
            {
              for(j=0; j<4; j++)
              {
                  if (listaPersonas[j].id == listaIngresos[i].propietario)
                  {
                   printf("\n\nID: %d.\nNombre: %s.\nPatente: %s.\n",listaIngresos[i].propietario, listaPersonas[j].nombre, listaIngresos[i].patente);
                  }
              }
              k=1;
            }
        }
        if(k==0)
            {
                printf("\nNo se encontraron usuarios con autos AUDI.\n");
            }
            break;

    case 98:
        imprimirListaPropietarios(listaPersonas, cantidad, j, valor);
        break;
    case 97:
        imprimirListaIngresos(listaIngresos, listaPersonas, cantidad, j, valor);
        break;

        }}

  }
    while(opcion!=99);



    return 0;
}
