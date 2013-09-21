/**
 * Array function program by Roy Van Liew. Homework 2 was a collaboration between Mike Meding and Roy Van Liew
 * All of the functions here work and the time output looks fine. The function names need to be changed I think, however.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* GLOBAL VARIABLE DECLARATIONS */
#define ARRAYSIZE 1000000
#define mid_value 500000

/* ARRAYS */
int array1[ARRAYSIZE + 5] = {0}; /* define the array to work with, 5 free slots */

/* GLOBAL VARIABLES */
int count = 0; /* Global variable counting how many elements were deleted of a certain value. This is for the mid value function. */
int size2 = ARRAYSIZE; /* This is for dealing with the changing array, initialized to the arraysize value. */

/* FUNCTIONS */
void displayArray(void);
void startOfArray(void);
void removeSOA(void);
void checkPosArr(void);
void remove_big_elements_array(void);
void remove_middle_array(int);

int main(int argc, char** argv) {

  srand(time(NULL)); /* Initalize random number generator with current time as the seed value */

  /* This is for filling in the array. */
  int i;
  for( i = 0 ; i < size2 ; i++ ){
    array1[i] =  (1000* (rand() % 1000)) + (rand() % 1000); /* Since RAND_MAX is defined as (0x7fff) = (32767), we need larger numbers here */
  }

  /* See first 5 elements before functions are performed */
  displayArray();

  /* Add element to the start of the array */
  startOfArray();

  /* Remove element from the start of the array */
  removeSOA();

  /* Check position in the start, middle, and end of the array. */
  checkPosArr();
  checkPosArr();
  checkPosArr();

  /* Remove all elements bigger than 500,000 */
  remove_big_elements_array();

  return 0;

}


/* This function displays the first few elements of the array. */
void displayArray(){

  int i;
  printf("The first 5 elements of the array are: [");
  for( i = 0 ; i < 5 ; i++ ){

    printf("%d,", array1[i] );

  }
  printf("...]\n\n"); /* The first 5 integers of the array have been printed out */

  return;

}

/* This function adds an integer at the start of the array. */
void startOfArray(){

  /* Start time of adding to the start operation */
  clock_t startTime, endTime;
  startTime = clock();

  int i;
  for( i = size2 ; i > -1 ; i-- ){
    array1[i] = array1[i-1]; /* Fills the next position (starting with the position after the last element) with the previous position, this is for shifting the array to compensate for the first element */
  }
  size2 = (size2 + 1); /* After the for loop, increase size2 variable by 1. It wasn't increased before the for loop because it was used for the index as opposed to the total elements. */
  array1[0] = rand() % 1000000; /* Add first element of the array with another randomly generated number between 0 and 1000000 */

  endTime = clock(); /* End time of adding to the start operation */
  double cpu_time = (double)(endTime - startTime) / CLOCKS_PER_SEC;
  printf("Adding to the start of the array took %f seconds.\n", cpu_time );

  displayArray();

  return;

}

/* This function removes an integer at the start of the array. */
void removeSOA(){

  /* Start time of removing from the start operation */
  clock_t startTime, endTime;
  startTime = clock();

  int i;
  int tempdisplay = array1[0];
  for( i = 0 ; i < size2 ; i++ ){
    array1[i] = array1[i+1]; /* Fills the previous position (starting with the first position) with the next position, this is for shifting the array to simulate deleting the first element */
  }
  size2 = (size2 - 1); /* After the for loop, decrease size2 variable by 1. It wasn't decreased before the for loop because it was used for the index as opposed to the total elements before the element was deleted. */

  endTime = clock(); /* End time of removing from the start operation */
  double cpu_time = (double)(endTime - startTime) / CLOCKS_PER_SEC;
  printf("Removing from the start of the array took %f seconds.\n", cpu_time );

  printf("The first element, %d, has been removed.\n", tempdisplay);
  displayArray();

  return;

}

/* This function removes an element in the middle of the array. Used for the remove big elements function. */
void remove_middle_array(int pos){

  /* The integer pos holds the current position that was passed to this function. */
  int i;
  for( i = pos ; i < size2 ; i++ ){
    array1[i] = array1[i+1]; /* Fills the previous position (starting with the first position) with the next position, this is for shifting the array to simulate deleting the current element */
  }
  size2 = (size2 - 1); /* After the for loop, decrease size2 variable by 1. It wasn't decreased before the for loop because it was used for the index as opposed to the total elements before the element was deleted. */

  return;

}

/* This function checks the start position in the array. */
void checkPosArr(){

  int userindex;
  printf("Please enter a position you would like to check for its value: ");
  scanf("%d",&userindex);
  while( userindex < 0 || userindex > size2 - 1 ){
    printf("\nPlease enter a position between 0 and %d: ", (size2-1) );
    scanf("%d",&userindex);
  }

  /* Start time of check operation */
  clock_t startTime, endTime;
  startTime = clock();

  printf("The value at position [%d] is: %d.\n", userindex, array1[userindex] );

  endTime = clock(); /* End time of check operation */
  double cpu_time = (double)(endTime - startTime) / CLOCKS_PER_SEC;
  printf("Checking position [%d] took %f seconds.\n\n", userindex, cpu_time );

  return;

}

/* This function removes all of the values 500,000 and greater in the array. */
void remove_big_elements_array(){

  /* Start time of removing mid_value operation */
  clock_t startTime, endTime;
  startTime = clock();

  count = 0; /* Reinitialize the delete count to zero */
  int i;
  for( i = 0 ; i < size2 ; i++ ){

    if( array1[i] > mid_value ){
        remove_middle_array(i); /* Pass current position i to the remove middle array function to shift the array */
        count++;
        i--; /* This subtraction compensates for the i++ in the for loop parameters */
    } /* End of if statement */

  } /* End of for loop */

  endTime = clock(); /* End time of removing mid_value operation */
  double cpu_time = (double)(endTime - startTime) / CLOCKS_PER_SEC;
  printf("Removing all values > %d took %f seconds.\n", mid_value , cpu_time );

  printf("%d integers with value higher than %d were removed from the array.\n", count, mid_value );
  displayArray();

  return;

}
