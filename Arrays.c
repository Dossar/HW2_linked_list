/**
 * This source file contains all the info needed for arrays
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Arrays.h"
#define ARRAYSIZE 1000

int array[ARRAYSIZE] = {}; // define the array to work with
int count = ARRAYSIZE; // size counter

void a_check(int position) {
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
}
