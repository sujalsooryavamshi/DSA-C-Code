// calculate the depth of the tree in which 
#include<stdio.h>
#include<string.h>
int caldepth(char [],int,int);
int max(int,int);
main()
{
    
    char tree[10];
    printf("Enter the string of n and l "); // n is the internal node and l is the leaf node
    scanf("%s",tree);
    int n=strlen(tree);
    int index=0;
   printf("The depth of the tree is : %d",caldepth(tree,index,n));
}
int caldepth(char tree[],int index,int n)
{
     if(index>=n || tree[index]=='l')
        return 0;
    
    ++index;
    int left=caldepth(tree,index,n);

    ++index;
    int right=caldepth(tree,index,n);

    return max(left,right)+1;
}
int max(int l,int r)
{
  return (l>r ? l : r);
}