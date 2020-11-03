#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int val;
  struct node *next;
} * node_t;

void print_list(node_t head)
{
  node_t current = head;
  printf("The list contains:\n");
  while (current != NULL)
  {
    printf("[%d]", current->val);
    current = current->next;
  }
  printf("\n");
}

node_t createNode(int e)
{
  node_t new_node = (node_t)malloc(sizeof(node_t));
  new_node->val = e;
  new_node->next = NULL;
  return new_node;
}

int append(node_t *head, int e)
{
  if (*head == NULL)
  {
    *head = createNode(e);
  }
  else
  {
    node_t current = *head;
    while (current->next != NULL)
    {
      current = current->next;
    }
    current->next = createNode(e);
  }
  return 1;
}

int prepend(node_t *head, int e)
{
  if (*head == NULL)
  {
    *head = createNode(e);
  }
  else
  {
    node_t new_node = createNode(e);
    new_node->next = *head;
    *head = new_node;
  }
  return 1;
}

int fill_list(node_t *head)
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

  node_t head = NULL;

  printf("\n%d values added\n", fill_list(&head));

  print_list(head);
  return 1;
}