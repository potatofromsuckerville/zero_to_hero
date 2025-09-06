#include <stdio.h>
#include <string.h>

int get_input(char *buffer, size_t buffer_size) {
    // Check for null pointer
    if (buffer == NULL || buffer_size == 0) {
        return 2; // Error: invalid parameters
    }
    
    // Attempt to read input
    if (fgets(buffer, buffer_size, stdin) == NULL) {
        // Handle error or end-of-file (Ctrl+D/Ctrl+Z)
        buffer[0] = '\0';
        return 2;
    }
    
    // Check if the input was complete by looking for a newline
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        // Input was complete: remove the newline
        buffer[len - 1] = '\0';
        return 0;
    } else {
        // Input was truncated: clear the leftover characters from stdin
        int c, c2;
        c = getchar();
        if (c == '\n') {
			return 0;
			}
        while ((c2 = getchar()) != '\n' && c2 != EOF) {
            // Discard characters until newline or EOF
        }
        return 1; // Signal that input was truncated
    }
}

int main() {
    // REGULAR fgets() SYNTAX (Now Safe):
    char sentence[6];
    printf("==== ROBUST fgets() SYNTAX ==== \n");
    printf("Enter a sentence (max %zu chars): \n", sizeof(sentence) - 1);
    
    int result = get_input(sentence, sizeof(sentence));
    
    if (result == 2) {
        printf("Program terminated or error occurred.\n");
        return 1;
    } else if (result == 0) {
        printf("Full input received: '%s'\n", sentence);
    } else {
        printf("Input truncated, but safe: '%s'\n", sentence);
    }
    
    // fgets() SYNTAX WITH ARRAYS (Now Safe):
    char name[2][17];
    printf("==== ROBUST fgets() WITH ARRAYS ====\n");
    
    printf("Enter name (max %zu chars): \n", sizeof(name[0]) - 1);
    int full_input1 = get_input(name[0], sizeof(name[0]));
    
    if (full_input1 == 2) {
        printf("Error reading first name.\n");
        return 1;
    }
    
    printf("Enter another name (max %zu chars): \n", sizeof(name[1]) - 1);
    int full_input2 = get_input(name[1], sizeof(name[1]));
    
    if (full_input2 == 2) {
        printf("Error reading second name.\n");
        return 1;
    }
    
    printf("You entered '%s' and '%s'!\n", name[0], name[1]);
    
    if (full_input1 == 1) printf("Warning: First name was truncated.\n");
    if (full_input2 == 1) printf("Warning: Second name was truncated.\n");
    
    return 0;
}
