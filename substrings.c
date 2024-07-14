// C program for the above approach
#include <stdio.h>
void printSubstrings(char str[])
{
	
	// outermost for loop
	// this is for the selection
	// of starting point
	for (int start = 0; str[start] != '\0'; start++) {
		
		// 2nd for loop is for selection
		// of ending point
		for (int end = start; str[end] != '\0'; end++) {
			
			// 3rd loop is for printing from
			// starting point to ending point
			for (int i = start; i <= end; i++) {
				printf("%c", str[i]);
			}
		
			// changing the line after printing
			// from starting point to ending point
			printf("\n");
		}
	}
}

// Driver Code
int main()
{

	// code
	char str[] = { 'a', 'b', 'c', 'd', '\0' };
	// calling the method to print the substring
	printSubstrings(str);
	return 0;
}
