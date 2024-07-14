#include<stdio.h>
#include<stdlib.h>
void missing(int n,int *a);
main()
{
    int *a,n,i;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    a=(int *)malloc(sizeof(int)*n);
    printf("Enter teh elements\n");
    for(i=0;i<n;++i)
      scanf("%d",a+i);
    missing(n,a);
}
void missing(int n,int *a)
{
    int i,small,j,temp;
    for(i=0;i<n;++i)
     for(j=0;j<n-1;++j)
     {
        if(*(a+j)>*(a+j+1))
        {
            temp=*(a+j+1);
            *(a+j+1)=*(a+j);
            *(a+j)=temp;
        }
     }
    small=*(a+0);
    i=0;
     while(i<n)
    {
       if(small!=*(a+i))
       {
          printf("NOT FOUND %d\n",small);
          break;
       }
      ++small;
      ++i;
     }
}