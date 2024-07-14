#include<stdio.h>
main()
{
    int arr[50],n,i,j;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    int newarr[n],count=0;
    for(i=0;i<n;++i)
     scanf("%d",&arr[i]);
    for(i=0;i<n;++i){
     int unique=1;
      for(j=0;j<count;++j)
      {
        if(arr[i]==newarr[j]){
           unique=0;
           break;
        }
      }
      if(unique)
      {
        newarr[count]=arr[i];
        ++count;
      }
    }
    printf("after removing duplicate elements from array\n");
    for(i=0;i<count;++i)
     printf("%d\n",newarr[i]);

}