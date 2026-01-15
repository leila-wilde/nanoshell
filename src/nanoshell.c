// nanoshell.c

#include "../include/nanoshell.h"

int main() {
    char input[MAX_USER_INPUT];
    char *arguments[MAX_ARGUMENTS] = {NULL}; // initialise all pointers to NULL
 
    while(1) {
        print_prompt();
        
        // check if input is read properly
        if (fgets(input, MAX_USER_INPUT, stdin) == NULL) {
            break; // exit on EOF or error
        } 
        
        // parse input into arguments
        split_arguments(input, arguments);

        // execute the command 
        int command = execute_external(arguments);
        if (command == 0) {
            break; // exit shell if command was 'exit' 
        }
    }
    
    return 0;
}

// function to prompt user input
void print_prompt(void){
    printf("?> ");
    fflush(stdout); //force output to appear immediately
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
    if (strcasecmp(arguments[0], "exit") == 0) {
        return 0; 
    }

    // just print the command for now
    printf("Vous avez entre: %s", arguments[0]);

    return 1;
}