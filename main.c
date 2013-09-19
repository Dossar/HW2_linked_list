/* 
 * File:   main.c
 * Author: Michael_Meding
 *
 * Created on September 16, 2013, 2:11 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LISTSIZE 1000000
#define MIDPOINT LISTSIZE/2

/*
 * 
 */
int main(int argc, char** argv) {
   srand(time(NULL)); // initalize random number generator with current time as the seed value;
   int random = rand() % 1000000; // generate random number between 0 - 1000000

   clock_t startTime = clock();

   // populate list
   int x = 0;
   for (x = 0; x < LISTSIZE; x++) {
	  l_insert(random); // insert into list
	  random = rand() % 1000000; // generate new random number between 0 - 1000000
   }

   // time taken to check head value
   double time_taken = l_check(1);
   if (time_taken == 0) {
	  printf("time taken to find value = ~1 nanosecond\n");
   } else {
	  printf("time taken to find value = %f seconds\n", time_taken);
   }

   // time taken to check the midpoint value
   time_taken = l_check(MIDPOINT);
   if (time_taken == 0) {
	  printf("time taken to find value = ~1 nanosecond\n");
   } else {
	  printf("time taken to find value = %f seconds\n", time_taken);
   }

   // time taken to check the endpoint value
   time_taken = l_check(LISTSIZE);
   if (time_taken == 0) {
	  printf("time taken to find value = ~1 nanosecond\n");
   } else {
	  printf("time taken to find value = %f seconds\n", time_taken);
   }



   clock_t endTime = clock();
   double cpu_time = (double) (endTime - startTime) / CLOCKS_PER_SEC;
   printf("\ntotal cpu time = %f sec\n", cpu_time);
   return (EXIT_SUCCESS);
}

