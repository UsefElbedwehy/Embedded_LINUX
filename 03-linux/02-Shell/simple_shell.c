#include <sched.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_SIZE 1024
#define MAX_ARG_SIZE 100

void parse(char* input,char **args){
    char* Tinput = strtok(input, " ");
    int counter=0;
    while(Tinput!=NULL){
        args[counter++] = Tinput;
        Tinput = strtok(NULL, " ");
    }
    args[counter] = NULL;
}


int main(int argc, char const *argv[])
{
    char Input[MAX_CMD_SIZE];
    char* args[MAX_CMD_SIZE];
    while (1) {
    printf("[Input] Enter the command: ");
    if (fgets(Input, MAX_ARG_SIZE, stdin) == NULL){
        perror("Failed to read input!");
        continue;
    }
    Input[strcspn(Input,"\n")] = '\0';
    
    if (!strcmp(Input, "exit") || !strcmp(Input,"quit") || !strcmp(Input,"q")) {
        break;
    }
    parse(Input,args);
    
    pid_t Child_id = fork();
    if (Child_id < 0) {
        perror("Fork failed!");
        break;
    }else if (Child_id == 0) {
        execvp(args[0], args);
        printf("Execution failed!\n");
        exit(EXIT_FAILURE);
    }else {
        int status=0;
        waitpid(Child_id, &status, 0);
    }
    
    }
    printf("exiting shell...\n");
    return 0;
}
