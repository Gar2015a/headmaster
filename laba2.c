#include       <sys/io.h>
#include        <stdio.h>
#include        <fcntl.h>
#include        <sys/stat.h>
#include        <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/mman.h>


int main(int argc, char const *argv[]) {
  int fd;
  int ret;
  char ch;
  int i=1;
  int n=1;
  int sum=0;
  int strCount=0; int strlen=0;
  struct stat fdstat;
  fd=open("text.txt", O_RDONLY);
  fstat(fd, &fdstat);
  char *marr=mmap(NULL, fdstat.st_size, PROT_READ, MAP_SHARED, fd, 0);
  close(fd);
  for(int j=0; j<=fdstat.st_size; j++){
      if(marr[j]=='\n'){
        strCount++;
      }
  }
  int arr[strCount];
  int brr[strCount];
  for(int j=0; j<=fdstat.st_size; j++) {
      strlen++;
      if(marr[j]=='\n'){
        arr[i]=strlen;
        i++;
        strlen=0;
      }
  }
  for(int j = 1; j<=strCount; j++){
    sum+=arr[j];
    brr[j+1]=sum;
    brr[1]=0;
    //printf("%d - %d\n", brr[j], arr[j]);
  }
  printf("Всего в файле %d строк\n", strCount);
  printf("Введите номер строки от 1 до %d\n", strCount);
  printf("Для выхода из программы введите 0\n" );
  while (n!=0) {
  scanf("%d", &n);
  ret=brr[n];
  //printf("%d\n", ret);
    for(int j = 1; j<arr[n]; j++){
      ch=marr[j+ret-1];
      printf("%c", ch);
    }
    printf("\n");
  }
  printf("Программа завершила работу\n");
  return 0;
}
