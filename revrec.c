#include<stdio.h>
#include<math.h>
int revrec(int num,int len);
main()
{
    int num,temp,rev,len=0;
    printf("Enter the number\n");
    scanf("%d",&num);
    temp=num;
    while(temp!=0)
    {
        len++;
        temp/=10;
    }
    rev=revrec(num,len);
    printf("the reversed number is %d",rev);

}
int revrec(int num,int len)
{
    if(len==0)
      return num;
    else
      return((num%10)*pow(10,len-1)+revrec(num/10,len-1));
}