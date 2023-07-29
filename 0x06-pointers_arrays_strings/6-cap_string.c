#include <stdio.h>
#include <ctype.h>

char *cap_string(char *str) {
    int capitalize_next = 1; // Start with capitalizing the first letter
    char *current = str;

    while (*current != '\0') {
        if (capitalize_next && islower(*current)) {
            *current = toupper(*current); // Capitalize the letter
        }

        // Update capitalize_next based on the separators
        if (*current == ' ' || *current == '\t' || *current == '\n' ||
            *current == ',' || *current == ';' || *current == '.' ||
            *current == '!' || *current == '?' || *current == '"' ||
            *current == '(' || *current == ')' || *current == '{' ||
            *current == '}') {
            capitalize_next = 1;
        } else {
            capitalize_next = 0;
        }

        current++;
    }

    return str;
}

int main() {
    char input[] = "hello, world! how are you? this is a test.";
    printf("Before: %s\n", input);
    printf("After: %s\n", cap_string(input));
    return 0;
}

