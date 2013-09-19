/**
 * This source contains all the info needed for creating and working with linked lists.
 */

#include "LinkedLists.h"

// define my node and its structure

typedef struct Node {
   int data;
   struct Node *next;
} Node;

Node *head; // create a head of the node stack pointer

double l_check(int position) { // returns the value stored after iterating the given number of times from the head
   clock_t startTime = clock();

   Node *n = head;
   int count = 0;

   printf("input position = %d\n", position);
   while (count < position) {
	  if (n->next == NULL) {
		 count = 0; // reset count value
		 break; // break out of the loop.
	  } else {
		 n = n->next;
		 count++;
	  }
   }
   if (count == 0) {
	  printf("exceeded stack size, end value = %d\n", n->data);
   } else {
	  printf("data value = %d\n", n->data);
   }


   clock_t endTime = clock();
   double cpu_time = (double) (endTime - startTime) / CLOCKS_PER_SEC;

   return cpu_time;

}

/**
 *  inserts a new node and makes that node the new head of the stack
 * @param num (the data to be inserted into the stack.)
 */
void l_insert(int num) {
   Node *temp;
   temp = (Node *) malloc(sizeof (Node)); // allocates all the memory space for a new node.
   temp->data = num; // set the data in the node to the input num
   if (head == NULL) {
	  head = temp; // temp becomes the new head if none exists
	  head->next = NULL;
   } else {
	  temp->next = head; // the current address of head becomes the next value of temp, placing it before head in the hierarchy
	  head = temp; // temp then becomes the new head.
   }
}

/**
 *  removes the head node and the next pointer becomes the new head.
 */
void l_remove(void) {
   Node *temp = head;

   if (temp->next == NULL) {
	  free(head); // empty the stack if the stack is only of size 1;
   } else {
	  temp = head->next; // temp becomes the next node after head in the stack
	  free(head); // free the memory of the head node
	  head = temp; // temp becomes the new head	  
   }

}

/**
 * display all currently linked values
 */
void l_display(void) {
   Node *r; // create referance node
   r = head; // make it equal to the head node
   if (r == NULL) { // if no stack exists
	  printf("stack is empty.");
   }
   while (r != NULL) {
	  printf("%d ", r->data); // print the values so long as there is data
	  r = r->next; // move pointer to the next value
   }
   printf("\n");
}

/**
 * displays the the number of values from the head to the specified start value
 * @param start = the number of items to display from the head item
 */
void l_display_count(int start) {
   Node *r; // create referance node
   int count = 0;
   r = head; // make it equal to the head node
   if (r == NULL) { // if no stack exists
	  printf("stack is empty.");
   }
   while (r != NULL && count < start) {
	  printf("%d ", r->data); // print the values so long as there is data
	  r = r->next; // move pointer to the next value
	  count++;
   }
   printf("\n");
}

/**
 *  remove all the data with an index larger than that of the midpoint.
 */
void l_remove_big_elements() {
   
   // get the total size of the array.
   // find the midpoint value address
   // free memory of all values following that midpoint until next == NULL

}