#include "Inputs.h"

void PrintMainMenu(){
	printf(	"1. Calcular la cantidad de empleados de género masculino.\n"
			"2. Calcular el porcentaje de empleados por género.\n"
			"3. Calcular la cantidad de años que le falta a cada empleado para jubilarse(convención: se jubilan a los 60 años ambos géneros).\n"
			"4. Calcular el monto que paga en concepto de sueldos la empresa, teniendo encuenta a todos los empleados.\n"
			"5. Permitir la consulta por empleado, ingresando el apellido, en pantalla debemostrar los datos personales mencionados en el enunciado, sueldo, en qué añocalendario se jubila.\n"
			"6. Listado ordenado por apellido de todos los empleados.\n"
			"7. El o los empleados de género femenino que ganan más dinero.\n"
			"0. Salir.\n");
}

int IntegerInputRange(char* message,int from ,int to){

	int number;
	char numberStr[100];
	int fail = 1;

	do{
		printf("%s\n", message);
		gets(numberStr);

		if(ValidatePositiveInteger(numberStr)){
			number = atoi(numberStr);
			if(number >= from && number <= to){
				fail = 0;
			}
			else{
				printf("Error: %d is out of range of %d - %d\n",number, from, to);
			}

		}
		else{
			printf("Error: %s is not an integer\n",numberStr);
		}

	}while(fail);

	return number;
}

int ValidatePositiveInteger(char* number){
	int length = strlen(number);
	int success=1;

	for (int i=0;i<length;i++){
		if (!isdigit(number[i])){
			success=0;
			break;
		}
	}

	return success;
}

void InputString(char* message, char* string){

	printf("%s", message);
	fflush(stdin);
	gets(string);

}
