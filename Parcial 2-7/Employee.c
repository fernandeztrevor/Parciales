#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"

int parseEmployee(FILE* pFile, ArrayList* list)
{
    int aux = -1;

    pFile = fopen("./info.csv","r");

    if(pFile != NULL)
    {
    char* id=(char *)malloc(sizeof(char)*51);
    char* nombre=(char *)malloc(sizeof(char)*51);
    char* direccion=(char *)malloc(sizeof(char)*51);
    while(!feof(pFile))
    {
    fscanf(pFile,"%[^,],%[^,],%[^\n]", id, nombre, direccion);
    Employee *tmp = newEmployee();
    Employee_setId(tmp, atoi(id));
    Employee_setNombre(tmp, nombre);
    Employee_setDireccion(tmp, direccion);
    list->add(list, tmp);
    }

    }
}

int compareEmployee(void* pEmployeeA,void* pEmployeeB)
{

    if(strcmp(((Employee*)pEmployeeA)->nombre,((Employee*)pEmployeeB)->nombre) > 0)
    {
        return 1;
    }
    if(strcmp(((Employee*)pEmployeeA)->nombre,((Employee*)pEmployeeB)->nombre) < 0)
    {
        return -1;
    }
    return 0;


}

void printEmployee(Employee* p)
{
    printf("ID:%d Nombre:%s Direccion:%s\r\n",Employee_getId(p),Employee_getNombre(p),Employee_getDireccion(p));
}

/** \brief Set this employee the values recived as parameters
 *
 * \param pEmployee employee*
 * \param id int
 * \param nombre[] char
 * \param direccion[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [NULL pointer] - (0) if Ok
 *
 */
Employee* newEmployee(void)//(int id, char nombre[],char direccion[])
{
    Employee* returnAux = NULL;
    Employee* pEmployee = malloc(sizeof(Employee));

    if(pEmployee != NULL)
    {
        /*pEmployee->id = id;
        strcpy(pEmployee->nombre,nombre);
        strcpy(pEmployee->direccion,direccion);*/
        returnAux = pEmployee;
    }

    return returnAux;

}

int Employee_setId(Employee* this, int id)
{
    this->id = id;
}
int Employee_getId(Employee* this)
{
    return this->id;
}
char* Employee_setNombre(Employee* this, char* nombre)
{
    strcpy(this->nombre, nombre);
}
char* Employee_getNombre(Employee* this)
{
    return this->nombre;
}
char* Employee_setDireccion(Employee* this, char* direccion)
{
    strcpy(this->direccion, direccion);
}
char* Employee_getDireccion(Employee* this)
{
    return this->direccion;
}
