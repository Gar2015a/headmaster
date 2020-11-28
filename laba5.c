#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h> 

int main() {
 int data_processed;
 int file_pipes[2];
 char some_data[] = "dASDdsadSDADeqSCZcdweqSADWecxzD";
 pid_t fork_result;
 if (pipe(file_pipes) == 0) 
 {
    fork_result = fork();
    if (fork_result == -1) 
        {
            fprintf(stderr, "Fork failure");
            exit(EXIT_FAILURE);//закрывает программу
        }
   if (fork_result == 0) 
   {
     data_processed = read(file_pipes[0], some_data, strlen(some_data));//чтение 
   for(int counter = 0; counter<data_processed; counter++) 
        {
            printf("%c", some_data[counter]);
        }
   exit(EXIT_SUCCESS);
  }
    else{
            for(int i=0; i<strlen(some_data); i++)
            {
            some_data[i]=toupper(some_data[i]);//Меняет регистры символов
             }
        write(file_pipes[1], some_data, strlen(some_data));//Записываем 
    }
 }
 exit(EXIT_SUCCESS);
}
