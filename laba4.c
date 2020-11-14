#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/fcntl.h>
#include <semaphore.h>
void logdog(FILE *f){
    fprintf(f, "Process %d\n", getpid());
}
void vito(FILE *f){
    sem_t *sem1;
    sem_t *sem2;
    char *name_sem1 = "/Hello";
    char *name_sem2 = "/Privet";
    sem1 = sem_open(name_sem1,  O_CREAT | O_EXCL, 0777, 1);
    sem2 = sem_open(name_sem2,  O_CREAT | O_EXCL, 0777, 0);
    if(fork()) {
        for(int i = 0; i<=3; i++){
            sem_wait(sem1);
            logdog(f);
            sem_post(sem2);
        }
    } else {
        for(int i = 0; i<=3; i++){
            sem_wait(sem2);
            logdog(f);
            sem_post(sem1);
        }
    } 
}
void main(int argc, char* argv[]) {
    FILE *f = fopen("text.txt", "w");
    vito(f);
    fclose(f);
    }
