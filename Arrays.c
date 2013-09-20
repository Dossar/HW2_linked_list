/**
 * IMPORTANT! All of my code here looks like it will probably work for the arrays portion of the assignment.
 * We can change the array size and mid value numbers later, this is just to test that the functions work first before the big values come in.
 * I kept getting an error message saying that size2 is undeclared even though I declared it as a global function.
 * size2 is a global variable that keeps track of the array's current size. But it's apparently "undeclared". Look into this?
 * I also commented out the functions that were in the previous arrays.c file
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* #include "Arrays.h" */

/* GLOBAL VARIABLE DECLARATIONS */
#define ARRAYSIZE 10
#define mid_value 5

/* ARRAYS */
int array1[ARRAYSIZE + 5] = {0}; /* define the array to work with, 5 free slots */

/* GLOBAL VARIABLES */
int count = 0; /* Global variable counting how many elements were deleted of a certain value. This is for the mid value function. */
int size2 = ARRAYSIZE; /* This is for dealing with the changing array, initialized to the arraysize value. */

/* FUNCTIONS */
void fillArray(void);
void displayArray(void);
void startOfArray(void);
void removeSOA(void);
void checkPosArr(void);
void remove_big_elements_array(void);
void remove_middle_array(int);

int main(int argc, char** argv) {

  fillArray();
  displayArray();
  startOfArray();
  removeSOA();
  checkPosArr();
  checkPosArr();
  checkPosArr();
  remove_big_elements_array();

  return 0;

}

/* This function fills in the array. */
void fillArray(){

  int i;
  for( i = 0 ; i < size2 ; i++ ){
    array1[i] = (i+1); /* Fill the first 10 spots of the array with integers 1-10 */
  }

  return;

}

/* This function displays the current array. */
void displayArray(){

  int i;
  printf("The current array is: [ ");
  for( i = 0 ; i < size2 ; i++ ){

    printf("%d ", array1[i] );

  }
  printf("]\n\n"); /* The array has been printed out */

  return;

}

/* This function adds an integer at the start of the array. */
void startOfArray(){

  int i;
  for( i = size2 ; i >= 0 ; i-- ){
    array1[i] = array1[i-1]; /* Fills the next position (starting with the position after the last element) with the previous position, this is for shifting the array to compensate for the first element */
  }
  int size2 = ++size2; /* After the for loop, increase size2 variable by 1. It wasn't increased before the for loop because it was used for the index as opposed to the total elements. */
  printf("Please input an integer to insert at the start of the array: ");
  scanf("%d",array1[0]); /* Save user's input into start of the array */
  printf("\n");
  displayArray();

  return;

}

/* This function removes an integer at the start of the array. */
void removeSOA(){

  int i;
  for( i = 0 ; i < size2 ; i++ ){
    array1[i] = array1[i+1]; /* Fills the previous position (starting with the first position) with the next position, this is for shifting the array to simulate deleting the first element */
  }
  int size2 = --size2; /* After the for loop, decrease size2 variable by 1. It wasn't decreased before the for loop because it was used for the index as opposed to the total elements before the element was deleted. */
  printf("\n");
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
  int size2 = --size2; /* After the for loop, decrease size2 variable by 1. It wasn't decreased before the for loop because it was used for the index as opposed to the total elements before the element was deleted. */
  printf("\n");

  return;

}

/* This function checks a certain position in the array. */
void checkPosArr(){

  int userindex;
  printf("Please enter the position in the array would you like to check the integer value: ");
  scanf("%d",&userindex);
  while( userindex < 0 || userindex > size2 - 1 ){
    printf("\nPlease enter a position between 0 and &d: ", (size2-1) );
    scanf("%d",&userindex);
  }
  printf("The value at position %d is: %d.\n\n", userindex, array1[userindex] );

  return;

}

/* This function removes all of the values 500,000 and greater in the array. */
void remove_big_elements_array(){

  count = 0; /* Reinitialize the delete count to zero */
  int i;
  for( i = 0 ; i < size2 - 1 ; i++ ){

    if( array1[i] > mid_value )
    {
      remove_middle_array(i); /* Pass current position i to the remove middle array function to shift the array */
      count++;
    }

  }
  printf("%d integers with value higher than %d were removed from the array.\n", count, mid_value );
  displayArray();

  return;

}

/* void a_check(int position) {
   clock_t startTime = clock();
   
   printf("%d\n",array[position]);

   clock_t endTime = clock();
   double cpu_time = (double) (endTime - startTime);
   printf("query time = %f", cpu_time);
}

void a_insert_start(int data) {

}

void a_remove_start(void) {

}

void a_display() {
   int x = 0;
   while(x < count){
	  printf("%d\n",array[x]);
   }
} */
