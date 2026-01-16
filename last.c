// nanoshell program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define MAX_ARGS 64

int my_strlen(char *str);
void print_welcome(void);

int main(void) {
    char line[BUFFER_SIZE] = {0};
    char *av[MAX_ARGS] = {NULL};
    char *env[] = {NULL};
    int pid = -1;

    print_welcome();

    while(1) {
        printf("?> ");
        fgets(line, BUFFER_SIZE, stdin);
        
        line[my_strlen(line) - 1] = 0;

        if (strcasecmp(line, "exit") == 0) {
            printf("byyyye...\n");
            exit(0);
        }

        char *arg = strtok(line, " ");
        int i = 0;
        while (arg != NULL && i <= MAX_ARGS) {
            av[i++] = arg;
            arg = strtok(NULL, " ");
        }
        av[i] = NULL;

        char *paths[] = {"/bin/", "/usr/bin/", "/usr/local/bin/", NULL};
        int executable = 0;

        for (int i = 0; paths[i] != NULL; i++) {
            char path[BUFFER_SIZE];
            snprintf(path, sizeof(path), "%s%s", paths[i], av[0]);

            if (access(path, X_OK) == 0) {
                strcpy(av[0], path);
                executable = 1;
                break;
            }
        }

        if(executable) {
            pid = fork();
            if (pid == 0) {
                execve(line, av, env);
                printf("huh?");
                exit(-1);
            }
            waitpid(pid, NULL, 0);
        } else {
            printf("nope, can't find %s\n", av[0]);
        }
    }

    return 0;
}

void print_welcome(void) {
    printf(" ______________________\n");
    printf("< welcome to nanoshell >\n");
    printf(" ----------------------\n");
    printf("        \\   ^__^\n");
    printf("         \\  (oo)\\_______\n");
    printf("            (__)\\       )\\/\\ \n");
    printf("                ||----w |\n");
    printf("                ||     ||\n");
}

int my_strlen(char *str) {
    int i = 0;
    for (i = 0; str[i]; i++) {}
    return i;
}