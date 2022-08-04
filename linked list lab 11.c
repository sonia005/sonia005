#include <stdio.h>
#include <stdlib.h>
struct Node
{
  int data;
  struct Node* next;
};
void insertAtBeginning(struct Node** head_ref, int new_data)
{
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}
void insertAtEnd(struct Node** head_ref, int new_data) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  struct Node* last = *head_ref;

  new_node->data = new_data;
  new_node->next = NULL;

  if (*head_ref == NULL) {
  *head_ref = new_node;
  return;
  }

  while (last->next != NULL) last = last->next;

  last->next = new_node;
  return;
}
void deleteNode(struct Node** head_ref, int key) {
  struct Node *temp = *head_ref, *prev;

  if (temp != NULL && temp->data == key) {
  *head_ref = temp->next;
  free(temp);
  return;
  }
  while (temp != NULL && temp->data != key) {
  prev = temp;
  temp = temp->next;
  }
  if (temp == NULL) return;
  prev->next = temp->next;
  free(temp);
}
void printList(struct Node* node) {
  while (node != NULL) {
  printf(" %d ", node->data);
  node = node->next;
  }
}
int main()
{
    struct Node* head = NULL;

    printf("Inserting 2 at the front of LL.\n");
    insertAtBeginning(&head, 2);
    printf("LL after inserting 2 at the front:");
    printList(head);
    printf("\n\n");

    printf("Inserting 1 at the end of LL.\n");
    insertAtEnd(&head, 1);
    printf("LL after inserting 1 at the end:");
    printList(head);
    printf("\n\n");

    printf("Inserting 3 at the front of LL.\n");
    insertAtBeginning(&head, 3);
    printf("LL after inserting 3 at the front:");
    printList(head);
    printf("\n");

    printf("Inserting 4 at the end of LL.\n");
    insertAtEnd(&head, 4);
    printf("LL after inserting 4 at the end:");
    printList(head);
    printf("\n\n");

    printf("\nDeleting 2 from the LL: ");
    deleteNode(&head, 2);
    printf("\nAfter deleting an element: ");
    printList(head);
    printf("\n\n");

}
