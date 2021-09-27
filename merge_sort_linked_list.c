#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* link;
}node;

void create(node **new)
{
    node* temp;
    temp=(node*)malloc(sizeof(node));
    printf("Enter the value of the node = ");
    scanf("%d",&(temp->data));
    temp->link=NULL;
    if(*new==NULL)
        *new=temp;
    else{
        node* p;
        p=*new;
        while(p->link!=NULL)
            p=p->link;
        p->link=temp;
    }
}
void merge(node **new1, node **new2, node **new3, int n){
    int min=INT_MIN;
    while(n--){
        node *temp1=*new1;
        node *temp2=*new2;
        int min1=INT_MAX, min2=INT_MAX;
        while(temp1!=NULL){
            if(temp1->data < min1 && temp1->data > min)
                min1=temp1->data;
            temp1=temp1->link;
        }
        while(temp2!=NULL){
            if(temp2->data < min2 && temp2->data > min)
                min2=temp2->data;
            temp2=temp2->link;
        }
        min=(min1<=min2)?min1:min2;
        node *temp=(node*)malloc(sizeof(node));
        temp->data=min;
        temp->link=NULL;
        if(*new3==NULL)
            *new3=temp;
        else{
            while((*new3)->link!=NULL)
                new3=&(*new3)->link;
            (*new3)->link=temp;
        }
    }
    printf("Lists Merged Successfully!!");
}
void display(node **head)
{
    node* temp=*head;
    if(temp==NULL)
        printf("Empty List!!");
    else{
        printf("\nPrinting the List : ");
        while(temp!=NULL){
        printf("%d-->",temp->data);
        temp=temp->link;
        }
    }
}
int main(void)
{
    node* new1=NULL;
    node* new2=NULL;
    node* new3=NULL;
    int n1=0, n2=0, n;
    printf("\n#______________________MENU_____________________#");
    printf("\n# 1) Insert into 1st Linked List\t\t#\n# 2) Insert into 2nd Linked List\t\t#\n# 3) To Merge and Sort 1st and 2nd Linked List\t#\n# 4) To Display the 1st Linked List \t\t#\n# 5) To Display the 2nd Linked List \t\t#\n# 6) To Display the Merged Linked List \t\t#\n# 7) Exit\t\t\t\t\t#\n#_______________________________________________#\n");    
    while(1)
    {
        printf("\nEnter your choice: ");
        scanf("%d",&n);
        switch(n)
        {
            case 1: create(&new1);
                    n1++;
                    break;
            case 2: create(&new2);
                    n2++;
                    break;
            case 3: merge(&new1, &new2, &new3, n1+n2);
                    break;
            case 4: display(&new1);
                    break;
            case 5: display(&new2);
                    break;
            case 6: display(&new3);
                    break;
            case 7: exit(0);
            default:printf("Wrong Choice!!");        
        }
    }
    return 0;
}