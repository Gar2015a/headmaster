#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/fcntl.h>
#include <semaphore.h>
void log(FILE *f){
    fprintf(f, "Process %d\n", getpid());
}
void vito(FILE *f){
    sem_t *sem1;
    sem_t *sem2;
    char *name_sem1 = "/10";
    char *name_sem2 = "/20";
    sem1 = sem_open(name_sem1,  O_CREAT | O_EXCL, 0777, 1);
    sem2 = sem_open(name_sem2,  O_CREAT | O_EXCL, 0777, 0);
    if(fork()) {
        for(int i = 0; i<=3; i++){
            sem_wait(sem1);
            log(f);
            sem_post(sem2);
        }
    } else {
        for(int i = 0; i<=3; i++){
            sem_wait(sem2);
            log(f);
            sem_post(sem1);
        }
    } 
}
void main(int argc, char* argv[]) {
    FILE *f = fopen("log.txt", "a");
    vito(f);
    fclose(f);
    }