// Do not remove #ifdef ... #endif before and after each function.
// 
// They are used to test different functions in your program and give
// partial credits, in case your program does not work completely.

#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void StudentPrint(Student * stu, int num)
{
  printf("There are %d students\n", num);
  int i;
  for (i = 0; i < num; i ++)
    {
      printf("ID = %d, First Name = %s, Last Name = %s\n",
	     stu[i].ID,  stu[i].firstname, stu[i].lastname);
    }
}

#ifdef TEST_READ
// return false if anything is wrong 
// return true if reading the file successfully and the data is save in
// the allocated memory
// input: filename, the name of the input file
// output: address of the allocated memory
// output: number of students
bool StudentRead(char * filename, Student * * stu, int * numelem)
{
  // open the file to read
  FILE * file;
  file = fopen(filename, "r");
  Student * st;

  if (file == NULL){
  	return false;
  }
  // if fopen fails, return false
  // do not use fclose since fopen already fails

  int lns = 0;
  char nlch = '\n';
  char cch;
  while (fscanf(file, "%c", &cch) == 1){
  	if (cch == nlch){
		lns++;
    }
  }


  // count the number of lines to determine the number of students

  fclose(file);
  FILE * file1 = fopen(filename, "r");

  if (file1 == NULL){
  	return false;
  }

  // return to the beginning of the file
  // you can use fseek or
  // fclose followed by fopen
  // You need to check whether fseek or fopen fails
  // Do not use rewind because it does not report whether it fails


  // allocate memory for the data
  st = malloc(sizeof(Student) * lns);
  * numelem = lns;
  // check whether memory allocation fails
  if (st == NULL){
  	fclose(file1);
  	return false;
  }

  // read the data from the file and store the data in the allocated memory
  int chck = 0;
  int i = 0;
  for(i = 0; i < lns; i++){
  	chck= fscanf(file1, "%d %s %s", &(st[i].ID), (st[i].firstname), (st[i].lastname));
    if(chck != 3){
		fclose(file1);
		return false;
	}
  }
  *stu = st;
  // close the file
  fclose(file1);

  return true;
}
#endif

#ifdef TEST_WRITE
// return false if anything is wrong 
// return true if writing the file successfully
// input: filename, the name of the output file
// input: address of the student array
// input: number of students

bool StudentWrite(char * filename, Student * stu, int numelem)
{
  // open the file to read
  FILE *file = fopen(filename, "w");
  
  if (file == NULL){
  	return false;
  }
  // if fopen fails, return false
  // do not use fclose since fopen already fails
  for(int i = 0; i < numelem; i++){
  	if(fprintf(file, "%d %s %s\n", stu[i].ID, (stu[i]).firstname, (stu[i]).lastname) < 1){
		return false;
	}
  }

  // write the students to the output file
  fclose(file);
  return true;
}
#endif 

#ifdef TEST_SORTID
#endif
int comparID(const void *arg1, const void *arg2){
	const Student * ptr1 = (const Student * ) arg1;
	const Student * ptr2 = (const Student * ) arg2;
	Student val1 = * ptr1;
	Student val2 = * ptr2;
	if(val1.ID < val2.ID) {return -1;}
	if(val1.ID == val2.ID) {return 0;}
	return 1;
}

int comparFirst(const void * arg1, const void * arg2){
	const Student * ptr1 = (const Student *) arg1;
	const Student * ptr2 = (const Student *) arg2;
	Student str1 = * ptr1;
	Student str2 = * ptr2;
	return strcmp(str1.firstname, str2.firstname);
}

int comparLast(const void * arg1, const void * arg2){
	const Student * ptr1 = (const Student *) arg1;
	const Student * ptr2 = (const Student *) arg2;
	Student str1 = * ptr1;
    Student str2 = * ptr2;
	return strcmp(str1.lastname, str2.lastname);
}
#ifdef TEST_SORTFIRSTNAME

void StudentSortbyID(Student * stu, int numelem)
{
	qsort((&stu[0]), numelem, sizeof(Student), comparID);	
}

void StudentSortbyFirstName(Student * stu, int numelem)
{	
	qsort((&stu[0]), numelem, sizeof(Student), comparFirst);	
}
#endif

#ifdef TEST_SORTLASTNAME
void StudentSortbyLastName(Student * stu, int numelem)
{

	qsort((&stu[0]), numelem, sizeof(Student), comparLast);	
}
#endif
