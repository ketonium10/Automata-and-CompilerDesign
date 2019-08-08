#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node {
char name;
struct node* ptr_0;
struct node* ptr_1;
};
void push(struct node** head_ref, char data){

//1. allocate node
struct node* new_node = (struct node*)malloc(sizeof(struct node));
//2.naming
new_node->name = data;
//3.referencing
new_node->ptr_0 = NULL;
new_node->ptr_1=(*head_ref);
//4.change prev of head node to new node
if((*head_ref)!=NULL){
    (*head_ref)->ptr_0 = new_node;
}
(*head_ref) = new_node;
}
void append(struct Node** head_ref, char label)
{
    /* 1. allocate node */
   struct node* new_node = (struct node*)malloc(sizeof(struct node));
    struct node* last = *head_ref; /* used in step 5*/

    /* 2. put in the data */
    new_node->name = label;

    /* 3. This new node is going to be the last node, so
        make next of it as NULL*/
    new_node->ptr_1 = NULL;

    /* 4. If the Linked List is empty, then make the new
        node as head */
    if (*head_ref == NULL)
    {
        new_node->ptr_0 = NULL;
        *head_ref = new_node;
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->ptr_1 != NULL)
        last = last->ptr_1;

    /* 6. Change the next of last node */
    last->ptr_1 = new_node;

    /* 7. Make last node as previous of new node */
    new_node->ptr_0 = last;

    return;
}
void main(){

struct node* head = NULL;
//inserting A so C->null
append(&head, 'C');
//inserting B so B->C->null
push(&head, 'B');
//inserting A so A->B->C->null
push(&head,'A');

struct node *ptr = head;
ptr->ptr_0 = (ptr->ptr_1);
ptr->ptr_1 = ptr;
//moving to next
ptr=ptr->ptr_0;
ptr->ptr_0=ptr;
//moving to next
ptr=ptr->ptr_1;
ptr->ptr_1=head;

int c;
ptr=head;

printf("Enter input ");
scanf("%d",&c);

while(c==0 || c==1){
    if(c==0){
        ptr=ptr->ptr_0;
    }
    else if(c==1){
        ptr=ptr->ptr_1;
    }
   printf("Enter input ");
   scanf("%d",&c);
}
  printf("%c",ptr->name);





}
