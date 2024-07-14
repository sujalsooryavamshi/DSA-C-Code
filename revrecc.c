# include <stdio.h>
 void reverse(char *str)
{ int cnt=0;
if (*str)
{   
	reverse(str + 1);
	printf("%c", *str);

}
}

// Driver code
int main()
{
  char a[50];
  printf("Enter the string\n");
  scanf("%s",a);
  reverse(a);
  return 0;
}
