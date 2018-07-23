/*
    utest example : Unit test examples.
    Copyright (C) <2016>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef __EMPLOYEE
#define __EMPLOYEE
struct
{
    int id;
    char nombre[51];
    char direccion[51];
    int horas;
    int sueldo;

}typedef Employee;
#endif // __EMPLOYEE

int compareEmployee(void* pEmployeeA,void* pEmployeeB);
int Employee_salary(Employee*);
void printEmployee(Employee* p);
Employee* newEmployee(void);//(int id, char nombre[],char direccion[]);
int Employee_setId(Employee*, int);
int Employee_getId(Employee*);
char *Employee_setNombre(Employee*, char*);
char *Employee_getNombre(Employee*);
char *Employee_setDireccion(Employee*, char*);
char *Employee_getDireccion(Employee*);
int Employee_mayor(ArrayList* this, int (*pFunc)(void*), int index);

