// nanoshell.c

#include "../include/nanoshell.h"

int main() {
    char input[MAX_USER_INPUT];
    char *arguments[MAX_ARGUMENTS] = {NULL}; // initialise all pointers to NULL
 
    while(1) {
        printf("?>"); // prompt user
        
        // check if input is read properly
        if (fgets(input, MAX_USER_INPUT, stdin) == NULL) {
            break; // exit on EOF or error
        } 
        
        // parse input into arguments
        split_arguments(input, arguments);

        // execute the command 
        int result = execute_external(arguments);
    }
    return 0;
}

// funtion to parse input into arguments
void split_arguments(char *input, char *arguments[]) {
    // remove newline character
    input[strcspn(input, "\n")] = 0;

    // reset arguments array
    for (int i = 0; i < MAX_USER_INPUT; i++) {
        arguments[i] = NULL;
    }
    // tokenize the input
    return; // todo

}

// function to execute commands 
int execute_external(char *arguments[]) {
    // check if no command was entered 
    if (arguments[0] == NULL) {
        return 1;
    }

    // check for exit command 
    if (strcmp(arguments[0], "exit") == 0) {
        return 0; 
    }

    // just print the command for now
    printf("Vous avez entre: %s", arguments[0]);

    return 1;
}