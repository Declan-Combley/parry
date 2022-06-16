#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void check_if_balanced(int circle_brackets, int squiggly_brackets, int square_brackets)
{
    int values[3] = { circle_brackets, squiggly_brackets, square_brackets };
    int is_balanced = 1;

    for (int i = 0; i < 3; i++) {
        if (values[i] != 0) {
            is_balanced = 0;
        }
    }

    // TODO: Make this look better
    printf("Is Balanced: %d \n", is_balanced);
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

    int size = input[0] / sizeof(input);

    if (size <= 2) {
        fprintf(stderr, "ERROR: %d is invalid input must be greater than 2 \n", size);
        exit(1);
    }

    int circle_brackets = 0;
    int squiggly_brackets = 0;
    int square_brackets = 0;
    
    for (int i = 0; i <= size; i++) {
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

    //printf("() : %d \n", circle_brackets);
    //printf("{} : %d \n", squiggly_brackets);
    //printf("[] : %d \n", square_brackets);

    check_if_balanced(circle_brackets, squiggly_brackets, square_brackets);
    
    return 0;
}
