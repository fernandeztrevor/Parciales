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
    int correcto;
    int eleccion = 0;
    ArrayList* auxList = al_clone(list);

    do{
        printf("1- Listar empleados\n2- Listar alfabeticamente\n3- Listar con salarios\n9- Salir\n");
        scanf("%d", &eleccion);

        switch(eleccion)
        {
    case 1:
        for(i=0; i < tam; i++)
            {
                printEmployee((Employee*)auxList->get(auxList, i));
            }
            printf("\n");
            system("pause");
            system("cls");
        break;
    case 2:

            correcto = auxList->sort(auxList,compareEmployee,1);

            if(correcto == 0)
            {
                for(i=0; i < tam; i++)
                    {
                        printEmployee((Employee*)auxList->get(auxList, i));
                    }
                    printf("\n");
                    system("pause");
                    system("cls");
            }
            else{
                printf("No se puede realizar la accion");
            }
            break;
    case 3:

            al_map(auxList, Employee_salary);
            //auxList->map(auxList, Employee_salary);

            for(i=0; i < tam; i++)
                {


                    printEmployeeSalary((Employee*)auxList->get(auxList, i));

                   /* for(int i=0; i<tam; i++)
                        {
                            int sal;
                            sal=Employee_salary(auxList->get(auxList,i));
                            Employee_setSueldo(auxList, sal);
                            printEmployeeSalary((Employee*)auxList->get(auxList, i));
                        }*/

                }

                printf("\n");
                system("pause");
                system("cls");

            break;
    case 4:
        Employee_salary_save(auxList);
        break;

     case 9:
            eleccion=9;
            break;
        }

    }while(eleccion!=9);
    return 0;
}
