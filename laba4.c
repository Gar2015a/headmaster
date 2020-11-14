#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/fcntl.h>
#include <semaphore.h>
void logdog(char *file){
    FILE *f = fopen(file, "a+"); 
    fprintf(f, "Process %d\n", getpid());
    fclouse(f);
    sleep(1);
}
void vito(char *file){
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
    sem_unlink(name_sem1);
    sem_unlink(name_sem2);
}
void main(int argc, char* argv[]) {
    FILE *f = fopen("text.txt", "a+");
    vito(f);
    fclouse(f);
    }
