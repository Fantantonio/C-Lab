#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int val;
  struct node *next;
} * Node;

void print_list(Node head)
{
  Node current = head;
  printf("The list contains:\n");
  while (current != NULL)
  {
    printf("[%d]", current->val);
    current = current->next;
  }
  printf("\n");
}

Node createNode(int e)
{
  Node new_node = (Node)malloc(sizeof(Node));
  new_node->val = e;
  new_node->next = NULL;
  return new_node;
}

int append(Node *head, int e)
{
  if (*head == NULL)
  {
    *head = createNode(e);
  }
  else
  {
    Node current = *head;
    while (current->next != NULL)
    {
      current = current->next;
    }
    current->next = createNode(e);
  }
  return 1;
}

int prepend(Node *head, int e)
{
  if (*head == NULL)
  {
    *head = createNode(e);
  }
  else
  {
    Node new_node = createNode(e);
    new_node->next = *head;
    *head = new_node;
  }
  return 1;
}

int fill_list(Node *head)
{
  int i = 0;
  char input;
  input = getchar();
  while (input != 'Q')
  {
    if (input != '\n')
    {
      i += prepend(head, atoi(&input));
    }
    input = getchar();
  }
  return i;
}

int main()
{
  printf("\nAdd values to list. Press Q + Enter to stop\n");

  Node head = NULL;

  printf("\n%d values added\n", fill_list(&head));

  print_list(head);
  return 1;
}