#include <stdio.h>
#include <ctype.h>

/**
 * Title: Bitwise
 *
 * This program will set or clear a single bit in a number entered
 * by the user using the binary representation of the number. The
 * program will accept values from 1 to 1000, it will then ask to
 * set or clear bits between 0 and 31. After completing the operation
 * the program will ask the user if they want to continue or stop.
 **/

//This function display a welcome message to the user.
void welcomeMessage()
{
    printf("---------------------------------------------------------------\n");
    printf("                Welcome to bitwise operation\n");
    printf("   This program set or clear a single bit in a given number.\n");
    printf("---------------------------------------------------------------\n\n");
} //End of welcomeMessage function.

//This function display a closing message to the user.
void closingMessage()
{
    printf("---------------------------------------------------------------\n");
    printf("                Thank you for using this product.\n");
    printf("---------------------------------------------------------------\n\n");
} //End of closingMessage function.

int main()
{
    //Declaring and initializing variables.
    unsigned int input; //user input
    unsigned int output = 0;
    int attemp; //used to collect garbage characters
    int status; // validate the user input.
    int bit = 0;
    char answer = '\0';
    char option = '\0';

    welcomeMessage();
    do
    { //Get initial value from user and validate if its a number.
        do
        {
            printf("\n");
            printf(" Enter any single initial value from 1 to 1000: ");
            status = scanf("%d", &input);
            while (status != 1)
            {
                while ((attemp = getchar()) != EOF && attemp != '\n')
                    ;
                printf(" Invalid input try again\n");
                printf(" Enter any single initial value from 1 to 1000: ");
                status = scanf("%d", &input);
            }
        }
        //Keep looping until a correct digit is enter.
        while (input < 1 || input > 1000);
        getchar();
        do
        { //Get set or clear character from user.
            printf(" Do you want to set enter 's' or clear enter 'c'? ");
            scanf("%c", &option);
            getchar();
        }
        //Keep looping until correct character is enter.
        while ((option != 'S') && (option != 's') && (option != 'c') && (option != 'C'));

        do
        { //Get bit number from user and validate if its a number.
            printf(" Which bit do you want to set/clear enter a number (0-31)? ");
            status = scanf("%d", &bit);
            while (status != 1)
            {
                while ((attemp = getchar()) != EOF && attemp != '\n')
                    ;
                printf(" Invalid input try again\n");
                printf(" Which bit do you want to set/clear enter a number (0-31)? ");
                status = scanf("%d", &bit);
            }
        }
        //Keep looping until correct bit number is enter.
        while (bit < 0 || bit > 31);
        getchar();

        //If statement with bitwise operation used to determine the output.
        if ((option == 'S') || (option == 's'))
        {
            output = input | (0x1 << bit);
        }
        else if ((option == 'c') || (option == 'C'))
        {
            output = input & (~(0x1 << bit));
        }
        printf("\n");
        //Display the result of the bitwise operation.
        printf(" Result value: %d\n\n", output);

        //Get answer from user to end or continue program.
        printf(" Do you want to continue y or n: ");
        scanf("%c", &answer);
        getchar();

        //Keep looping until correct answer is given.
        while ((answer != 'Y') && (answer != 'y') && (answer != 'n') && (answer != 'N'))
        {
            printf(" Do you want to continue y or n: ");
            scanf("%c", &answer);
            getchar();
        } //If answer is no display closing message.
        if (answer == 'n' || answer == 'N')
        {
            closingMessage();
        }
    } //If answer is yes rerun the entire program.
    while (answer == 'y' || answer == 'Y');
} //End of Bitwise program.
