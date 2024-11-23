#include <stdio.h>
#include <ctype.h>

void count_alnum_fields() {
    int c;
    int is_alnum_field = 1;  // Flag to check if the current field is alphanumeric
    int alnum_count = 0;     // Number of alphanumeric fields in the current line

    freopen("file.txt", "r", stdin);
    
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
            // Print the alnum_count 
            printf("%d\n", alnum_count);
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
        printf("%d\n", alnum_count);
    }
}

int main(){

    count_alnum_fields();

    return 0;
}