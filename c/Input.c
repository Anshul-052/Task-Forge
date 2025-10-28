// Program 1: Convert letters to ASCII values
#include <stdio.h>
#include <ctype.h>

void letters_to_ascii() {
    char sentence[1000];
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    
    for (int i = 0; sentence[i] != '\0'; i++) {
        if (isalpha(sentence[i]) || isspace(sentence[i])) {
            if (!isspace(sentence[i]))
                printf("%d ", sentence[i]);
            else
                printf("  "); // Double space to preserve word boundaries
        }
    }
    printf("\n");
}

int main() {
    letters_to_ascii();
    return 0;
}