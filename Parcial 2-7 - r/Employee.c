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
    char* horas=(char *)malloc(sizeof(char)*51);
    //fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]", id, nombre, direccion, horas);
    while(!feof(pFile))
    {
    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]", id, nombre, direccion, horas);
    Employee *tmp = newEmployee();
    Employee_setId(tmp, atoi(id));
    Employee_setNombre(tmp, nombre);
    Employee_setDireccion(tmp, direccion);
    Employee_setHoras(tmp, atoi(horas));
    list->add(list, tmp);
    }

    }
    fclose(pFile);
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
    printf("ID:%d Nombre:%s Direccion:%s Horas: %d\r\n",Employee_getId(p),Employee_getNombre(p),Employee_getDireccion(p), Employee_getHoras(p));
}

void printEmployeeSalary(Employee* p)
{
    printf("ID:%d\nNombre:%s\nDireccion:%s\nHoras: %d\nSueldo: %d\r\n\n",Employee_getId(p),Employee_getNombre(p),Employee_getDireccion(p), Employee_getHoras(p), Employee_getSueldo(p));
}

int Employee_salary_save(ArrayList* this)
{
    int aux = -1;
    FILE* pFile;
    pFile = fopen("./sueldos.csv","w");

    if(pFile != NULL)
    {
    int tam=al_len(this);
    fprintf(pFile, "ID,Nombre,Direccion,Horas,Sueldo\n");
    for(int i=0; i<tam; i++)
    {
        Employee* tmp = (Employee*)this->get(this,i);
        fprintf(pFile, "%d,%s,%s,%d,%d\n", Employee_getId(tmp), Employee_getNombre(tmp), Employee_getDireccion(tmp), Employee_getHoras(tmp), Employee_getSueldo(tmp));
    }
    }
    fclose(pFile);
}

int Employee_salary_save_mayor(ArrayList* this)
{
    int aux = -1;
    FILE* pFile;
    pFile = fopen("./MayoresA20K.csv","w");

    if(pFile != NULL)
    {
    int tam=al_len(this);
    fprintf(pFile, "ID,Nombre,Direccion,Horas,Sueldo\n");
    for(int i=0; i<tam; i++)
    {
        Employee* tmp = (Employee*)this->get(this,i);
        fprintf(pFile, "%d,%s,%s,%d,%d\n", Employee_getId(tmp), Employee_getNombre(tmp), Employee_getDireccion(tmp), Employee_getHoras(tmp), Employee_getSueldo(tmp));
    }
    }
    fclose(pFile);
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
int Employee_salary(Employee* this)
{
    int salary;
    Employee* aux = (Employee*) this;
    int horas = Employee_getHoras(this);

    if(aux =! NULL)
    {

        if(horas< 120)
        {
           salary = horas*180;
           //Employee_setSalary(aux, salary);
           Employee_setSueldo(this, salary);
        }
        if(horas >= 120 && horas < 160)
        {
            salary = (horas-120)*240 + 120*180;
            //printf("ok");
            //Employee_setSalary(aux, salary);
            Employee_setSueldo(this, salary);
        }
        if (horas >= 160)
        {
            salary = (horas-160)*350 + (horas-120)*240 + 120*180;
            //Employee_setSalary(aux, salary);
            Employee_setSueldo(this, salary);
        }
    }


    return salary;
}

int Employee_mayor(ArrayList* this, int (*pFunc)(void*), int index)
{
    int retorno=-1;

    if(this != NULL && pFunc != NULL)
    {
        //printf("!");
           if( Employee_salary(this) < 20000)
            {
                retorno = 1;
            }
    //printf("!");
    }
    return retorno;
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
int Employee_setHoras(Employee* this, int horas)
{
    this->horas = horas;
}
int Employee_getHoras(Employee* this)
{
    return this->horas;
}
int Employee_setSueldo(Employee* this, int sueldo)
{
    this->sueldo = sueldo;
}
int Employee_getSueldo(Employee* this)
{
    return this->sueldo;
}
