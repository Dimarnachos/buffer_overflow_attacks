#include <stdio.h>
#include <string.h>

// processes a student ID to obtain individual sum
int sum_id(char* user_input)
{
	int sum = 0;
	char* p;
	for(p = user_input; *p != '\0'; p++)
	{
		int value = *p - '0';
		sum = sum + value;
	}
	return sum;
}

int main()
{
	char student_id_1[9]; // student id 1 (char with 8 bits)
	char student_id_2[9]; // student id 2 (char with 8 bits)
	int sum = 0; // final sum of both student ids

	printf("[BEFORE] sum: address %p with value of %s\n",sum, sum);

	printf("Enter Student ID 1:\n");
	scanf("%s",student_id_1);
	printf("[BEFORE] student_id_1: address %p with value of %s\n",student_id_1, student_id_1);

	printf("Enter Student ID 2:\n");
	scanf("%s",student_id_2);
	printf("[BEFORE] student_id_2: address %p with value of %s\n",student_id_2, student_id_2);

	printf("[AFTER] student_id_1: address %p with value of %s\n",student_id_1, student_id_1);
	printf("[AFTER] student_id_2: address %p with value of %s\n",student_id_2, student_id_2);

	size_t length1 = strlen(student_id_1);
	size_t length2 = strlen(student_id_2);

	if((length1 > 8) || (length2 > 8))
	{
    	printf("Buffer overflow! Please enter in an ID 8 digits or less.");
   		exit(0);
 	}
 	printf("No buffer overflow!\n");

	sum = sum_id(student_id_1) + sum_id(student_id_2);
	printf("[SUM] sum: address %p with value of %i\n",sum, sum);

	return 0;
}