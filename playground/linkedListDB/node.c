#include <stdio.h>
#include <stdlib.h>
#include "node.h"

/*
 * TODO:
 * understand why in the appendNode function we had to use a doubled pointer
 * Understand what is this: *head = new_node astrisk is doing here
 * and here struct Node *current = *head;
 * Understand why we are passing the address of h to the function ($head)
 * Undrstand why can't we pass a NULL head
*/

void appendNode(struct Node **head, int data)
{
  // Allocate memory for new node and initialize it
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  new_node->data = data;
  new_node->next = NULL;

  // if head is null, make it a new node an point it to new_node
  if(head == NULL)
  {
    *head = new_node;
    return;
  }

  // append data to the end of linked list
  struct Node *current = *head;
  while(current->next != NULL)
  {
    current = current->next;
  }

  current->next = new_node;
}


int main()
{

  // every thing was fine (I hope :D).
  return 0;
}
