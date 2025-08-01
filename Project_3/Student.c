/* Student.c: maintaining student records */

#include "Student.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

/* allocate a new student record */
STUDENT *NewStudent(int ID, char *Name, char Grade)
{
    
	//create a pointer s that points to student struct
	STUDENT *s = NULL; 
	
	//allocate memory for student struct 
	s = malloc(sizeof(STUDENT));	

	//check that malloc didn't return NULL
	if (s == NULL)
	{
	perror("msg"); 
	exit(10);
	}

	//copy information passed to function to the struct 
	s->ID = ID;
	strncpy(s->Name, Name, SLEN);
	s->Name[SLEN] = '\0';
	s->Grade = Grade;
	//return s to the main
	return s;
} /* end of NewStudent */

/* delete a student record */
void DeleteStudent(STUDENT *s)
{
	
	//add asserts that s exists before freeing memory
	assert(s != NULL);	

	//free memory that was allocated in "New Student"
	free(s);
	
} /* end of DeleteStudent */

/* print a student record */
void PrintStudent(STUDENT *s)
{
    assert(s);
    printf("Student ID:    %d\n", s->ID);
    printf("Student Name:  %s\n", s->Name);
    printf("Student Grade: %c\n", s->Grade);
} /* end of PrintStudent */

/* test the student record functions */
int main(void)
{
    STUDENT *s1 = NULL, *s2 = NULL;
    printf("Creating 2 student records...\n");
    s1 = NewStudent(1001, "Jane Doe", 'A');
    s2 = NewStudent(1002, "John Doe", 'C');

    printf("Printing the student records...\n");
    PrintStudent(s1);
    PrintStudent(s2);

    printf("Deleting the student records...\n");
    DeleteStudent(s1);
    s1 = NULL;
    DeleteStudent(s2);
    s2 = NULL;
    
    printf("Done.\n");
    return 0;
} /* end of main */

/* EOF */
