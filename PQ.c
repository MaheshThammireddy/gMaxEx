
#define MAX_SIZE 50

#define left(i) 2*i+1
#define right(i) 2*i+2
#define parent(i) (i-1)/2

void swap(int*a , int*b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
    
}

int arr[MAX_SIZE];
int gSize=0;


int insertKey(int key);
int decreaseKey(int i , int key);
int getMin();
void minHeapify(int i);
void deleteKey(int i);
int extractMin();

int insertKey(int key)
{
    if(gSize==MAX_SIZE-1)
        return 0;
    gSize++;
    int i=gSize-1;
    
    arr[i]=key;

    while(i!=0 && arr[i]<arr[parent(i)])
    {
        swap(&arr[i],&arr[parent(i)]);
        i=parent(i);
        
    }
    
    
}

int decreaseKey(int i , int key)
{
    arr[i]=key;
    
    while(i!=0 && arr[i]<arr[parent(i)])
    {
        swap(&arr[i],&arr[parent(i)]);
        i=parent(i);
        
    }
    
}

int getMin()
{
    return arr[0];
}

void minHeapify(int i)
{
    int smallest=i;
    int l=left(i);
    int r=right(i);
    
    if(l<gSize && arr[l] < arr[i])
        smallest=l;
    if(r<gSize && arr[r] < arr[smallest])
        smallest=r;
    
    if(smallest!=i)
    {
        swap(&arr[i],&arr[smallest]);
        
        minHeapify(smallest);
    }
    
}

int extractMin()
{
    if(gSize==0)
        return 0;
    if(gSize==1)
    {
        gSize=0;
        return arr[0];
    }
    
    int root=arr[0];
    arr[0]=arr[gSize-1];
    gSize--;
    minHeapify(0);
    return root;
    
}

void deleteKey(int i)
{
    decreaseKey(i,-99999);
    
    extractMin();
    
}


/************PQ**************/


int main()
{
    
    insertKey(3);
    insertKey(2);
    deleteKey(1);
    insertKey(15);
    insertKey(5);
    insertKey(4);
    insertKey(45);
    printf("%d" ,extractMin() );
    printf("%d" ,getMin() );
    
    decreaseKey(2, 1);
    printf("%d" ,getMin() );
   
    return 0;
}
