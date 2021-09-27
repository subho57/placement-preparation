#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
void print(struct node *temp){
    while (temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
void append(struct node **head_ref, int n){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = n;
    newnode->next = NULL;
    if (*head_ref == NULL)
        *head_ref = newnode;
    else{
        struct node *temp = *head_ref;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
}
void removeDuplicate(struct node **head1_ref, struct node **head2_ref){
    if (*head1_ref != NULL){
        struct node *temp1 = *head1_ref;
        while (temp1 != NULL){
            if (*head2_ref == NULL)
                append(head2_ref, temp1->data);
            else{
                struct node *temp2 = *head2_ref;
                int flag = 0;
                while (temp2 != NULL){
                    if (temp1->data == temp2->data){
                        flag = 1;
                        break;
                    }
                    temp2 = temp2->next;
                }
                if (flag == 0)
                    append(head2_ref, temp1->data);
            }
            temp1 = temp1->next;
        }
    }
}
int main(void){
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    int n;
    scanf("%d", &n);
    while (n--){
        int temp;
        scanf("%d", &temp);
        append(&head1, temp);
    }
    removeDuplicate(&head1, &head2);
    print(head2);
    return 0;
}