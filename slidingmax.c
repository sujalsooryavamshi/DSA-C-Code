#include<stdio.h>
void printMax(int size,int k,int arr[]);
main()
{
    int n,k,arr[10],i;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    for(i=0;i<n;++i)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the subbarray or k\n");
    scanf("%d",&k);
    printMax(n,k,arr);
}
void printMax(int size,int k,int arr[])
{
    int i,j,max;
    for(i=0;i<=size-k;++i)
    {
     max=arr[i];
     for(j=1;j<k;++j)
     {
         if(arr[i+j]>max)
         {
            max=arr[i+j];
         }
     }
     printf("THE MAX NUMBER IN SUBAARY %d is %d\n",i,max);
    }
}