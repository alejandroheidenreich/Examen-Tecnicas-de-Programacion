#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include "Inputs.h"
#define FREE 0
#define OCCUPY 1

typedef struct{
	int id;
	char name[50];
	char lastname[50];
	int age;
	char sex;
	int seniority;
	float salary;
	int state;

}eEmployee;

int InitializeEmployeeList(eEmployee* list, int length);

void HardCodeEmployeeList(eEmployee* list, int length);

int AddNewEmployee(eEmployee* list, int length, int id, char* name, char* lastname, int age, char sex,int seniority, float salary);

void PrintEmployeeList(eEmployee* list, int length);

int SortEmployeesByLastname(eEmployee* list, int length);

int CountMaleEmployees(eEmployee* list, int length, char sex);

int PercentageEmployeesBySex(eEmployee* list, int length);

void PrintEmployeesYearLeftToRetire(eEmployee* list, int length);

float SalaryAmountPaidOutToEmployees(eEmployee* list, int length);

void PrintHighestSalaryBySex(eEmployee* list, int length, char sex);

void ShowEmployeeByLastname(eEmployee* list, int length);

void ShowEmployeeByID(eEmployee* list, int index);

#endif /* EMPLOYEE_H_ */
