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