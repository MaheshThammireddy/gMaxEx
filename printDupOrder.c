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

