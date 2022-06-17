#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

void check_if_balanced(int circle_brackets, int squiggly_brackets, int square_brackets)
{
    int values[3] = { circle_brackets, squiggly_brackets, square_brackets };
    bool is_balanced = true;

    for (int i = 0; i < 3; i++) {
        if (values[i] != 0) {
            is_balanced = false;
        }
    }

    // TODO: Make this look better
    if(is_balanced == false) {
        printf("The parenthesis are not balanced \n");
        return;
    }

    printf("The parenthesis are balanced \n");
}

int main(int argc, char **argv)
{
    (void) argc;

    assert(*argv != NULL);
    char *program = *argv++;
    
    if (*argv  == NULL) {
        fprintf(stderr, "ERROR: Usage %s is invalid \n", program);
        fprintf(stderr, "ERROR: Must have one argument \n");
        exit(1);
    }
        
    char *input = *argv++;

    size_t length = strlen(input);

    if (length < 2) {
        fprintf(stderr, "ERROR: %ld is invalid input must be greater than 2 \n", length);
        exit(1);
    }

    int circle_brackets = 0;
    int squiggly_brackets = 0;
    int square_brackets = 0;
    
    for (size_t i = 0; i <= length; i++) {
        switch (input[i])
        {
            case '(': circle_brackets++;
            continue;
            
            case ')': circle_brackets--;
            continue;
            
            case '{': squiggly_brackets++;
            continue;
            
            case '}': squiggly_brackets--;
            continue;
            
            case '[': square_brackets++;
            continue;
            
            case ']': square_brackets--;
            continue;

            default:
            continue;

        }
    }

    check_if_balanced(circle_brackets, squiggly_brackets, square_brackets);
    
    return 0;
}
