/*
 * Alejandro Heidenreich
 ============================================================================
Empresa
De los 20 empleados de una empresa se registran: nombre, apellido, género (masculino o
femenino), la edad (mayor que 18), cantidad de años trabajados en la empresa y un
salario básico asignado.
Desde el programa se debe poder realizar las siguientes operaciones y se debe poder
acceder a las mismas mediante un menú de usuario con las siguientes opciones:
a. Calcular la cantidad de empleados de género masculino.
b. Calcular el porcentaje de empleados por género.
c. Calcular la cantidad de años que le falta a cada empleado para jubilarse
(convención: se jubilan a los 60 años ambos géneros).
d. Calcular el monto que paga en concepto de sueldos la empresa, teniendo en
cuenta a todos los empleados.
e. Permitir la consulta por empleado, ingresando el apellido, en pantalla debe
mostrar los datos personales mencionados en el enunciado, sueldo, en qué año
calendario se jubila.
f. Listado ordenado por apellido de todos los empleados.
g. El o los empleados de género femenino que ganan más dinero.
Notas: De ser posible llevar su dispositivo, para evitar cualquier inconveniente de
disponibilidad de software o versiones.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include "Inputs.h"

#define LEN 20

int main(void) {
	setbuf(stdout,NULL);

	int option;
	eEmployee employeeList[LEN];
	int inform;
	float totalSalary;

	InitializeEmployeeList(employeeList, LEN);
	HardCodeEmployeeList(employeeList, LEN);

	do{

		PrintMainMenu();
		option = IntegerInputRange("Insert an option: ",0,7);

		switch(option){
			case 1:
				inform = CountMaleEmployees(employeeList, LEN, 'M');
				printf("Cantidad de empleados de genero masculino: %d\n\n",inform);
				break;
			case 2:
				PercentageEmployeesBySex(employeeList, LEN);
				break;
			case 3:
				PrintEmployeesYearLeftToRetire(employeeList, LEN);
				break;
			case 4:
				totalSalary = SalaryAmountPaidOutToEmployees(employeeList, LEN);
				printf("Monto que paga en concepto de sueldos la empresa: $ %.2f",totalSalary);
				break;
			case 5:
				ShowEmployeeByLastname(employeeList, LEN);
				break;
			case 6:
				SortEmployeesByLastname(employeeList, LEN);
				PrintEmployeeList(employeeList, LEN);
				break;
			case 7:
				PrintHighestSalaryBySex(employeeList, LEN, 'F');
				break;
		}

	}while(option != 0);

	printf("\n\nFIN DE LA APLICACION\n\n");
	return EXIT_SUCCESS;
}
