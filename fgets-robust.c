#include <stdio.h>

int main() {
	
	char sentence[7] = {'\0'};
	printf("==== INPUT VALIDATION (PERSONAL BUILD V1) ==== \n");
	printf("Enter %zu characters max: \n", sizeof(sentence) - 1);
	fgets(sentence, sizeof(sentence), stdin);
	
	for (int i = 0; i < sizeof(sentence); i++) {
		if (sentence[i] == '\n') {
			sentence[i] = '\0';
			printf("Valid input(less than max). You entered: %s", sentence);
			break;
			}
		else if (sentence[i] == '\0') {
			if (getchar() == '\n') {
				printf("Valid input(exactly max). You entered: %s", sentence);
				}
			else {
				while (getchar() != '\n' && getchar() != EOF) {
					}
				printf("Invalid input(longer than max). Truncation occured. You entered: %s", sentence);
				}	
			}
		}
		return 0;
	}
