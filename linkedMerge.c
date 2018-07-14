#include <stdio.h>
#include<malloc.h>

typedef struct node
{
    int data;
    struct node* next;
}node;
void printl(node* head)
{
    node* curr=head;
    
    while(curr !=NULL)
    {
        printf("%d->",curr->data);
        curr=curr->next;
    }
    printf("NULL\n");
}
node* merge(node* a ,node* b)
{
    
    node* result=NULL;
    
    if(a==NULL)
        return b;
    if(b==NULL)
        return a;
        
    if(a->data < b->data)
    {
        result=a;
        result->next=merge(a->next,b);
    }
    else
    {
        result=b;
        result->next=merge(a,b->next);
    }
    return result;
}
int main()
{
    node* head=NULL;
    node* head1=NULL;
    for(int i=100;i>0;i=i-2)
    {
        push(&head,i);
    }
    for(int i=99;i>0;i=i-2)
    {
        push(&head1,i);
    }
    printl(head);
    printl(head1);
    head=merge (head , head1);
    //reverse(&head);
    printl(head);
    //printf("Hello World");

    return 0;
}
