// Singly linked list structrure declaration
struct Node {
  int data;
  struct Node *next;
};

// Append node to the end of list
void appendNode(struct Node **head, int data);
