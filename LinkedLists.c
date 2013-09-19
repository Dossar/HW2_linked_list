/**
 * This source contains all the info needed for creating and working with linked lists.
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedLists.h"

// define my node and its structure

typedef struct Node {
   int data;
   struct Node *next;
} Node;

Node *head; // create a head of the node stack pointer

void l_check(int position) { // returns the value stored after iterating the given number of times from the head
   printf("input position = %d", position);
}

void l_insert(int num) { // inserts a new node and makes that node the new head of the stack
   Node *temp;
   temp = (Node *) malloc(sizeof (Node)); // allocates all the memory space for a new node.
   temp->data = num; // set the data in the node to the input num
   if (head == NULL) {
	  head = temp; 
	  head->next = NULL;
   } else {
	  temp->next = head; // the current address of head becomes the next value of temp, placing it before head in the hierarchy
	  head = temp; // temp then becomes the new head.
   }
}

void l_remove(void) { // removes the head node and the next pointer becomes the new head.

}

void l_display(void) { // display all currently linked values
   
}

//void l_display(int start) { // display all the values from the start index till the specified value
//
//}

void l_remove_big_elements() { // remove all the data with an index larger than that of the midpoint.

}