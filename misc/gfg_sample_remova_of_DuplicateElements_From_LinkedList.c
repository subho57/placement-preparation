/* C program to remove duplicates from a linked list */
#include <stdio.h>
#include <stdlib.h>

/* Structure for a node */
struct node
{
    int data;
    struct node *next;
};

/* Function to insert a node */
void insert_elements(struct node **head, int new_data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head);
    (*head) = new_node;
}

/* Function to print nodes */
void display_list(struct node *node)
{
    while (node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
}

/* Function to remove duplicates from a sorted list */
void remove_duplicate_elements(struct node *temp)
{
    struct node *ptr1, *ptr2, *duplicate;
    ptr1 = temp;

    while (ptr1 != NULL && ptr1->next != NULL)
    {

        ptr2 = ptr1;

        /* Compare the current element with rest of the elements */
        while (ptr2->next != NULL)
        {
            if (ptr1->data == ptr2->next->data)
            {
                duplicate = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete (duplicate);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

int main()
{
    struct node *head = NULL;
    int n;
    printf("\nEnter the total number of elements : ");
    scanf("%d", &n);
    printf("\nEnter the unsorted linked list : ");
    int i;
    for (i = 0; i < n; i++)
    {
        int data;
        scanf("%d", &data);
        insert_elements(&head, data);
    }

    printf("\nLinked list before removing duplicates : ");
    display_list(head);
    printf("\n");

    remove_duplicate_elements(head);

    printf("\nLinked list after removing duplicates : ");
    display_list(head);
    printf("\n");

    return 0;
}