#include<stdio.h>

main()
{
    int a,b,gcd;
    printf("Enter the two numbers");
    scanf("%d%d",&a,&b);
    gcd=gcdrec(a,b);
    printf("The gcd of the given number is %d\n",gcd);
}
int gcdrec(int a,int b)
{
    if(a%b==0)
      return(b);
    else 
      return(gcdrec(b,a%b));
}