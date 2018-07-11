/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<malloc.h>


typedef struct node
{
    int data;
    struct node* next;
}node;

void push(node** head , int data)
{
    node* new = (node*)malloc(sizeof(node));
    new->data=data;
    new->next=*head;
    *head=new;
}

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

void reverse (node** head)
{
    node* prev=NULL;
    node* curr=*head;
    node* next=NULL;
    
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        
    }
    
    *head=prev;
}

void binary(unsigned char n)
{
    unsigned char i=1;
    
    for(i=i<<7;i>0;i=i/2)
    {
        (n&i)?printf("1"):printf("0");
    }
    
}

int abs(int x)
{
return x>0?x:-x ;

}

void printDuplicates1(int a[],int n)
{
    int i=0;
    
    for(i=0;i<n;i++)
    {
        if(a[a[i]%n]>=n)
        {
            
            if(a[a[i]%n]< 2*n)
            {
               // printf("repeated : %d-",a[i]%n);
            }
            
        }
        
      a[a[i]%n] +=n;
        
        
    }
    
    for(i=0;i<n;i++)
    {
       
      printf("no - %d, repetiton -%d\n",i,a[i]/n )  ;
    }
}


void printDuplicates (int a[],int n)
{
int i=0;

for(i=0;i<n;i++)
{
    
    if(a[abs(a[i])]>0)
    {
        a[abs(a[i])]=-a[abs(a[i])];
    }
    else
    {
        printf("repeted : %d\n",abs(a[i]));
    }
    
}
    
}


int main()
{
    //binary(8);
    char const *p=NULL;
    char ch='a';
    
    p=&ch;
    
    *p='b';
    
    printf("%c",*p);
    
    int a[]={2,3,3,1,3,2,2};
    int size=sizeof(a)/sizeof(a[0]);
    printDuplicates1(a,size);
    
    
    node* head=NULL;
    for(int i=10;i>0;i--)
    {
        push(&head,i);
    }
    
    printl(head);
    reverse(&head);
    printl(head);
    //printf("Hello World");

    return 0;
}
