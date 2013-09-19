/* 
 * File:   main.c
 * Author: Michael_Meding
 *
 * Created on September 16, 2013, 2:11 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * 
 */
int main(int argc, char** argv) {

   clock_t startTime = clock();

   // something that takes a lot of execution time.
   //    int x = 0;
   //    int y = 0;    
   //    for (x = 0; x < 100000; x++) {
   //        y = 0;
   //        while (y < 100000) {
   //            y++;
   //        }
   //    }

   
   l_check(5);
   l_display();

   clock_t endTime = clock();
   double cpu_time = (double) (endTime - startTime);
   printf("\ntotal cpu time = %f\n", cpu_time);
   return (EXIT_SUCCESS);
}

