#include <stdio.h>

int countCharacters( char str[], int index) {
    if (str[index] == '\0') {
        // Base case: end of the string, return 0
        return 0;
    } else {
        // Recursive case: increment count and move to the next character
        return 1+countCharacters(str, index + 1);
    }
}

int main() {
    char str[50];
    printf("Enter the string\n");
    scanf("%s",str);
    int characterCount = countCharacters(str, 0);

    printf("Number of characters in the string: %d\n", characterCount);

    return 0;
}
