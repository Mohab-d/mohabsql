#include <stdio.h>
#include <stdlib.h>
#include "node.h"

// append data to the end of linked list
void appendNode(struct Node **head, int data)
{

 // If the list is empty return
    if (*head == NULL) {
    printf("The given head is null.\n")
    return;
    }

  // find the list tail
  struct Node *current = *head;
  while(current->next != NULL)
  {
    current = current->next;
  }

  // append new node
  current->next = (struct Node *)malloc(sizeof(struct Node));
  current->next->data = data;
  current->next->next = NULL;
}
