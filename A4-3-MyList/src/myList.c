/**
 @file myList.c
 @author Jenny Dietrich
 @date 1.0
 @brief simple linked employee list
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct emplInfo {
	char name[41];
	int pID;
	float salary;
	struct emplInfo *nextEmpl;
} emplInfo_t;

/**
 * add a employee node to the list
 * @param list the list to update
 * @param name the name of the employee
 * @param pID the id of the employee
 * @param salary the salary of the employee
 */
void addNode(emplInfo_t **list, char name[41], int pID, float salary) {

	emplInfo_t *employee;
	employee = malloc(sizeof(*employee));
	strcpy(employee->name, name);
	employee->pID = pID;
	employee->salary = salary;
	employee->nextEmpl = NULL;

	while (*list != NULL) {
		list = &(*list)->nextEmpl;
	}

	*list = employee;
}

/**
 * prints whole list
 *
 * @param list the list to print
 */
void print(emplInfo_t **list) {
	while (*list != NULL) {
		printf("{%s, %i, %f}\n", (*list)->name, (*list)->pID, (*list)->salary);
		list = &(*list)->nextEmpl;
	}
}

int main(int argc, char const *argv[]) {
	printf("Wie viele Datensätze an Mitarbeitern?\n");
	unsigned int amount;
	scanf("%ui", &amount);
	struct emplInfo *list;
	list = NULL;

	char name[41];
	int pID;
	float salary;

	for (int i = 0; i < amount; i++) {
		printf("\n%i. Datensatz:\n", i + 1);
		printf("name:");
		scanf("%s", name);
		printf("pID:");
		scanf("%i", &pID);
		printf("salary:");
		scanf("%f", &salary);
	}
	print(&list);

	return 0;
}
