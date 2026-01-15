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
    pid_t pid = -1;

    // check if no command was entered 
    if (arguments[0] == NULL) {
        return 1;
    }

    // check for exit command 
    if (strcasecmp(arguments[0], "exit") == 0) {
        return 0; 
    }
    // check for built-in commands
    // todo

    // find the command using the path
    char *path = find_in_path(arguments[0]);
    if (path == NULL) {
        printf("Commande non trouvé: %s\n", arguments[0]);
        return 1;
    }
    
    pid = fork();
    if (pid == 0) {
        // child process
        char *env[] = {NULL}; // null-terminated list of environment variables
        execve(path, arguments, env);
        exit(-1);
    }

    // parent process (wait for child process to finish)
    waitpid(pid, NULL, 0);

    free(path);

    return 1;
}