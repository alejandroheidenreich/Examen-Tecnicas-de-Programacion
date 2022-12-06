#include "Employee.h"


int InitializeEmployeeList(eEmployee* list, int length){
	int success = -1;

	if(list != NULL && length > 0){
		success = 0;
		for(int i=0; i < length; i++){
			list[i].state = FREE;
		}
	}
	return success;
}

void HardCodeEmployeeList(eEmployee* list, int length){
	AddNewEmployee(list,length,1,"Dusty","Layzell",42,'F',14,123900.00);
	AddNewEmployee(list,length,2,"Orren","Waddilove",41,'M',24,132294.50);
	AddNewEmployee(list,length,3,"Buckie","Long",59,'M',21,106105.10);
	AddNewEmployee(list,length,4,"Brocky","Rennicks",24,'M',4,142535.15);
	AddNewEmployee(list,length,5,"Orlan","Luna",28,'M',3,225199.99);
	AddNewEmployee(list,length,6,"Martina","Du Fray",40,'F',9,155388.65);
	AddNewEmployee(list,length,7,"Alengtha","Bonifas",58,'F',21,248276.45);
	AddNewEmployee(list,length,8,"Ingmar","Long",45,'M',15,144270.00);
	AddNewEmployee(list,length,9,"Cathi","Swinney",26,'X',6,227479.65);
	AddNewEmployee(list,length,10,"Roman","Clarke",27,'M',9,137852.33);
	AddNewEmployee(list,length,11,"Lynnelle","Rembrant",59,'F',6,203352.77);
	AddNewEmployee(list,length,12,"Janeen","Osgordby",40,'F',22,197090.82);
	AddNewEmployee(list,length,13,"Graehme","Corby",58,'M',19,83048.43);
	AddNewEmployee(list,length,14,"Eddi","Fearnsides",33,'F',14,189228.25);
	AddNewEmployee(list,length,15,"Augustina","Scirman",36,'F',17,224972.75);
	AddNewEmployee(list,length,16,"Lucille","Wildblood",27,'F',14,207006.55);
	AddNewEmployee(list,length,17,"Dorri","Gerring",18,'F',16,128537.36);
	AddNewEmployee(list,length,18,"Cristabel","Callaway",49,'F',13,116894.41);
	AddNewEmployee(list,length,19,"Bryanty","Buttriss",57,'M',23,176004.77);
	AddNewEmployee(list,length,20,"Jennilee","Hilhouse",58,'F',14,153397.69);
}

int AddNewEmployee(eEmployee* list, int length, int id, char* name, char* lastname, int age, char sex,int seniority, float salary){
	int success = -1;

	for(int i=0; i<length; i++){
		if(list[i].state == 0){
			success = 0;
			list[i].state = 1;
			list[i].id = id;
			strcpy(list[i].name, name);
			strcpy(list[i].lastname, lastname);
			list[i].age = age;
			list[i].sex = sex;
			list[i].seniority = seniority;
			list[i].salary = salary;
			break;
		}
	}
	return success;
}

void PrintEmployeeList(eEmployee* list, int length){
	printf("+=======================================================================================================+\n");
	printf("|| ID |        NAME          |           LASTNAME           |  AGE  | SEX | SENIORITY |     SALARY     ||\n");
	printf("+=======================================================================================================+\n");
	for(int i=0; i<length; i++){
		if(list[i].state == 1){
			printf("||%4d|%22s|%30s|%7d|%5c|%11d|$ %-14.2f||\n",list[i].id,list[i].name,list[i].lastname,list[i].age,list[i].sex,list[i].seniority,list[i].salary);
			printf("+-------------------------------------------------------------------------------------------------------+\n\n");
		}
	}
}

int SortEmployeesByLastname(eEmployee* list, int length)
{
	int success = -1;
	eEmployee aux;

	if(list != NULL && length > 0){
		success = 0;
		for(int i=0; i<length; i++){
			for(int j=0; j<length; j++){
				if(list[i].state == 1 && (strcmp(list[i].lastname,list[j].lastname)<0)){
					aux = list[i];
					list[i]=list[j];
					list[j]=aux;
				}
			}
		}
	}
    return success;
}

int CountMaleEmployees(eEmployee* list, int length, char sex){
	int count = 0;

	if(list != NULL && length > 0 && (sex == 'M' || sex == 'F' || sex == 'X')){
		for(int i=0; i<length; i++){
			if(list[i].state == 1 && list[i].sex == sex){
				count++;
			}
		}
	}
	return count;
}

int PercentageEmployeesBySex(eEmployee* list, int length){
	int success = -1;
	int quantityMale;
	int quantityFemale;
	int quantityBinary;

	if(list != NULL && length > 0){
		success = 0;
		quantityMale = CountMaleEmployees(list, length, 'M');
		quantityFemale = CountMaleEmployees(list, length, 'F');
		quantityBinary = CountMaleEmployees(list, length, 'X');
		printf(	"Porcentaje de empleados por genero\n"
				"Masculino: %d %% \n"
				"Femenino: %d %% \n"
				"Binario: %d %% \n\n",quantityMale*100/length,quantityFemale*100/length,quantityBinary*100/length);
	}

	return success;
}

void PrintEmployeesYearLeftToRetire(eEmployee* list, int length){
	if(list != NULL && length > 0){
		for(int i=0; i< length; i++){
			if(list[i].state == 1){
				printf("%s %s le faltan %d para jublirse\n",list[i].name,list[i].lastname,60-list[i].age);
			}
		}
	}
}

float SalaryAmountPaidOutToEmployees(eEmployee* list, int length){
	float totalSalary = 0;

	if(list != NULL && length > 0){
		for(int i=0; i<length; i++){
			if(list[i].state == 1){
				totalSalary+=list[i].salary;
			}
		}
	}
	return totalSalary;
}

float FindSexHigherSalary(eEmployee* list, int length, char sex){
	float higherSalary=0;

	if(list != NULL && length > 0 && (sex == 'M' || sex == 'F' || sex == 'X')){
		for(int i=0; i < length; i++){
			if(list[i].state == 1 && list[i].sex == sex && higherSalary < list[i].salary){
				higherSalary = list[i].salary;
			}
		}
	}
	return higherSalary;
}

void PrintHighestSalaryBySex(eEmployee* list, int length, char sex){
	float higherSalary = FindSexHigherSalary(list,length,sex);

	if(higherSalary != 0){
		for(int i=0; i < length; i++){
			if(list[i].state == 1 && list[i].salary == higherSalary){
				ShowEmployeeByID(list,i);
			}
		}
	}
}

void ShowEmployeeByLastname(eEmployee* list, int length){
	char lastname[50];
	int found = 0;

	if(list != NULL && length > 0){
		InputString("Ingrese apellido:\n", lastname);
		for(int i=0; i<length; i++){
			if(stricmp(list[i].lastname,lastname) == 0){
				found = 1;
				ShowEmployeeByID(list, i);
				printf("Anio de jubilacion: %d\n\n",2022+(60-list[i].age));
			}
		}
	}
	if(found == 0){
		printf("No se encontraronn empleados con ese apellido\n\n");
	}
}

void ShowEmployeeByID(eEmployee* list, int index){
	if(list != NULL && index > -1){
		printf(	"ID: %d\n"
				"Nombre: %s\n"
				"Apellido: %s\n"
				"Edad: %d\n"
				"Sexo: %c\n"
				"Anitguedad: %d\n"
				"Salario: %.2f\n\n",list[index].id,list[index].name,list[index].lastname,list[index].age,list[index].sex,list[index].seniority,list[index].salary);
	}
}
