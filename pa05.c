// You must modify this file
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "student.h"

// --------------------------------------------------------------
int main(int argc, char * * argv)
{
  // argv[1]: input file name
  // argv[2]: output file name, sorted by ID
  // argv[3]: output file name, sorted by first name
  // argv[4]: output file name, sorted by last name
  if (argc < 5)
    {
      return EXIT_FAILURE;
    }
  // create the necessary variables
  Student * stu;
  char * filename = argv[1];
  bool check;
  int numelem = 0;


  // read students from the input file
  // return EXIT_FAILURE if reading fails
  check = StudentRead(filename, &stu, &numelem);

  if (check == 0){
  	return EXIT_FAILURE;
  }

  // sort the students by IDs
  
  StudentSortbyID(stu, numelem);
  check = StudentWrite(argv[2], stu, numelem);
  // write the result to the output (name is argv[2])
  // return EXIT_FAILURE if writing fails
  if (check == 0){
  	return EXIT_FAILURE;
  }

  // sort the students by first names
  
  StudentSortbyFirstName(stu, numelem);
  check = StudentWrite(argv[3], stu, numelem);
  // write the result to the output (name is argv[3])
  // return EXIT_FAILURE if writing fails

  if (check == 0){
  	return EXIT_FAILURE;
  }

  // sort the students by last names
  
  StudentSortbyLastName(stu, numelem);
  check = StudentWrite(argv[4], stu, numelem);

  // write the result to the output (name is argv[4])
  // return EXIT_FAILURE if writing fails

  if (check == false){
  	return EXIT_FAILURE;
  }

  // release allocated memory
  free(stu);




  return EXIT_SUCCESS;
}
