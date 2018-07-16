#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define MAX_CHAR   26
#define MAX_TRIE   150

int gSize = 0;

typedef unsigned char uint8_t;

typedef struct node
{
  uint8_t isEnd;
  uint8_t count;
  int children[MAX_CHAR];
}node;

node trie[MAX_TRIE];

int getNode()
{
    if(gSize == MAX_TRIE -1)
        return -1;
        
    trie[gSize].isEnd=0;
    trie[gSize].count=0;
    
    for(int i=0;i<MAX_CHAR;i++)
        trie[gSize].children[i]=-1;
    gSize++;
    
    return gSize-1;
}

void insert (char str[],int head)
{
    //printf("inserting string %s",str);
    int len=strlen(str);
    int c;
    int temp=head;
    for(int i=0;i<len;i++)
    {
        c=str[i]-'a';
        
        if(trie[temp].children[c]==-1)
        {
            trie[temp].children[c]=getNode();
        }
        
        temp= trie[temp].children[c];   
        
    }
    trie[temp].isEnd=1;
    trie[temp].count++;
    //return ;
}

int search (char str[],int head)
{
    int len=strlen(str);
    int c;
    int temp=head;
    for(int i=0;i<len;i++)
    {
        c=str[i]-'a';
        
        if(trie[temp].children[c]==-1)
        {
          return 0;
        }
        
        temp= trie[temp].children[c];   
        
    }
    
    if(trie[temp].isEnd && temp!=-1)
        return trie[temp].count;
    else
        return 0;
}

int main()
{
    // Input keys (use only 'a' through 'z'
    // and lower case)
    char keys[8][20] = {"the","a","mahesh","padmavathi","mahesh","ramesh","thammireddy","mahesh"};
    
    int n = sizeof(keys)/sizeof(keys[0]);
    
    printf("no of str:%d\n",n);
 
    int root = getNode();
 
    
    // Construct trie
    for (int i = 0; i < 8; i++)
        insert(keys[i],root);
 
    // Search for different keys
    int m_count=search("ramksh",root);
                        
    search("thammireddy",root)? printf("Yes\n") :
                        printf("No\n");
    search("venu",root)? printf("Yes\n") :
                        printf("No\n");
    search("padmajar",root)? printf("Yes\n") :
                        printf("No\n");
    //search("these",root)? cout << "Yes\n" :
                          // cout << "No\n";
                          
    printf("m_count : %d",m_count);
    
    for(int i=0;i<gSize;i++)
    {
        
       // printf ("trie[%d].isEnd:%d",i,trie[i].isEnd);
        //printf("\r\r");
        //for(int j=0;j<MAX_CHAR;j++)
            //printf ("trie[%d].children[%d] : %d",i,j,trie[i].children[j]);
        //printf("\n");
        
    }
    return 0;
}



