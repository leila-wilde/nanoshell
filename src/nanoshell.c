#include <stdio.h> // input output fuctions
#include <stdlib.h> // memory management
#include <unistd.h> // process control 
#include <string.h> // string funtions

#define MAX_USER_INPUT 1024 // constant to restrict user input length 

int main() {
    char input[MAX_USER_INPUT];
 
    while(1) {
        printf(">>"); // prompt user 
        fgets(input, MAX_USER_INPUT, stdin); // get user input
        printf("Vous avez entre: %s", input);
    }
    return 0;
}