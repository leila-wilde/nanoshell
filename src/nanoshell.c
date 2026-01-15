// nanoshell.c
#include <stdio.h>
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
        int result = execute_external(arguments);
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
 
    int i=0;
    int a=0;


    while (input[i]!=' \0'){

    while (input[i]==' ' || input[i]=='\t')
        i++;

    if (input[i]=='\0')
        break;

        arguments[a]=malloc (512);
        int k=0;

        while (input[i]!=' ' && input[i]!='\t' && input[i]!='\0'){
            arguments[a][k]=input[i];
            i++;
            k++;
        }
        arguments[a][k]='\0';
        a++;
    }
    arguments[a]= NULL;
    free(arguments[a]);
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