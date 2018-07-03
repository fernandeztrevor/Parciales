#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"

int main()
{
    ArrayList* list = al_newArrayList();
    cargar(list);
    int tam = list->len();
    int i;
    int eleccion = 0;
    ArrayList* auxList = al_clone(list);

    do{

        printf("1- Listar empleados\n9- Salir\n");
        scanf("%d", &eleccion);

        switch(eleccion)
        {
        case 1:

            auxList->sort(auxList,compareEmployee,1);

            for(i=0; i < tam; i++)
            {
                printEmployee((Employee*)auxList->get(list, i));
            }
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 9:
            eleccion=9;
            break;
        }

    }while(eleccion!=9);
    return 0;
}
