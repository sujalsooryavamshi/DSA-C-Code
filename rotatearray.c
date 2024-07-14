#include<stdio.h>
main()
{
    int a[10],b,i,j,n,key;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    for(i=0;i<n;++i)
        scanf("%d",&a[i]);
    printf("Enter the key to rotate\n");
    scanf("%d",&key);
    for(i=0;i<key;++i)
    {
        b=a[n-1];
        for(j=n-1;j>0;--j)
         {
             a[j]=a[j-1];
         }
         a[0]=b;
    }
    printf("After rotation the array is as follows\n");
    for(i=0;i<n;++i)
      printf("%d\t",a[i]);
    
}