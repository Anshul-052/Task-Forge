// Program 2: Convert ASCII values back to letters
#include <stdio.h>

void ascii_to_letters() {
    int ascii_value;
    printf("Enter ASCII values separated by spaces (double spaces for words): ");
    
    while (scanf("%d", &ascii_value) == 1) {
        printf("%c", ascii_value);
    }
    printf("\n");
}

int main() {
    ascii_to_letters();
    return 0;
}
