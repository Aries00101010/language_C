#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int MAX_NUMBER = 100, MIN_NUMBER = 1;

/**
the int value 0 equal false and the value 1 equal true
**/

// Get random number between 1 and 100
int random_number()
{
    time_t t;
    srand((unsigned) time(&t));
    return rand() % MAX_NUMBER + MIN_NUMBER;
}

// Get user's input
int get_user_input()
{
    int input = 0;
    if (scanf("%d", &input) >= MIN_NUMBER && input <= MAX_NUMBER)
    {
        return input;
    }
    else
    {
        return 0;
    }
}

// Check if the user's input is equal to random number
// Print if the random number is plus or minus the user's input
// Return 0 or 1 for for the loop in main function
int advice(int random_number, int input_user)
{
    if (random_number > input_user)
    {
        printf("Plus\n");
        return 1;
    }
    else if (random_number < input_user)
    {
        printf("Minus\n");
        return 1;
    } else
    {
        printf("Find !\n");
        return 0;
    }
}

int main()
{
    int r_number = random_number();
    int input_user = 0;
    int counter = 0;

    // Get input again while the random number isn't equal
    do
    {
        counter++;
        input_user = get_user_input();
    }
    while(advice(r_number, input_user));

    printf("You try to find the number : %d", counter);

    return 0;
}
