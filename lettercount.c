//Import the modules needed
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// The count function, given a string and a char, will count how many times that 
// character appears in the string.
int count(char string[], char x) {
    // Declaring some variables
    int i; 
    int total = 0;

    // This for loop will run an amount of times equivalent to the length of the string
    // (Checking every character of the string)
    for (i = 0; i < strlen(string); i++) {

        // If the current character is not a letter, it'll skip it
        if (isalpha(string[i]) == 0) continue;

        // Otherwise, it checks whether the letter matches the character inputted, ignoring
        // whether it's upper or lower case. If so, add one to the total
        else if (toupper(string[i]) == x) total += 1;
    }

    // It returns the total number of times the letter appears
    return total;
}

int main(void) {

    // Declare and initalize several variables, including the buffer with 1023 characters permitted
    char buffer[1023];
    int i = 0;
    char input;
    char check;
    int x;
    float percent;
    float most = 0;
    float least = 100;
    char mostC;
    char leastC;

    // Prompt user to enter the text and then scan the text 
    // character-by-character using a while loop
    printf("Enter text for analysis: ");
    while ((input = getchar()) != '\n') buffer[i++] = input;
    buffer[i] = '\0';

    // These are mostly for aesthetic purposes, to make the output look nice
    printf("\n\nLetter Analysis Complete!\n\n");
    printf("Letter    Occurrences    Percentage     \n");
    printf("****************************************\n");
    
    // This for loop will cycle through the integers from 65 to 90 inclusive.
    // This is because these numbers correspond to the letters A-Z respectively
    // in ASCII.
    for (x = 65; x <= 90; x++) {

        //Find how much of the string is composed of the current letter
        percent = ((float)count(buffer,x)/(float)strlen(buffer))*100;

        // If this percentage is greater than the previous greatest, make
        // note of the new most occurring letter and its percentage
        if (percent >= most) {
            most = percent;
            mostC = x;
        }

        // If this percentage is less than the previous lowest, make
        // note of the new least occurring letter and its percentage
        if (percent <= least) {
            least = percent;
            leastC = x;
        }

        // Print the letter, # of occurrences, and percentage in that 
        // order.  
        printf("%-10c%-15d%-15.2f\n", x, count(buffer, x), percent);    
    }

    // Print the recorded most and least frequently appearing letter.
    printf("\nThe most frequently occurring character is %c.", mostC);
    printf("\nThe least frequently occurring character is %c.", leastC);

    return 0;

}
