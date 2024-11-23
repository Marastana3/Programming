#include <stdio.h>
#include <ctype.h>

void count_alnum_fields() {
    int c;
    int is_alnum_field = 1;  // Flag to check if the current field is alphanumeric
    int alnum_count = 0;     // Number of alphanumeric fields in the current line
    
    while ((c = getchar()) != EOF) {
        if (c == ',') {
            // Field separator
            if (is_alnum_field) {
                alnum_count++;
            }
            is_alnum_field = 1;  // Reset for the next field
        } else if (c == '\n') {
            // End of line
            if (is_alnum_field) {
                alnum_count++;
            }
            // Print the alnum_count using putchar()
            if (alnum_count > 9) {
                putchar('0' + alnum_count / 10); // Tens digit
            }
            putchar('0' + alnum_count % 10); // Units digit
            putchar('\n');
            // Reset for the next line
            alnum_count = 0;
            is_alnum_field = 1;
        } else {
            // Check if character is alphanumeric
            if (!isalnum(c)) {
                is_alnum_field = 0;
            }
        }
    }
    // Handle last line if it doesn't end with '\n'
    if (is_alnum_field && alnum_count > 0) {
        alnum_count++;
        if (alnum_count > 9) {
            putchar('0' + alnum_count / 10); // Tens digit
        }
        putchar('0' + alnum_count % 10); // Units digit
        putchar('\n');
    }
}

int main() {
    count_alnum_fields();
    return 0;
}
