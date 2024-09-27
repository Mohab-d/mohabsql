#include <stdio.h>
#include <stdlib.h>
#include "node.h"

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
  struct Node *head = (struct Node *)malloc(sizeof(struct Node));
  head->data = 0;
  head->next = NULL;

  appendNode(&head, 4);
  appendNode(&head, 8);
  appendNode(&head, 9);

  // Print the linked list
    struct Node* current = head->next;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

  // every thing was fine (I hope :D).
  return 0;
}
