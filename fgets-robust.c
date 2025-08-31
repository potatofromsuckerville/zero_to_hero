#include <stdio.h>
#include <string.h>
#include <stdbool.h> // For bool type

/**
 * @brief Safely reads a line of input into a buffer.
 * 
 * @param buffer The buffer to store the input.
 * @param buffer_size The size of the buffer.
 * @return true if the entire line was read successfully.
 * @return false if the input was truncated.
 */
bool get_input(char *buffer, size_t buffer_size) {
    if (fgets(buffer, buffer_size, stdin) == NULL) {
        // Handle error or end-of-file (Ctrl+D/Ctrl+Z)
        buffer[0] = '\0';
        return false;
    }

    // Check if the input was complete by looking for a newline
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        // Input was complete: remove the newline
        buffer[len - 1] = '\0';
        return true;
    } else {
        // Input was truncated: clear the leftover characters from stdin
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {
            // Discard characters until newline or EOF
        }
        return false; // Signal that input was truncated
    }
}

int main() {
    // REGULAR fgets() SYNTAX (Now Safe):
    char sentence[20];
    printf("===#include <stdio.h>
#include <string.h>
//~ #include <stdbool.h> // For bool type
/**
 * @brief Safely reads a line of input into a buffer.
 * 
 * @param buffer The buffer to store the input.
 * @param buffer_size The size of the buffer.
 * @return true if the entire line was read successfully.
 * @return false if the input was truncated.
 */
int get_input(char buffer) {  // , size_t buffer_size (second get_input parameter in original source code)
	
	char input = buffer;
    if (input == NULL) {
        // Handle error or end-of-file (Ctrl+D/Ctrl+Z)
        input[0] = '\0';
        return 2;
    }
    
    else {
		// Check if the input was complete by looking for a newline
		size_t len = strlen(input);
		if (len > 0 && input[len - 1] == '\n') {
			// Input was complete: remove the newline
			input[len - 1] = '\0';
			return 0;
		} else {
			// Input was truncated: clear the leftover characters from stdin
			int c;
			while ((c = getchar()) != '\n' && c != EOF) {
				// Discard characters until newline or EOF
					}
			return 1; // Signal that input was truncated
				}		
		}
	}
int main() {
    // REGULAR fgets() SYNTAX (Now Safe):
    char sentence[9];
    printf("==== ROBUST fgets() SYNTAX ==== \n");
    printf("Enter a sentence (max %zu chars): \n", sizeof(sentence) - 1);
    
    fgets(sentence, sizeof(sentence), stdin);
    if (get_input(sentence) == 2) { // , sizeof(sentence)
		printf("Program terminated. \n");
		}
		
	else {
		
		if (get_input(sentence)) { // , sizeof(sentence)
			printf("Full input received: '%s' \n", sentence);
		} else {
			printf("Input truncated, but safe: '%s' \n", sentence);
		}
		// fgets() SYNTAX WITH ARRAYS (Now Safe):
		char name[2][17];
		printf("==== ROBUST fgets() WITH ARRAYS ==== \n");
		
		printf("Enter name (max %zu chars): \n", sizeof(name[0]) - 1);
		int full_input1 = get_input(name[0]); // , sizeof(name[0])
		
		printf("Enter another name (max %zu chars): \n", sizeof(name[1]) - 1);
		int full_input2 = get_input(name[1]); // , sizeof(name[1])
		
		printf("You entered '%s' and '%s'! \n", name[0], name[1]);
		
		if (!full_input1) printf("Warning: First name was truncated.\n");
		if (!full_input2) printf("Warning: Second name was truncated.\n");
		
		
		}
    return 0;
}

= ROBUST fgets() SYNTAX ==== \n");
    printf("Enter a sentence (max %zu chars): \n", sizeof(sentence) - 1);
    
    if (get_input(sentence, sizeof(sentence))) {
        printf("Full input received: '%s' \n", sentence);
    } else {
        printf("Input truncated, but safe: '%s' \n", sentence);
    }

    // fgets() SYNTAX WITH ARRAYS (Now Safe):
    char name[2][50];
    printf("==== ROBUST fgets() WITH ARRAYS ==== \n");
    
    printf("Enter name (max %zu chars): \n", sizeof(name[0]) - 1);
    bool full_input1 = get_input(name[0], sizeof(name[0]));
    
    printf("Enter another name (max %zu chars): \n", sizeof(name[1]) - 1);
    bool full_input2 = get_input(name[1], sizeof(name[1]));
    
    printf("You entered '%s' and '%s'! \n", name[0], name[1]);
    
    if (!full_input1) printf("Warning: First name was truncated.\n");
    if (!full_input2) printf("Warning: Second name was truncated.\n");

    return 0;
}
