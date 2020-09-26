#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc,char* argv[])
{
  pid_t pid;
  int rv;
  switch(pid=fork()) {
  case -1:
          perror("fork"); /* произошла ошибка */
          exit(1); /*выход из родительского процесса*/
  case 0:       
          printf(" CHILD\n");
          execvp(argv[1], &argv[1]);
          exit(3);
  default:                   
          wait(&rv);
          printf("PARENT: Код возврата потомка:%d\n", WEXITSTATUS(rv));
          printf("PARENT: Выход!\n");   
  }
  return 0;
}
